# Generic Bubble Sort C
## Description
This is just an academic function which implements Bubble Sort Algorithm in C, that allows generic usage such as 'qsort' function. The function is named 'bsort'.<br>

<b>bsort</b> function sort an array with 'nmemb' elements of size 'size'. The 'base' argument points to the start of
the array. The contents of the array are sorted in ascending or descending order according to a comparison
function which is pointed by 'cmp', which is called with two arguments that point to the object to be compared.

FUNCTION  
<pre>
bsort(void *base, size_t nmemb, size_t size, int (*cmp)(void *, void *))
</pre>
where <b>base</b> is the pointer to the first element of the array to sort; <b>nmemb</b> is the number of elements inside of the array; <b>size</b> is the size of each element of the array; <b>cmp</b> is a pointer to a comparison function.

## Usage

To use <b>bsort</b> function, only thing you need is to store <b><i>bsort.h</i></b> file into your directory, and then you have to remember to import it above all by typing <code>#include "bsort.h"</code>. Then, you have to write your own comparison function to sort any kind of array in any sorting order you want, such as for <b>qsort</b>.

## Example
In a file named '<i>test.c</i>':

<pre class="prettyprint">
int compareIntegers(void *a,void *b){
	int a1 = *(int*)a;
	int b1 = *(int*)b;
	return a1-b1;
}
</pre>
Then you can write your main to use te bsort function like that:

<pre class="prettyprint">
//... 
//a = [3,1,8,3,2,9,5]
bsort(a,7,sizeof(int),compareIntegers);
//...
</pre>
See more <a href="test.c">here</a>

