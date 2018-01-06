#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

Node *listUnion(Node *first, Node *second);
// void addNode(Node* list_head, Node* add);
// void printList2(Node *head);
#endif
