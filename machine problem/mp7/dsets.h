/* Your code here! */
#ifndef DSETS
#define DSETS

#include <vector>
using namespace std;

/**	
 *	The DisjointSet Class is defines DisjointSets object that represent a family of disjoint sets
 *	Each element has an integer index. It is implemented with the optimizations as up-trees stored in a single vector of ints. 
 *	Path compression and union-by-size are used. Each element of the vector represents a node. 
 *	A nonnegative number is the index of the parent of the current node; a negative number in a root node is the negative of the set size.
 */
class DisjointSets{

private:
	/** 
	 *	vector of ints whose index represents node and value represents parent
	 */
	vector<int> arr_;

public:

	/** 
	 *	Creates n unconnected root nodes at the end of the vector.
	 */
	void addelements(int num);

	/** 
	 *	find the represent node of node whose index is num
	 *	perform path compression at the same time
	 */
	int find(int elem);

	/** 
	 *	Union node with index a and b. 
	 *	Implemented by union-by-size are used.
	 *	Find roots of  arguments before combining the trees. 
	 *	If the two sets are the same size, make the tree containing the second argument point to the tree containing the first.
	 */
	void setunion(int a, int b);

	/**
	 *	Return the size of the set what contains node with index elem.
	 */
	int size (int elem);	
};

#endif