/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */
#include <iostream>
using namespace std;
namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s){
    if (s.empty()){
        return T();
    }
    T add = s.top();
    s.pop();
    stack<T> rest;
    rest = s;
    s.push(add);
    return (add + sum(rest));
    // Your code here
                 // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q){
    // stack<T> s;
    queue<T> q2;
    int loopSize = 1;
    int total = q.size();
    bool reverse = false;
    bool done = false;
    int i = 0;
    while(i < total){

        // cout<< "length of q is" << total << endl;
        if ((total-i-1)<loopSize){
            loopSize = total-i;
            done = true;
        }

        cout << "reverse flag "<< reverse << endl;
        

        if (reverse){//do reversely for loopsize
            cout<< "loop size is " << loopSize << endl;
            cout<< "loop start point is " << i << endl;
            T temp[20];
            for (int k=0; k<loopSize; k++){
                T add = q.front();
                q.pop();
                
                
                temp[k] = add;
            }
            for (int k=0; k<loopSize; k++){
                cout << "push reversely: "<<temp[loopSize-k-1] << endl;
                q2.push(temp[loopSize-k-1]);
            }
            
        }else{//do not reverse for loopsize
            cout<< "loop size is " << loopSize << endl;
            cout<< "loop start point is " << i << endl;
            for (int j=0; j<loopSize; j++){
                T add = q.front();
                q.pop();
               
                cout << "push normally: "<<add << endl;
                q2.push(add);
            }
        }
        i += loopSize;
        loopSize += 1;

        reverse = !reverse;
        if (done){
            break;
        }
        cout << "\n" << endl;
        cout << "\n" << endl;
    }
    // optional: queue<T> q2;
    q = q2;
    // Your code here
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q){
    bool r = true;
    if(s.empty()){// base case: when s is empty and start to compare while put things back in s
        return true;
    } 

    //take out first element in s and store in a
    T a = s.top();
    s.pop();

    //recursively do the thing in block above until hit base case
    r = verifySame(s, q);
    //this recursion will be called until hit base case, by the time s is empty and q is unchanged yet

    //moving up
    //at this moment, last obj taken from s should equal to the front of q
    r = (r && (a == q.front()));

    //take obj from exit of q and put it at entrance
    T b = q.front();
    q.push(b);
    q.pop();

    //put a back to s
    s.push(a);

    //everything restored, and every element compared.
    return r;

    }

}

