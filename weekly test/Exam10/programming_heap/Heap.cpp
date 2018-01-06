#include "Heap.h"
#include <iostream>
using namespace std;
//true if a > b
void Heap::printH(){
  for (size_t i= 1; i<items_.size(); i++){
    cout << items_[i] << "\t";
  }
  cout << endl;
}
bool Heap::higherPriority(int a, int b){
  if (items_.at(a) > items_.at(b)){
      return true;
  }else{
      return false;
  }
}

void Heap::heapifyUp(int idx){
  if (idx == 1){
    return;
  }
  int parent_idx = parentIdx(idx);
  if (higherPriority(idx, parent_idx)){
    swap(items_[idx], items_[parent_idx]);
    heapifyUp(parent_idx);
  }
}

void Heap::heapifyDown(int idx){
  if (hasChild(idx)){
  int child_idx = maxPriorityChild(idx);
  if (higherPriority(child_idx, idx)){
    swap(items_[idx], items_[child_idx]);
    heapifyDown(child_idx);
  }
}
}




/**
 * Inserts an integer element into the heap.
 *
 * @param item The integer to be inserted.
 */
void Heap::insert(const int &item)
{
  items_.push_back(item);
  heapifyUp(items_.size()-1);
  // cout << "successfuly insert" << item << endl;
  // printH();
}

/**
 * Removes the maximum item from the heap.
 *
 * @return the maximum item in the heap.
 */
int Heap::remove()
{
  // if (empty()){
  //   return -1;
  // }

  int first = items_[1];
  // cout << "now first item is " << first << endl;

  swap(items_[1],items_[items_.size()-1]);
  items_.pop_back();
      // printH();
      // cout << items_[1] << endl;
  heapifyDown(1);

  return first;
}

Heap::Heap()
{
    items_.resize(1);
    // items_.push_back(999);
}

int Heap::rootIdx() const
{
    return 1;
}

int Heap::maxPriorityChild(int currIdx) const
{
    if (rightChildIdx(currIdx) >= (int)items_.size())
    {
        return leftChildIdx(currIdx);
    }
    else if (items_.at(rightChildIdx(currIdx)) > items_.at(leftChildIdx(currIdx)))
    {
        return rightChildIdx(currIdx);
    }
    else
    {
        return leftChildIdx(currIdx);
    }
}

int Heap::rightChildIdx(int currIdx) const
{
    return 2 * currIdx + 1;
}

int Heap::leftChildIdx(int currIdx) const
{
    return 2 * currIdx;
}

int Heap::parentIdx(int currIdx) const
{
    return currIdx / 2;
}

bool Heap::hasChild(int currIdx) const
{
    return leftChildIdx(currIdx) < (int) items_.size();
}

bool Heap::empty() const
{
    return items_.size() == 1;
}

void Heap::getItems(std::vector<int> & heap) const
{
    for (const int & i : items_) {
        heap.push_back(i);
    }
}
