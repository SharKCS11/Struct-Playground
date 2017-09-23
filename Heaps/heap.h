#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/* BINARY MIN-HEAP*/
#define MAX_HEAP_SIZE 256

int bh_size;
int bh_arr[MAX_HEAP_SIZE];
//inits, basics, debugging
void bh_init();
int bh_empty();
void bh_print();
void array_print(int arr[],int size);
//main functions
void bh_add(int x);
void heapify(int arr[],int size);


#endif // HEAP_H_INCLUDED
