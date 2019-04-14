#include <stdio.h>
#include <stdlib.h>
/*
 * Arrays are sequential lists of elements in the same type. 
 * If you are familiar with pointers, basically array names are pointers.
 * They are being written in memory sequentially. 
 * So, if you do a[1], it means that add 1 (depends on the type) to address
 * of the first element of the array. 
 * 
 * Address of data element, a[k] = BaseAddress(a) + w(k - lower boundary)
 * w is the size of one element of the array.
 *
 * There are Linked lists which is similar but different to arrays.
 * The main difference is that lists are not sequential and just have next element pointer.
 * Arrays are linear instead.
 * So, choosing one over other depends to the case.
 */

/*
 * Since arrays are linear, traversing is simply looping all of the elements 
 * of the array. 
 */
void traverseArray(int * a, int length){
	//pre increment is used because it is slightly faster. 
	for(int index = 0; index < length; ++index){
		printf("%d ", a[index]);
	}	
}

/*
 * Finding smallest number of an array is just looping array too. 
 * First select the very first element of an array as smallest.
 * And after that just loop and compare.
 */
int findSmallestOfArray(int * a, int length){
	int smallest = a[0];
	for(int index = 1; index < length; ++index){
		if(a[index] < smallest){
			smallest = a[index];
		}
	}
 	return smallest;
}

/*
 * There may be another way to solve it.
 * But simply if we select largest first and the largest
 * that is not equal to it is second largest.
 */
int findSecondLargestOfArray(int * a, int length){
	int largest = a[0];
	for(int index = 1; index < length; ++index){
		if(a[index] > largest){
			largest = a[index];
		}
	}
	
	int secondLargest = a[1];
	for(int index = 0; index < length; ++index){
		if(a[index] != largest){
			if(a[index] > secondLargest){
				secondLargest = a[index];
			}
		}
	}
	return secondLargest;
}

/*
 * There are a lot of more examples.
 * But i will continue to more challenging questions.
 * Inserting an element in an Array looks easy. 
 * But an answer may be silly and there may be a better solution.
 * And i believe best solution i think or find is this.
 */
void insertElementToArray(int * a, int numOfElements, int position, int value){
	for(int index = numOfElements - 1; index < position; --index){
		a[index + 1] = a[index];
	}
	a[position] = value;
}

/*
 * Inserting to sorted array is simply like this.
 * So, i will skip it.
 * Deleting an element from an array can be done in the way below.
 */
void deleteElementFromArray(int * a, int numOfElements, int pos, int val){
	for(int index = pos; index <= numOfElements - 1; ++index){
		a[index] = a[index + 1];
	}
}

/*
 * Merging two array is important case. 
 * Because Merge sort uses it.
 * Sometimes, Merging really large data can not be done in memory.
 * And should be done in harddrive and use small amout of RAM.
 * To do this merge sort is used (called external sort.)
 * Thus, attention should be paid to merging.
 * Merging unsorted arrays and simply concenate them one after another
 * is really simple so i will skip it too.
 */
int* mergeTwoArrays(int * a, int numOfElements1,  int * b, int numOfElements2){
	int * c = (int*) malloc(sizeof(int) *(numOfElements1 + numOfElements2));
	int index1 = 0, index2 = 0, index3 = 0;
	while(index1 < numOfElements1 && index2 < numOfElements2){
		if(a[index1] < b[index2]){
			c[index3] = a[index1++];
		} else {
			c[index3] = b[index2++];
		}
		index3++;
	}
	if(index1 == numOfElements1){
		while(index2 < numOfElements2){
			c[index3] = b[index2++];
			index3++;
		}
	} else if(index2 == numOfElements2){
		while(index1 < numOfElements1){
			c[index3] = a[index1++];
			index3++;
		}
	}
	return c;
}

/*
 * There are several ways to pass an array to a function.
 * Passing individual data values, passing individual addresses and passing entire array.
 * first two is like func(a[i]) and func(&a[i]), passing array is like func(a).
 * The silly code below demonstrates the call with entire array.
 */
