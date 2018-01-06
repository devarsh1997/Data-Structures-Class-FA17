#define _BINARYTREE_CPP
#include "binarytree.h"
#include <iostream>
#include <cstdlib>

using namespace std;


template <typename T>
int BinaryTree<T>::countOccurrences(Node*& node, const T& elem) {
  int out;
  if (node == NULL){
    return 0;
  }
  if (node->left == NULL && node->right == NULL){
    if (node->elem == elem){
      return 1;
    }else{
      return 0;
    }
  }
  if (node->left == NULL){
    if (node->elem == elem){
      return 1+countOccurrences(node->right, elem);
    }else{
      return countOccurrences(node->right, elem);
    }
  }
  if (node->right == NULL){
    if (node->elem == elem){
      return 1+countOccurrences(node->left, elem);
    }else{
      return countOccurrences(node->left, elem);
    }
  }
  if (node->elem == elem){
    out = 1+countOccurrences(node->left, elem)+countOccurrences(node->right, elem);
  }else{
    out = countOccurrences(node->left, elem)+countOccurrences(node->right, elem);
  }
  return out;
}


template <typename T>
int BinaryTree<T>::countOccurrences(const T& elem) {
  return countOccurrences(root, elem);
}




/**
 * Constructor to create an empty tree.
 */
template <typename T>
BinaryTree<T>::BinaryTree() : root(NULL) {
  /* nothing */
}

/**
 * Inserts into the BinaryTree, using BST insert algorithm.
 * @param elem The element to insert
 */
template <typename T>
void BinaryTree<T>::insert(const T& elem) {
  insert(root, elem);
}

template <typename T>
void BinaryTree<T>::insert(Node*& node, const T& elem)
{
    // If we're at a NULL pointer, we can put our element here
    if (node == NULL)
        node = new Node(elem);

    // Go left or right
    else if (elem < node->elem)
        insert(node->left, elem);
    else
        insert(node->right, elem);
}
