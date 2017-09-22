//
// Created by Sharang on 9/3/2017.
//

#ifndef BTREES_BTREES_H
    #define BTREES_BTREES_H
#endif //BTREES_BTREES_H

#include <deque>
#include <initializer_list>

typedef struct Node{
    int key;
    Node* left;
    Node* right;
    Node(){key=0; left=nullptr; right=nullptr;}
    Node(int x)
        :Node() {key=x;}
}Node;

typedef enum{
    PREORDER, POSTORDER, INORDER,
    LEVEL_ORDER, PREORDER_ITER, POSTORDER_ITER, INORDER_ITER
}Tree_ordering_type;

class BinaryTree
{
private:
    Node* root;

    void printInOrder(Node* cur);
    void printPreOrder(Node* cur);
    void printPostOrder(Node* cur);
    void printLevelOrder();
    void printPreOrder_itr();
    void printPostOrder_itr();
    void printInOrder_itr();
    void reverseRecursive(Node *cur);

public:
    //ctors and dctors
    BinaryTree();
    BinaryTree(std::initializer_list<int> l);
    ~BinaryTree();

    //main functions
    void insert(int x);
    void print(Tree_ordering_type ord);
    void reverse();
    bool isEmpty();



};