void recursiveSilly(int a[5]){
	static int dummy = 0;
	if(dummy++ > 4){
		return;
	}
	//recursive is evil by the way. 
	//do not use if recursion depth is higher than about 7 or 8.
	//use loop instead.
	//the reason is that recursive consumes stack memory i.e RAM.
	recursiveSilly(a);
}

/*
 * As i mentioned before array names are actually pointers. 
 * But they are immutable (constant), so if you try to change the address
 * you will get an error.
 */
void dummyArrayPointerFunc(int a[10]){
	//a dummy example of void pointer.
	void * voidPointer = a;
	
	//we simply cast void pointer to int pointer, Since void is nothing it makes sense.
	int * p = (int *) voidPointer;
	
	//a[i], i[a], *(a+i), *(i+a) all gives same address.
	
	*p = 0;
	*(((int *) voidPointer) + 1) = 1;
	a[2] = 2;
	
	//int *p[x] is array of pointers. 
	//each individual is another pointer. It can be used to store independent addresses.
	int arr1[] = {0,1};
	int arr2[] = {2,3};
	int arr3[] = {4,5};
	int *pArr[3] = {arr1, arr2, arr3};

}

/*
 * Two dimentional arrays are like 1d arrays. 
 * They are being stored in memory sequentally but there is a calculation
 * of addresses and it is abstracted to us. 
 * We simply use it as a[i][k].
 * And think of it like ->
 *
 * -----------------------
 * -    -     -     -    -
 * -----------------------
 * -    -     -     -    -
 * -----------------------
 *
 * But in real life it is not. It is just linear as a 1d array.
 * Hence, there are two ways as row-order and column-order to store them in memory.
 * If you are curious about it, you can google it. 
 * It is actually really simple.
 */
void dummyInit2DArray(){
	int a[2][2] = {1,2,3,4};
	int b[2][2] = {{1,2},{3,4}};
	//both above are same.
	//we can think of them as:
	//1 2
	//3 4
	//in usage. and first dimention is rows and second is columns.
}

/*
 * What operations can be done in an 2d array?
 * Lots of! But only a few of them will be done in this file.
 * Note that photos are actually 2d array of pigments (colors of pixels).
 *
 * We can think 2d arrays as matixes in math. 
 * Hence, we can do any of the operations which are done to matrixes.
 *
 * Transpose: mxn A matrix will become to nxm B matrix and rows become columns.
 *
 * Sum: if two matrixes are compatible(same amount of rows and columns) c[i][k] = a[i][k] + b[i][k]
 *
 * Difference: same as sum but instead of adding them, we substract one from other.
 *
 * Product: if one matrix is mxn and other one is nxk we can product and get mxk matrix.
 * and it like: c[i][l] = S(A[i][j], B[j][l]) for j = 1 to n. (S stands for adding them)
 * And it is like 3 loops nested. I believe you can code it yourself.
 * In a short sentence, it is looping equation above for all of the elements of c.
 *
 * Note that pointer of pointer is not equal to 2d array.
 * If you want to pass 2d array to a func that uses double pointer you should do dynamic allocation.
 */
void transposeMatrix(int a[3][3]){
	int transposedMatrix[3][3];

	for(int index1 = 0; index1 < 3; ++index1){
		for(int index2 = 0; index2 < 3; ++index2){
			transposedMatrix[index1][index2] = a[index2][index1];
		}
	}

	for(int index1 = 0; index1 < 3; ++index1){
	
		printf("\n");
		for(int index2 = 0; index2 < 3; ++index2){
                        printf("%d ", transposedMatrix[index1][index2]);
                }
        }
}	

/*
 * The ways of passing 2d arrays to a function is given below:
 * Passing individual elements, passing a row, passing the entire array.
 *
 * if a funtion is like func(int arr[]) you can pass one row as func(a[1]).
 * Passing entire array is calling func(arr[10][]) or func(arr[10][10]) as func(a).
 */
void selfCallingSilly(int arr[2][2]){
	static int uselessVariable = 0;
	
	if(uselessVariable++ > 4){
		return;
	}
	selfCallingSilly(arr);
}


/*
 * I did not mind the args and argv.
 * Since i will not pass while executing the process.
 */
int main(){

	return 0;
}
