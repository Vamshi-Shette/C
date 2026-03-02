#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 1. Pointer Declaration and Initialization
Goal: Declare pointers for various data types and initialize them properly to point to existing variables or
dynamically allocated memory. Use pointer arithmetic and typecasting appropriately.

Activity:

Declare pointers to different data types (int, float, char).
Dynamically allocate memory for these pointers.
Assign addresses of variables to pointers and access their values through the pointers.
Perform pointer arithmetic to move through allocated memory blocks.
Use typecasting to convert pointers between compatible types.
 */
void pointer_declarations()
{
    int *ip=(int *)malloc(sizeof(int));
    float *fp=(float *)malloc(sizeof(float));
    char *cp=(char *)malloc(sizeof(char));
    *ip=10;
    *fp=2.2;
    *cp='c';

}
/*
 3. Pointer to Pointer (Double Pointer)
Goal: Understand how to use double pointers for indirect referencing and dynamic memory management.

Activity:

Declare a double pointer and use it to dynamically allocate memory for a single variable or an array.
Access and modify the allocated memory via the double pointer.
Pass double pointers to functions to dynamically allocate or modify memory inside the function.
 */
void ptr_to_ptr()
{
        int **dp=(int **)malloc(sizeof(int *));
        *dp=(int *)malloc(sizeof(int));
        **dp=10;

        //dynamically allocate memory for an array
        int **pp=(int **)malloc(sizeof(int *));
        *pp=(int *)malloc(5*sizeof(int));
        int i;
        for(i=0;i<5;i++)
                (*pp)[i]=i+1;
        for(i=0;i<5;i++)
                printf("%d "(*pp)[i]);

        return;

}

/*
2. Array and Pointer Arithmetic
Goal: Traverse and manipulate arrays by using pointers and pointer arithmetic instead of array indexing.

Activity:

Log Session an array of integers.
Use a pointer to iterate through the array elements by incrementing the pointer.
Perform operations like summing the elements or modifying them using only the pointer (no array indices).
Implement a function that receives a pointer and size to reverse the array elements in place.
*/
void reverse(int *p,int n)
{
int i;
for(i=0;i<n/2;i++)
	{
		int temp=*(p+i);
		*(p+i)=*(p+n-1-i);
		*(p+n-1-i)=temp;
	}
}

