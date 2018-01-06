/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
#include <iostream>
#include <cmath>
using namespace std;
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (curDim>=Dim || curDim<0){
        return false;
    }
    if (first[curDim] < second[curDim]){
        return true;
    }else if (first[curDim] > second[curDim]){
        return false;
    }else{
        return (first < second);
    }
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double cur_dist = 0.0;
    double pot_dist = 0.0;
    for (int i=0; i<Dim; i++){
        cur_dist += (target[i]-currentBest[i])*(target[i]-currentBest[i]);
        pot_dist += (target[i]-potential[i])*(target[i]-potential[i]);
    }
    if (pot_dist < cur_dist){
        return true;
    }else if (pot_dist > cur_dist){
        return false; 
    }else{
        return (potential < currentBest);
    }
    
}

/** 
*   partition: based on wikipedia pseudocode:
*   input:
*   the start and end index of a vector, 
*   the index of the pivot element for partition,
*   the dimension specified for k-d tree
*   function:
*   put the pivot element at position it should be
*   put all the elements smaller on left side, regardless of order
*   put all the elements larger on the right side, regardless of order
*   output:
*   the correct index of the position of the selected pivot element
**/
template<int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int dimension)
{
    Point<Dim> pivotValue = this->points[pivotIndex];
    // swap pivotValue to vector end, temporarily
    swap(this->points[pivotIndex], this->points[right]);
    int storeIndex = left;
    for(int i=left; i<right; i++){
        //compare with value of at pivotIndex, keep swapping larger ones to right
        if(smallerDimVal(this->points[i], pivotValue, dimension)){
            swap(this->points[storeIndex], this->points[i]);
            storeIndex += 1;
        }
    }
    // put pivotValue to its actual position
    swap(this->points[right], this->points[storeIndex]);
    return storeIndex;
}

/**
*   quickSelect: based on wikipedia pseudocode:
*   input:
*   the start and end index of a vector, 
*   the dimension specified for k-d tree
*   index of the median position in the vector 
*   function:
*   put the median value in the median position of the vector
*   output:
*   void
**/
template<int Dim>
void KDTree<Dim>::quickSelect(int left, int right, int midIndex, int dimension)
{   
    // use partition to find where the median element in current vector actually belongs to
    if(!(left < right)){
        return;
    }
    int pivotIndex = (left + right)/2;
    pivotIndex = partition(left, right, pivotIndex, dimension);
    // if it's already at median position, we are done
    // else, search for it in left or right parts
    if(midIndex == pivotIndex){
        return;
    }else if(midIndex < pivotIndex){
        quickSelect(left, pivotIndex - 1, midIndex, dimension);
    }else{
        quickSelect(pivotIndex + 1, right, midIndex, dimension);
    }
}

/** 
*   sortKD actually sorts the whole vector representing the KDtree
*   check if there is only one element/no element left
*   put the median value at median position and smaller left and larger right by calling quickSelect
*   recursively repeat above step for smaller left and larger right
**/
template<int Dim>
void KDTree<Dim>::sortKD(int left, int right, int dimension)
{   
    if (left >= right){
        return;
    }
    int mid = (left+right)/2;
    quickSelect(left, right, mid, dimension);
    sortKD(left, mid-1, (dimension+1)%Dim);
    sortKD(mid+1, right, (dimension+1)%Dim);
}

/**
*   copy input vector to points first
*   perform sort algorithm written above to points to make it KD tree
**/
template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    this->points = newPoints;
    int left = 0;
    int right = newPoints.size()-1;
    sortKD(left, right, 0);
}





/** call the helper funtion to implement search through the entire KD tree **/
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    if (points.empty()){
        return NULL;
    }
    return f(query, 0, this->points.size()-1, 0);
}

/**
*   f is the helper funtion for findNearestNeighbor
*   input:
*   target point, bound of search in vector, current dimension
*   function: as described in MP5 webpage, 
*   go all the way down then back trace and check if should go to right branch according to median value
*   output:
*   the point that is closest to the target point
**/
template <int Dim>
Point<Dim> KDTree<Dim>::f(const Point<Dim>& query, int start, int end, int dimension) const
{
    /**
     * @todo Implement this function!
     */
    // base case: touch down
    int mid = (start+end)/2;
    if (start >= end){
        return this->points[mid];
    }

    int nextDim = (dimension+1)%Dim;
    Point<Dim> curBest;
    if (smallerDimVal(this->points[mid],query,dimension)){
        // go right
        curBest = f(query, mid+1, end, nextDim);
    }else{
        // go left
        curBest = f(query, start, mid-1, nextDim);
    }
    // after touch down, check if median is actually nearer
    
    if (shouldReplace(query, curBest, this->points[mid])){
        curBest = this->points[mid];
    }
    // update the radius of current best (square)
    double cur_best_r = 0;
    for (int i=0; i<Dim; i++){
        cur_best_r += (query[i]-curBest[i])*(query[i]-curBest[i]);
    }
    double mid_r = (query[dimension]-points[mid][dimension])*(query[dimension]-points[mid][dimension]);
    // should go right branch
    if(mid_r <= cur_best_r){
        Point<Dim> potBest;
        if (smallerDimVal(this->points[mid],query,dimension)){
            // go left
            potBest = f(query, start, mid-1, nextDim);
        }else{
            // go right
            potBest = f(query, mid+1, end, nextDim);
        }
        if (shouldReplace(query, curBest, potBest)){
            curBest = potBest;
        }
    }
    
    return curBest;
}





