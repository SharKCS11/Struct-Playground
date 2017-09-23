#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


int main()
{
    printf("Binary heap test.");
    bh_init();
    bh_add(9);
    bh_print();
    bh_add(10);
    bh_print();
    bh_add(2);
    bh_print();

    int testarr[9]={3,2,9,-14,25,6,84,60,0};
    array_print(testarr,9);
    heapsort(testarr,9);
    array_print(testarr,9);
    return 0;
}
