#include <iostream>
using namespace std;
/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List() {
  /// @todo Graded in MP3.1
    this->clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  /// @todo Graded in MP3.1
    while (head_ != NULL){
        ListNode* temp = head_;
        head_ = head_->next;
        delete temp;
    }
    this->length_ = 0;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {
  /// @todo Graded in MP3.1
    ListNode* temp = new ListNode(ndata);
    if (head_ != NULL){
        temp->next = head_;
        temp->prev = NULL;
        head_->prev = temp;
        head_ = temp;
    }else{
        temp->next = NULL;
        temp->prev = NULL;
        head_ = temp;
        tail_ = temp;
    }
    this->length_ += 1;
    temp = NULL;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {
  /// @todo Graded in MP3.1
    ListNode* temp = new ListNode(ndata);
    if (tail_ != NULL){
        temp->prev = tail_;
        temp->next = NULL;
        tail_->next = temp;
        tail_ = temp;
    }else{
        temp->next = NULL;
        temp->prev = NULL;
        head_ = temp;
        tail_ = temp;
    }
    this->length_ += 1;
    temp = NULL;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& s, ListNode*& e) {
    if(s==e || s==NULL || e==NULL){return;}
    ListNode* t1 = s;
    ListNode* t2 = s->prev;
    ListNode* t3 = e->next;
    while(s != e){
        ListNode* t5 = s->prev;     
        s->prev = s->next;
        s->next = t5;
        s = s->prev;
    }
    ListNode* t4 = s->prev;     
    s->prev = t2;
    s->next = t4;
    e = t1;
    e->next = t3;
    
    if(t2 == NULL){
        head_ = s;
    }else{
        t2->next = s;
    }

    if(t3 == NULL){
        tail_ = e;
    }else{
        t3->prev = e;
    }
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
    int size = this->size();
    if (n>size){
        this->reverse();
        return;
    }
    int loop = size/n;
    ListNode* s = head_;
    ListNode* e = head_;
    for (int i=0; i<loop; i++){
        for (int j=0; j<(n-1); j++){
            e = e->next;
        }
        reverse(s,e);
        s = e->next;
        e = e->next;
    }
    e = tail_;
    reverse(s,e);
  /// @todo Graded in MP3.1
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {

    ListNode* yi = head_->next;
    ListNode* zuihou = tail_;
    ListNode* qian;
    ListNode* hou;

    while (yi!=tail_){
        qian = yi->prev;
        hou = yi->next;
        tail_ = yi;
        yi->prev = zuihou;
        zuihou->next = yi;
        qian->next = hou;
        hou->prev = qian;
        zuihou = yi;
        tail_->next = NULL;
        yi = hou->next;
    }
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_->next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {
    /// @todo Graded in MP3.2
    if (start == NULL){
        return NULL;
    }
    ListNode* new_head = start;
    for (int ct=0; ct<splitPoint-1; ct++){
        new_head = new_head->next;
    }
    ListNode* output = new_head->next;
    output->prev = NULL;
    new_head->next->prev = NULL;
    new_head->next = NULL;
    return output;
}




/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) { 
  /// @todo Graded in MP3.2
    //base
    if (first == NULL && second == NULL)
        return NULL;
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    ListNode* new_list;
    ListNode* n1 = first;
    ListNode* n2 = second;
    if ( n1->data < n2->data ) {
        new_list = n1;
        n1 = n1->next;
    }else {
        new_list = n2;
        n2 = n2->next;
    }   
    while ( n1 != NULL || n2 != NULL ) {
        if ( n1 == NULL || ( n2 != NULL && (n2->data<n1->data) )) {
            new_list->next = n2;
            new_list->next->prev = new_list;
            //move to next pair
            new_list = new_list->next;
            n2 = n2->next;
        }else{
            new_list->next = n1;
            new_list->next->prev = new_list;
            new_list = new_list->next;
            n1 = n1->next;
        }
    }
    if ( first->data < second->data)
        return first;
    else
        return second;

// // base case
//     if (first == NULL && second == NULL)
//         return NULL;
//     if (first == NULL)
//         return second;
//     if (second == NULL)
//         return first;
// // recursion case
//     // ListNode* add;
//     // pick smaller one
//     if (first->data < second->data){
//         // add = first;
//         if (first->next == NULL){
//             first->next = second;
//             second->prev = first;
//             return first;
//         }
//         first->next->prev = NULL;
//         // first = first->next;
//         first->next = merge(first->next, second);
//         first->next->prev = first;
//         return first;        
//     }else{
//         // add = second;
//         if (second->next == NULL){
//             second->next = first;
//             first->prev = second;
//             return second;
//         }
//         second->next->prev = NULL;
//         // second = second->next;
//         second->next = merge(first, second->next);
//         second->next->prev = second;   
//         return second;
//     }
//     // add->next = merge(first, second);
//     // add->next->prev = add;
//   // return add;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
    /// @todo Graded in MP3.2
    if (start == NULL)
        return NULL;
    if (chainLength == 1)
        return start;
    int m = int(chainLength/2);
    ListNode* left = start;
    ListNode* right = split(start, m);
    return merge(mergesort(left, m),mergesort(right, chainLength-m));
}
