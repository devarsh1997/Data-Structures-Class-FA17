// your code here
#include "LNode.h"

void LNode::lookAtMeOdd(Node **arr,int n){
  for (int i=1; i<n; i+=2){
    arr[i]->setLookingAt(this);
  }
}
