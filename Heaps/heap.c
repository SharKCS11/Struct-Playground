#include "heap.h"
#include <stdio.h>
#include <stdint.h>

//#define DEBUG_HEAPIFY
//#define DEBUG_HEAPSORT

#ifdef DEBUG_HEAPIFY
# define DEBUG_PRINT_HEAPIFY(x) printf x
#else
# define DEBUG_PRINT_HEAPIFY(x) do {} while (0)
#endif

#ifdef DEBUG_HEAPSORT
# define DEBUG_PRINT_HEAPSORT(x) printf x
#else
# define DEBUG_PRINT_HEAPSORT(x) do {} while (0)
#endif

/** HELPER FUNCTIONS **/
static void swapInts(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


static void fixDown(int arr[], int size, int idx)
{
    int lc_i, rc_i; //left child and right child indices
    while(1){
        lc_i = (2*idx+1 < size) ? (2*idx+1) : -1; //sanity check: left child exists
        rc_i = (2*idx+2 < size) ? (2*idx+2) : -1; //sanity check: right child exists
        int least_i = idx;
        if(lc_i>0 && arr[lc_i]<arr[least_i]) //left child is smaller
            least_i = lc_i;
        if(rc_i>0 && arr[rc_i]<arr[least_i]) //right child is smaller
            least_i=rc_i;
        DEBUG_PRINT_HEAPIFY((" ..least is %d.\n",arr[least_i]));
        if(least_i != idx)
        {
            swapInts(&arr[idx],&arr[least_i]);
            idx=least_i;
        }
        else //already fixed
        {
            return;
        }
    }
}

void array_print(int arr[],int size)
{
    int* tracker = arr;
    printf("[ ");
    while(tracker < arr+size){
        printf("%d ",*tracker);
        ++tracker;
    }
    printf("]\n");
}

/** BINARY HEAP **/
/* Inits, basics, and debugging */
void bh_init()
{
    bh_size=0;
}

int bh_empty(int x)
{
    return bh_size==0;
}

void bh_print()
{
    int* tracker = bh_arr;
    printf("[ ");
    while(tracker < bh_arr+bh_size){
        printf("%d ",*tracker);
        ++tracker;
    }
    printf("]\n");
}


//main functions
void bh_add(int x)
{
    bh_arr[bh_size++]=x;
    //fixup
    int idx=bh_size-1;
    //printf("    Adding %d, idx is %d.\n",x,idx);
    //printf("    Before: ");
    //bh_print();
    while(x<bh_arr[idx/2] && idx!=0){
        swapInts(&bh_arr[idx/2],&bh_arr[idx]);
        idx = idx/2;
    }
}

void heapify(int arr[], int size)
{ //heapify an array representing a complete binary tree heap.
    int last_leaf = (size/2)-1;
    if(last_leaf<0)
        return;
    for(;last_leaf>=0;last_leaf--){
        DEBUG_PRINT_HEAPIFY(("    Now fixing down %d...",arr[last_leaf]));
        fixDown(arr,size,last_leaf);
    }
    return;
}

void heapsort(int arr[],int size)
{
    int sizecpy=size;
    while(size>1){ //reverse heapsort
        heapify(arr,size);
        DEBUG_PRINT_HEAPSORT(("    "));
        swapInts(&arr[0],&arr[(size--)-1]);
        DEBUG_PRINT_HEAPSORT(("   next run "));
        #ifdef DEBUG_HEAPSORT
            array_print(arr,sizecpy);
        #endif
    }
    //reverse
    int *beg=arr, *end=arr+sizecpy-1;
    while(beg < end){
        int temp = *beg;
        *beg++ = *end;
        *end-- = temp;
    }

}

