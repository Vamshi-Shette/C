#include<stdio.h>

/*
 Question 1: Pointer Increment and Access
Task: Log Session an integer array with 5 elements. Use a pointer to access and print the third element by incrementing the pointer appropriately.
int arr[] = {5, 10, 15, 20, 25};
 */
void pointer_access(int *arr,int num)
{
	arr=arr+2;
	printf("third element is: %d\n",*arr);
	return;
}

/*
 Question 2: Pointer Addition
Task: Using the same array, print the last element by adding an integer to the pointer.
int arr[] = {5, 10, 15, 20, 25};
Expected output:
Last element is 25
 */
void pointer_addition(int *arr,int num)
{
	arr=arr+num-1;
        printf("last element is: %d\n",*arr);
        return;
}

/*
 Question 3: Pointer Subtraction
Task: Given two pointers pointing to elements of an integer array, find the distance (number of elements) between them.
int arr[] = {2, 4, 6, 8, 10};
int *p1 = &arr[4];  // points to 10
int *p2 = &arr[1];  // points to 4
Expected output:
Distance between pointers is 3
 */
void pointer_subtraction(int *arr,int num)
{
	int *p1=arr+1;
	int *p2=arr+4;
	printf("Distance between pointers is :%d",p2-p1);
	return;

}
/*
 Question 4: Pointer Comparison
Task: Write code to compare two pointers to elements in an array and print which one points to the element with a smaller index.
int arr[] = {11, 22, 33, 44, 55};
int *ptr1 = &arr[2];  // points to 33
int *ptr2 = &arr[4];  // points to 55
Expected output:
Pointer ptr1 points to an earlier element than ptr2
 */
void pointer_comparison(int *arr,int num)
{
	int *p1=arr+2;
        int *p2=arr+4;
	if(p1<p2)
        printf("Pointer ptr1 points to an earlier element than ptr2");
	else
		printf("Pointer ptr2 points to an earlier element than ptr1");
	return;
}

/*
 Question 5: Traverse Array with Pointer Arithmetic
Task: Using only a pointer (no array indexing), print all elements of the array.
int arr[] = {100, 200, 300, 400};
Expected output:
100 200 300 400
 */
void traverse_array(int *arr,int num)
{
	for(int i=0;i<num;i++)
		printf("%d ",*(arr+i));
	return;
}

/*
 Question 7: Pointer Arithmetic with Different Data Types
Task: Log Session a double array and use pointer arithmetic to print the second element. Explain how pointer arithmetic differs for double compared to int.
double darr[] = {1.1, 2.2, 3.3};
Expected output:
Second element is 2.2
 */
void float_values(double *arr,int num)
{
	arr=arr+1;
    printf("second element is: %d\n",*arr);
    return;
}

/*
 Question 8: Pointer Arithmetic and Array Bounds
Task: Write code that attempts to access memory outside an array using pointer arithmetic and explain why this is unsafe.
int arr[] = {10, 20, 30};
int *ptr = arr + 5; // Out of bounds
Expected output:
Undefined behavior - accessing memory outside the array may cause crash or unexpected results
 */
void array_bound(int *arr,int num)
{
	int *ptr=arr+5;
	if(ptr>(arr+num))
	printf("Undefined behavior - accessing memory outside the array may cause crash or unexpected results");
    return;
}

/*
 Question 9: Reverse Array using Pointer Arithmetic
Task: Write a function that reverses an integer array in place using pointer arithmetic only (no array indexing).
int arr[] = {1, 2, 3, 4, 5};
Expected output:
Reversed array: 5 4 3 2 1
 */
void reverse_array(int *arr,int num)
{
	int temp;
	for(int i=0;i<=num/2;i++)
	{
		temp=*(arr+num-1-i);
		*(arr+num-1-i)=*(arr+num);
		*(arr+i)=temp;
	}
	traverse_array(arr,num);
	return;
}
int main()
{
	int arr1[5]={5,10,15,20,25};
	int size=sizeof(arr1)/sizeof(arr1[0]);
	pointer_access(arr1,size);
	double arr2[5]={1.1,2.2,3.3};
	float_values(arr2,num);
	pointer_addition(arr1,size);
	pointer_subtraction(arr1,size);
	pointer_comparision(arr1,size);
	traverse_array(arr1,size);
	array_bound(arr1,size);
	reverse_array(arr1,size);
	return 0;
}
