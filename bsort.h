#ifndef _BSORT_H
#define _BSORT_H
#endif
#include<stdlib.h>
/* ***
NAME - bsort - sort an array
FUNCTION - bsort(void *base, size_t nmemb, size_t size, int (*cmp)(void *, void *))
DESCRIPTION 
bsort function sort an array with 'nmemb' elements of size 'size'. The 'base' argument points to the start of
the array. The contents of the array are sorted in ascending or descending order according to a comparison
function which is pointed by 'cmp', which is called with two arguments that point to the object to be compared.

RETURN VALUE - bsort is void type.

EXAMPLE - sorting array of int

int compare(void *a,void *b){
	int a1 = *(int*)a;
	int b1 = *(int*)b;
	return a1-b1;
}

void print_array(int arr[], int l){
	printf("[");
	for(int i=0;i<l;i++){
		printf(" %d",arr[i]);
	}
	printf(" ]\n");
}

int main(){
	int a[7] = {3,1,8,3,2,9,5};
	bsort(a,7,sizeof(int),compare);
	print_array(a,7); //prints [ 1 2 3 3 5 8 9 ]
	
	return 0;
}

NOTES 
	This is just a silly implementation of the Bubble Sort algorithm, inspired by the original 'qsort' function.
	It's purpose is just to better understand how the qsort function actually works, thus is also an excercise 
	to learn how to deal with void* type and function pointers in C.
****/
void bsort(void *base, size_t nmemb, size_t size, int (*cmp)(void *,void *)){
	//creating 3 'general' elements and allocating them the 'size' to be used as items of 'base' array.
	void * el1 = malloc(size);
	void * el2 = malloc(size);
	void *aux = malloc(size);
	//casting into char to handle al of the datatypes.
	char *b = (char *)base;
	//bubble sort algorithm
	for(int i =0;i<nmemb-1;i++){
		for(int j=0;j<nmemb-1-i;j++){
			*(char*)el1 = b[j*size];
			*(char*)el2 = b[(j+1)*size]; //multiplication between indexes and size to be compatible between different datatypes
			if(cmp(el1,el2)>=0){ //cmp func used in this way allows ascending or descending order.
				//swap function
				*(char*) aux = b[j*size];
				b[j*size] = b[(j+1)*size];
				b[(j+1)*size] = *(char*)aux;
			}
		}
	}
}