void array_and_pointer()
{
	int arr[]={1,2,3,4,5};
	int n=5;
	int *p=arr;
	int sum=0,i;
	printf("array elements using pointer: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",*p);
		sum+=*p;
		p++;
	}
	printf("\nsum: %d\n",sum);
	p=arr;
	for(i=0;i<n;i++)
	{
		*p=*p+1;
		p++;
	}
	printf("after modification: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	reverse(arr,n);
	printf("after reverse: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
/*
5. Dynamic Memory Allocation
Goal: Allocate, reallocate, and free memory dynamically for different data types and structures while avoiding memory leaks.

Activity:

Allocate memory for an array using malloc.
Expand or shrink the allocated memory using realloc.
Initialize the allocated memory using calloc.
Free allocated memory after use.
Handle cases where allocation fails.
*/
void dynamic_allocation()
{
    int *p=(int *)malloc(5*sizeof(int));
	if(p==NULL)
	{
        printf("calloc not allocated memory\n");
		return;
	}
    for(int i=0;i<5;i++)
    {
        *(p+i)=i+1;
    }
	for(i=0;i<5;i++)
        printf("%d "p[i]);
	// realloc 
	p=realloc(p,10*sizeof(int));
	if(p==NULL)
	{
	 	printf("calloc not allocated memory\n");
		return;
	}
	for(int i=5;i<10;i++)
    {
        *(p+i)=i+1;
    }
    for(i=5;i<10;i++)
        printf("%d "p[i]);

	//use calloc to initialize
	int *q=(int *)calloc(5,sizeof(int));
	if(q==NULL)
		printf("calloc not allocated memory\n");
	for(i=0;i<5;i++)
                printf("%d "q[i]);
	free(p);
	free(q);
	return;

}

/*
 6. Character Pointer and String Handling
Goal: Manipulate strings using character pointers and standard string library functions.

Activity:

Declare a character pointer and assign it to a string literal or dynamically allocated memory.
Use pointer arithmetic to traverse and modify the string.
Implement functions to concatenate, copy, or reverse strings using only pointers.
Understand how strings are stored and accessed in memory via pointers.
 */
void concatenate_str(char *str1, char *str2)
{
	int i=0;
	while(str1[i])
		i++;
	for(int j=0;str2[j];j++)
		str1[i+j]=str2[j];
	str[i+j]='\0';
	printf("%s",str1);
	return;
}
void string_copy(char *str1,char *str2)
{
	int i;
	for(i=0;str2[i];i++)
		str1[i]=str2[i];
	str1[i]=str2[i];
	printf("%s",str1);
	return;
}
void reverse_string(char *str1)
{
	int len=strlen(str1)-1;
	int i;
	char temp;
	for(i=0;i<=len/2;i++)
	{
		temp=str1[i];
		str1[i]=str1[len-i];
		str1[len-i]=temp;
	}
	printf("%s",str1);
	return;
}

void char_pointer()
{
	char *str=(char *)malloc(20);
	scanf("%[^\n]s",str);
	*(str+0)='c';
	concatenate_str(str1,str2);
	string_copy(str1,str2);
	reverse_string(str1);
	return;
}
void dynamic_allocation()
{
	int size=10;
	char *str=malloc(10);
	if(str==NULL)
		return;
	int i=0;
	char ch;
	while((ch==getchar())!='\n')
	{
		if(i>=size-1)
		{
			size*=2;
			char *temp=realloc(str,size);
			if(temp==NULL)
			{
				free(str);
				printf("allocation failed\n");
				return;
			}
			str=temp;
		}
		str[i++]=ch;
	}
	str[i]=0;
	printf("%s",str);
	free(str);
	return;
}

/*
4. Pointer and Function
Goal: Use pointers to pass variables or arrays to functions so that the function can modify the original data.

Activity:

Write a function that takes pointers as parameters to swap two integer variables.
Log Session a function that modifies the elements of an array via a pointer.
Pass a pointer to a function to update the contents of a structure or a dynamically allocated memory block.
*/

struct student
{
	int id;
	float marks;
};

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void modify_array(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
		*(arr+i)=*(arr+i)*2;
}

void update_structure(struct student *s)
{
	s->marks=95.0;
}

void pointer_and_function()
{
	int x=10,y=20;
	printf("before swap: %d %d\n",x,y);
	swap(&x,&y);
	printf("after swap: %d %d\n",x,y);
	int arr[]={1,2,3,4,5};
	int n=5,i;
	modify_array(arr,n);
	printf("modified array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	struct student *s=malloc(sizeof(struct student));
	s->id=1;
	s->marks=60.0;
	printf("before update marks: %.2f\n",s->marks);
	update_structure(s);
	printf("after update marks: %.2f\n",s->marks);
	free(s);
}
/*
 8. Pointer and Multi-Dimensional Arrays
Goal: Access and manipulate elements of multi-dimensional arrays using pointers and pointer arithmetic.

Activity:

Declare a 2D array.
Use pointers to iterate through rows and columns.
Implement operations such as matrix transpose or addition using pointer arithmetic only.
Pass multi-dimensional arrays as pointers to functions and manipulate elements.
*/
void matrix_addition(int **arr1,int **arr2,int **arr3,int rows,int columns)
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			(*(arr3+i)+j)=(*(arr1+i)+j)+(*(arr2+i)+j);
		}
	}
	
	for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
           printf("%d ",(*(arr3+i)+j));
        }
	    printf("\n");
    }

}
void matrix_transpond(int **arr1,int **arr2,,int rows,int columns)
{
    for(j=0;j<columns;j++)
    {
        for(i=0;i<rows;i++)
        {
            (*(arr2+j)+i)=(*(arr1+i)+j)+;
        }
   }
	for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
            printf("%d ", *(*(arr2+i)+j));
        printf("\n");
	}
	return;
}

