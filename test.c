#include<stdio.h>
#include "bsort.h"
/* ***
example of usage of bsort function.

*** */
//compare function for ascending order for int arrays
int compareIntegers(void *a,void *b){
	int a1 = *(int*)a;
	int b1 = *(int*)b;
	return a1-b1;
}
//compare function for descending order for char arrays
int compareChars(void *a, void *b){
	char a1 = *(char*)a;
	char b1 = *(char*)b;
	return b1-a1;
}

void print_int_array(int arr[], int l){
	printf("[");
	for(int i=0;i<l;i++){
		printf(" %d",arr[i]);
	}
	printf(" ]\n");
}

void print_char_array(char arr[],int l){
	printf("[");
	for(int i=0;i<l;i++){
		printf(" %c",arr[i]);
	}
	printf(" ]\n");
}


int main(){
	//testing random int array
	int a[7] = {3,1,8,3,2,9,5};
	printf("Unsorted integers array: \n");
	print_int_array(a,7);
	bsort(a,7,sizeof(int),compareIntegers);
	printf("Sorted (ascending order) integers array: \n");
	print_int_array(a,7);
	
	//testing random char array
	char b[5] = {'k','w','c','a','z'};
	printf("Unsorted characters array: \n");
	print_char_array(b,5);
	bsort(b,5,sizeof(char),compareChars);
	printf("Sorted (descending order) characters array: \n");
	print_char_array(b,5);

	return 0;
}
