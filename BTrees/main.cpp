#include <iostream>
#include "btrees.h"

using namespace std;


int main()
{
    cout << "Testing Binary Tree" << std::endl;
    BinaryTree btree{4,2,3,8,6,9};
    btree.print(PREORDER);
    btree.print(POSTORDER);
    btree.print(INORDER);
    btree.print(LEVEL_ORDER);
    btree.print(PREORDER_ITER);
    btree.print(POSTORDER_ITER);
    btree.print(INORDER_ITER);
    cout << "Reversing tree once: " << endl;
    btree.reverse();
    btree.print(INORDER_ITER);
    cout << "Reversing it back: " <<endl;
    btree.reverse();
    btree.print(INORDER_ITER);
    return 0;
}