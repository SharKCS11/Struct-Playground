#include "btrees.h"
#include <iostream>

using namespace std;

/* BINARY TREE: PRIVATE FUNCTIONS */
void BinaryTree::printInOrder(Node* cur)
{
    if(!cur)
        return;
    printInOrder(cur->left);
    cout << cur->key << " ";
    printInOrder(cur->right);
}

void BinaryTree::printPreOrder(Node* cur)
{
    if(!cur)
        return;
    cout << cur->key << " ";
    printPreOrder(cur->left);
    printPreOrder(cur->right);
}

void BinaryTree::printPostOrder(Node* cur)
{
    if(!cur)
        return;
    printPostOrder(cur->left);
    printPostOrder(cur->right);
    cout << cur->key << " ";
}

void BinaryTree::printLevelOrder()
{
    if(!root)
        return;
    std::deque<Node*> allnodes;
    allnodes.push_back(root);
    while(!allnodes.empty()){
        Node* &cur = allnodes.front();
        if(cur->left) //push left and right if possible
            allnodes.push_back(cur->left);
        if(cur->right)
            allnodes.push_back(cur->right);
        cout << cur->key << " "; //operate
        allnodes.pop_front();
    }
}

void BinaryTree::printPreOrder_itr()
{
    if(!root)
        return;
    Node *cur=root;
    std::deque<Node*> allnodes;
    allnodes.push_back(cur);
    while(!allnodes.empty()){
        cur = allnodes.back();
        allnodes.pop_back(); //remove top of stack
        cout << cur->key << " "; //process current node
        if(cur->right) //push right and left in that order
            allnodes.push_back(cur->right);
        if(cur->left)
            allnodes.push_back(cur->left);
    }
}

void BinaryTree::printPostOrder_itr()
{
    if(!root)
        return;
    std::deque<Node*> allnodes;
    std::deque<Node*> toPrint;
    allnodes.push_back(root);
    while(!allnodes.empty()){
        Node* cur=allnodes.back();
        allnodes.pop_back(); //transfer top of stack to top of other stack
        toPrint.push_front(cur);
        if(cur->left)//push left and right in that order
            allnodes.push_back(cur->left);
        if(cur->right)
            allnodes.push_back(cur->right);
    }
    for(auto N:toPrint){
        cout << N->key << " ";
    }
}

void BinaryTree::printInOrder_itr()
{
    if(!root)
        return;
    std::deque<Node*> allnodes;
    Node* cur = root;
    bool cont_flag;
    do{
        cont_flag=false;
        while(cur){ //find null current node
            if(allnodes.empty() || allnodes.back()!=cur)
                allnodes.push_back(cur);
            cur = cur->left;
        }
        cur = allnodes.back();
        allnodes.pop_back();
        cout << cur->key << " ";
        cur = cur->right;
    }while(!allnodes.empty() || cur);
}

void BinaryTree::reverseRecursive(Node *cur)
{
    if(!cur) //if pointer is null
        return;
    reverseRecursive(cur->right);
    reverseRecursive(cur->left);
    auto temp = cur->right;
    cur->right = cur->left;
    cur->left = temp;
    return;
}

/* BINARY TREE: PUBLIC FUNCTIONS */

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::BinaryTree(initializer_list<int> l)
:BinaryTree()
{
    for(int a : l){
        insert(a);
    }
}

BinaryTree::~BinaryTree()
{
    if(isEmpty())
        return;
    std::deque<Node*> allnodes;
    allnodes.push_back(root);
    while(!allnodes.empty()){
        if(allnodes.front()->left) //push left and right
            allnodes.push_back(allnodes.front()->left);
        if(allnodes.front()->right)
            allnodes.push_back(allnodes.front()->right);
        delete(allnodes.front()); //get rid of front node
        allnodes.pop_front();
    }
}

void BinaryTree::insert(int x) {
    auto ited_new = new Node(x);
    if (this->isEmpty())
    {
        root = ited_new;
        return;
    }
    else
    {
        Node* tracker = root;
        Node* next_in_line = tracker;
        while(true)
        {
            tracker = next_in_line;
            if(x < tracker->key)
            {
                next_in_line = tracker->left;
                if(!next_in_line) //space found
                {
                    next_in_line = ited_new;
                    tracker -> left = next_in_line;
                    return;
                }
            }
            else
            {
                next_in_line = tracker->right;
                if(!next_in_line) //space found
                {
                    next_in_line = ited_new;
                    tracker -> right = next_in_line;
                    return;
                }
            }
        }
    }
}

void BinaryTree::print(Tree_ordering_type ord) {
    if (isEmpty())
        return;
    Node *current = root;
    cout << "[ ";
    switch (ord)
    {
        case PREORDER:
            printPreOrder(current);
            break;
        case INORDER:
            printInOrder(current);
            break;
        case POSTORDER:
            printPostOrder(current);
            break;
        case LEVEL_ORDER:
            printLevelOrder();
            break;
        case PREORDER_ITER:
            printPreOrder_itr();
            break;
        case POSTORDER_ITER:
            printPostOrder_itr();
            break;
        case INORDER_ITER:
            printInOrder_itr();
            break;
        default:
            cout << "gtfo" <<std::endl; exit(1);
    }
    cout << "]" << std::endl;
}

void BinaryTree::reverse()
{
    reverseRecursive(root);
}

bool BinaryTree::isEmpty() { return !root;}