void multi_dimensional_arrays()
{
	int arr1[][3]={{1,2,3},{4,5,6},{7,8,9}};
	int arr1[][3]={{1,2,3},{4,5,6},{7,8,9}};
	int rows=sizeof(arr1)/sizeof(arr1[0]);
	int columns=sizeof(arr1[0])/sizeof(arr1[0][0]);
	int arr3[3][3];
	matrix_addition(arr1,arr2,arr3,rows,columns);
	int arr4[2][3]={{1,2,3},{4,5,6}},arr5[3][2];
	int rows1=sizeof(arr4)/sizeof(arr4[0]);
    int columns1=sizeof(arr4[0])/sizeof(arr4[0][0]);
	matrix_transpond(arr4,arr5,rows1,columns1);
	return;
}

/*
9. Pointer and Structures
Goal: Use pointers to access and modify structure members efficiently, including passing structures to functions.

Activity:

Define a structure and create a pointer to it.
Use the pointer to read and modify structure members.
Pass structure pointers to functions that update structure data.
Dynamically allocate memory for structures and handle them via pointers.
*/
struct student
{
	int id;
	char name[50];
	float marks;
};
void update_marks(struct student *s,float new_marks)
{
	s->marks=new_marks;
}
void pointer_and_structures()
{
	struct student *s1;
	s1=malloc(sizeof(struct student));
	if(s1==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	s1->id=1;
	strcpy(s1->name,"john");
	s1->marks=75.5;
	printf("before update: %d %s %.2f\n",s1->id,s1->name,s1->marks);
	update_marks(s1,88.0);
	printf("after update: %d %s %.2f\n",s1->id,s1->name,s1->marks);
	free(s1);
}

/*
10. Pointer and File I/O
Goal: Use pointers and dynamic memory to efficiently read and write data of variable sizes to files.

Activity:

Open a file for reading and writing.
Determine the size of the file or data to read.
Dynamically allocate a buffer to hold file data.
Use pointers to read the data into memory and write data back to a file.
Close the file and free allocated memory.
*/

void pointer_and_file()
{
	FILE *fp;
	char *buffer;
	long size;
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
		printf("file not found\n");
		return;
	}
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	rewind(fp);
	buffer=malloc(size+1);
	if(buffer==NULL)
	{
		printf("memory allocation failed\n");
		fclose(fp);
		return;
	}
	fread(buffer,1,size,fp);
	buffer[size]='\0';
	printf("file content:\n%s\n",buffer);
	fclose(fp);
	fp=fopen("copy.txt","w");
	if(fp!=NULL)
	{
		fwrite(buffer,1,size,fp);
		fclose(fp);
	}
	free(buffer);
}
/*
 12. Pointer and Recursion
Goal: Use pointers within recursive functions to manipulate data structures or strings.

Activity:

Write a recursive function to reverse a string using pointers.
Implement a recursive traversal of a linked list using pointers.
Use recursion to perform operations such as summing elements of an array via pointer traversal.
 */
void rev_string(char *start,char *end)
{
	
	if(start>=end)
		return;
	char temp;
	temp=*start;
	*start=*end;
	*end=temp;
	rev_string(start+1,end-1);
}
void ptr_and_recursion()
{
	char str[10]="hello";
	rev_string(str);
	return;
}
int main()
{
	pointer_declaration();
	ptr_to_ptr();
	pointer_and_function();
	array_and_pointer();
	dynamic_allocation();
	ptr_and_recursion();
	pointer_and_structures();
	pointer_and_file();
	multi_dimensional_arrays();
	char_pointer();
	return 0;
}
