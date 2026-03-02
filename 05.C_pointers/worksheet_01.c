#include<stdio.h>

/*
 Pointer Declaration and Initialization
Goal: Understand how to declare a pointer and store the address of a variable.

Activity:

Declare an integer variable: int a = 5;
Declare a pointer to int: int *ptr;
Assign the address of a to ptr: ptr = &a;
Print both a and *ptr using printf.
.........................................................................
2. Using & (Address-of) Operator
Goal: Learn how to find and print the memory address of variables.

Activity:

Declare variables of different types: int x;, float y;, char z;
Print their memory addresses using &x, &y, and &z.
.........................................................................
3. Using * (Dereference) Operator
Goal: Learn how to access or modify a variable's value using a pointer.

Activity:

Declare int a = 10;
Log Session int *p = &a;
Change the value at the pointer: *p = 20;
Print a and *p to verify both are 20.
*/

void pointer_basics()
{
	int a=5;
	int *ptr=&a;
	printf("a=%d *ptr=%d\n ",a,*ptr);
	
	*p=20;
	printf("a=%d *ptr=%d\n ",a,*ptr);

	float y;
	float *fptr=&y;
	char z;
	chr *cptr=&z;
	printf("int: %p",ptr);
	printf("float: %p",fptr);
	printf("char: %p",cptr);
	return;
}

/*
4. Swapping Two Numbers Using Pointers
Goal: Understand how to pass variables by reference to functions using pointers.

Activity:

Write a swap function: void swap(int *a, int *b)
In main(), declare two integers and call swap(&x, &y);
Print values before and after swapping.
*/

void swapping_numbers()
{
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}

/*
 5. Pointer Arithmetic with Arrays
Goal: Learn how to access array elements using pointer arithmetic.

Activity:

Declare: int arr[5] = {10, 20, 30, 40, 50};
Use int *p = arr;
Use a loop to print all elements via *(p + i).
 */
void pointer_arithmetics()
{
	int arr[5]={10,20,30,40,50};
	int size=sizeof(arr)/sizeof(arr[0]);
	int *p=arr;
	for(i=0;i<size;i++)
		printf("%d "*(p+i));
	return;
}

/*
 6. Array Index vs Pointer Arithmetic
Goal: Understand that arr[i] and *(arr + i) give the same result.
void pointer_arithmetics()

Activity:
Use both arr[i] and *(arr + i) to print array elements.
Confirm outputs are the same.
 */
void index_vs_pointer()
{
        int arr[5]={10,20,30,40,50};
        int size=sizeof(arr)/sizeof(arr[0]);
        int *p=arr;
        for(i=0;i<size;i++)
                printf("%d "*(p+i));
	printf("\nusing array index: ");
	for(i=0;i<size;i++)
                printf("%d "p[i]);
        return;
}

/*
 7. Modify Array Elements Using Pointers
Goal: Learn to modify values in an array using pointer operations.

Activity:

Log Session int arr[] = {2, 4, 6};
Use pointer arithmetic to increase each element by 1.
Print modified array.
 */
void modify_arr_elements()
{
	 int arr[5]={2,4,6,8,10};
        int size=sizeof(arr)/sizeof(arr[0]);
        int *p=arr;
	for(i=0;i<size;i++)
	{
		*p+=1;
		p++;
	}
        for(i=0;i<size;i++)
                printf("%d "*(p+i));
        return;
}
/*
8. NULL Pointer Safety
Goal: Learn to avoid dereferencing NULL pointers.

Activity:

Declare: int *p = NULL;
Use a condition if (p != NULL) before dereferencing.
Later, assign p = &a; and access safely.
*/
void null_ptr()
{
int *p=NULL;
int a=10;
if(p!=NULL)
printf("%d\n",*p);
else
printf("pointer is null, cannot dereference\n");
p=&a;
if(p!=NULL)
printf("value after assigning address: %d\n",*p);
}

/*
9. Passing Array to Function
Goal: Learn how arrays are passed to functions as pointers.

Activity:

Write void display(int *arr, int n);
Inside the function, loop using pointer arithmetic to print elements.
*/
void display(int *arr,int n)
{
int i;
for(i=0;i<n;i++)
printf("%d ",*(arr+i));
}

void array_to_function()
{
int arr[]={1,2,3,4,5};
int n=5;
display(arr,n);
}

/*
10. Visualizing Memory Addresses
Goal: Visualize how memory is arranged for variables.

Activity:

Declare three local variables.
Print their addresses using printf.
Observe the increasing/decreasing pattern.
*/
void memory_addresses()
{
int a=10;
int b=20;
int c=30;

printf("address of a: %p\n",&a);
printf("address of b: %p\n",&b);
printf("address of c: %p\n",&c);
}

/*
11. Pointer to Pointer (int **)
Goal: Learn how to use a pointer to another pointer.

Activity:

Declare int a = 5;, int *p = &a;, and int **pp = &p;
Print a, *p, and **pp to understand levels of indirection.
*/
void ptr_to_ptr()
{
int a=5;
int *p=&a;
int **pp=&p;

printf("a: %d\n",a);
printf("*p: %d\n",*p);
printf("**pp: %d\n",**pp);
}

/*
12. Garbage Pointer
Goal: Understand what happens when a pointer is used without initialization.

Activity:

Declare an uninitialized pointer int *p;
Try printing *p and observe the issue (garbage value or crash).
Then fix by assigning a valid address.
*/
void garbage_pointer()
{
int *p;
printf("uninitialized pointer value (unsafe): %p\n",p);
//do not dereference here, may crash
int a=50;
p=&a;
printf("after fixing, value: %d\n",*p);
}

int main()
{
	pointer_basics();

	int a=10,b=20;
	printf("a=%d b=%d\n",a,b);
	swapping_numbers(&a,&b);
	printf("a=%d b=%d\n",a,b);
	
	index_vs_pointer();
	modify_arr_elements();
	null_ptr();
	array_to_function();
	memory_addresses();
	ptr_to_ptr();
	garbage_pointer();
	return 0;
}
