
/*
 Exercise 1: Allocate Memory for an Integer
Goal: Understand how to allocate memory for a single variable using malloc.

Activity:

Log Session a pointer to an integer.
Use malloc to allocate memory for one integer.
Assign a value to that memory.
Print the value through the pointer.
Free the allocated memory.
Include NULL check after malloc.
 */
#include <stdio.h>
#include <stdlib.h>

void memory_for_int()
{
    int *ptr;

    ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }

    *ptr = 25;

    printf("value = %d\n", *ptr);

    free(ptr);
}

/*
 Exercise 2: Allocate and Store a List of Integers
Goal: Practice allocating memory for an array of integers.

Activity:

Ask the user to enter the number of integers.
Allocate memory dynamically using malloc based on input.
Use a loop to take integer inputs into the allocated array.
Display the entered values.
Free the allocated memory.
 */

/*
 Exercise 3: Zero-Initialize an Integer Array
Goal: Understand how calloc initializes memory.

Activity:

Ask the user for the number of elements.
Allocate memory using calloc.
Print the initial values (before user input).
Assign values, then display them.
Free the memory after use.
 */
void zero_initialize_an_integer_array()
{
    int n, i;
    printf("enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
        return;

    printf("initial values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nenter values:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("after assigning values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
}

/*
 Exercise 4: Compare malloc and calloc
Goal: Learn the key difference between malloc and calloc.

Activity:

Allocate two arrays using malloc and calloc with the same size.
Print the default values in both arrays.
Use a loop for printing to understand initialization differences.
Free both arrays.
 */
void compare_malloc_and_calloc()
{
    int n = 5, i;

    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)calloc(n, sizeof(int));

    if (arr1 == NULL || arr2 == NULL)
        return;

    printf("malloc values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    printf("\ncalloc values:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr2[i]);

    free(arr1);
    free(arr2);
}

/*
 Exercise 5: Reallocate an Array Dynamically
Goal: Use realloc to extend an array as needed.

Activity:

Allocate memory for 2 integers.
Ask the user for values.
Then resize the array to 5 integers using realloc.
Accept more values into the resized array.
Print all values.
Free the memory at the end.
 */
void reallocate_an_array_dynamically()
{
    int i;
    int *arr = (int *)malloc(2 * sizeof(int));
    if (arr == NULL)
        return;

    printf("enter 2 values:\n");
    for (i = 0; i < 2; i++)
        scanf("%d", &arr[i]);

    arr = (int *)realloc(arr, 5 * sizeof(int));
    if (arr == NULL)
        return;

    printf("enter 3 more values:\n");
    for (i = 2; i < 5; i++)
        scanf("%d", &arr[i]);

    printf("all values:\n");
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);
}

/*
 Exercise 6: Log Session a Dynamic 2D Array
Goal: Learn how to allocate and access a 2D array dynamically.

Activity:

Ask the user for number of rows and columns.
Allocate memory for an array of row pointers.
Allocate each row separately using malloc.
Accept values for each row-column index.
Display the matrix.
Free each row and then the row pointer array.
 */
void log_session_a_dynamic_2d_array()
{
    int rows, cols, i, j;
    printf("enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL)
        return;

    for (i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL)
            return;
    }

    printf("enter values:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);

    printf("matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    for (i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
}

/*
 Exercise 7: Dynamic String Input
Goal: Handle strings with dynamic memory allocation.

Activity:
Ask the user to enter a string.
Find its length using strlen.
Allocate memory to store the string using malloc.
Copy the string to the new memory.
Print the copied string.
Free the memory.
 */
void dynamic_string()
{
    char str[100];
    printf("enter string: ");
    scanf("%s", str);

    int len = strlen(str);
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if (copy == NULL)
        return;

    strcpy(copy, str);
    printf("copied string: %s\n", copy);

    free(copy);
}

/*
 Exercise 8: Implement Custom strdup()
Goal: Practice duplicating a string using dynamic memory.

Activity:

Log Session a function that takes a string as input.
Allocate memory for a copy of the string.
Copy character by character.
Return the copied string.
Call this function and display the result.
Free the copied string.
 */
char *custom_strdup(char *str)
{
    int i, len = strlen(str);
    char *copy = (char *)malloc((len + 1) * sizeof(char));
    if (copy == NULL)
        return NULL;

    for (i = 0; i <= len; i++)
        copy[i] = str[i];

    return copy;
}

void custom_strdup()
{
    char str[100];
    printf("enter string: ");
    scanf("%s", str);

    char *dup = custom_strdup(str);
    if (dup == NULL)
        return;

    printf("duplicated string: %s\n", dup);
    free(dup);
}

/*
 Exercise 9: Log Session a Linked List with 3 Nodes
Goal: Apply dynamic memory to build a simple linked list.

Activity:

Define a struct for a node with data and next.
Use malloc to create 3 nodes dynamically.
Link the nodes manually.
Traverse and print the list.
Free all nodes after traversal.
 */
struct node
{
    int data;
    struct node *next;
};

void log_session()
{
    struct node *n1 = malloc(sizeof(struct node));
    struct node *n2 = malloc(sizeof(struct node));
    struct node *n3 = malloc(sizeof(struct node));

    if (n1 == NULL || n2 == NULL || n3 == NULL)
        return;

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;

    struct node *temp = n1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(n1);
    free(n2);
    free(n3);
}

/*
 Exercise 10: Log Session and Reverse an Array
Goal: Use pointers to reverse dynamically allocated memory.

Activity:

Allocate an array of integers using malloc.
Accept n values.
Reverse the array using pointer arithmetic (not indexing).
Print reversed values.
Free the memory.
 */
void log_session_and_reverse_array()
{
    int n, i;
    printf("enter size: ");
    scanf("%d",&n);

    int *arr=malloc(n*sizeof(int));
    if (arr==NULL)
        return;

    printf("enter values:\n");
    for (i=0;i<n;i++)
        scanf("%d",arr+i);

    int *start=arr;
    int *end=arr+n-1;
    while(start<end)
    {
        int temp =*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }

    printf("reversed array:\n");
    for (i=0;i<n;i++)
        printf("%d",arr[i]);
    free(arr);
}

/*
 Exercise 11: Accept Characters Until Enter Pressed
Goal: Dynamically grow a string buffer with realloc.
Activity:
Start with a small buffer.
Accept characters one by one.
Reallocate buffer each time a new character is added.
Stop on newline character.
Null-terminate and print the string.
Free the memory.
 */
void accept_characters_until_enter_pressed()
{
    int size=2,i=0;
    char *str=malloc(size);
    if (str==NULL)
        return;

    printf("enter characters (press enter to stop):\n");
    char ch;
    while((ch=getchar())!='\n')
    {
        str[i++]=ch;
        if(i==size)
        {
            size*= 2;
            str=realloc(str,size);
            if (str==NULL)
                return;
        }
    }
    str[i] ='\0';
    printf("entered string: %s\n", str);
    free(str);
}

/*
 Exercise 12: Track Frequency of Elements
Goal: Use calloc for zero-initialized counting.
Activity:
Allocate an integer array of size 100 using calloc.
Accept n numbers between 0 and 99.
Increment the value at each index to count frequency.
Display the frequencies.
Free the memory.
 */
void frequency_of_elements()
{
    int n, i;
    printf("how many numbers: ");
    scanf("%d",&n);

    int *freq=(int *)calloc(100,sizeof(int));
    if (freq==NULL)
        return;

    int num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        if(num>=0 && num<100)
            freq[num]++;
    }

    printf("frequencies:\n");
    for(i=0;i<100;i++)
        if(freq[i]>0)
            printf("%d: %d\n",i,freq[i]);

    free(freq);
}

/*
 Exercise 13: Memory Leak Simulation
Goal: Understand what a memory leak is.

Activity:

Allocate memory using malloc and assign values.
Intentionally skip free().
Run the program with tools like valgrind to observe the leak.
Fix the leak by adding proper free().
 */
void memory_leak_simulation()
{
    int *arr=malloc(5*sizeof(int));
    if (arr==NULL)
        return;

    for(int i=0;i<5;i++)
        arr[i]=i+1;

    printf("values before freeing:\n");
    for(int i=0;i<5;i++)
        printf("%d ",arr[i]);

    // memory leak example: comment out free(arr);
    free(arr);
}

/*
 Exercise 14: Tokenize String Dynamically
Goal: Store each word of a sentence in dynamically allocated memory.

Activity:

Accept a sentence as input.
Use strtok() to split it into words.
Use malloc to copy each token into a new memory block.
Store them in a pointer array.
Print all words and free each block.
 */

void tokenize_string()
{
    char sentence[500];
    printf("Enter a sentence:\n");
    scanf(" %[^\n]", sentence);
    char *tokens[100];     // pointer array to store words
    int count = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL)
    {
        tokens[count] = (char *)malloc(strlen(token) + 1);

        if (tokens[count] == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, " ");
    }
    printf("\nWords are:\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", tokens[i]);
    for (int i = 0; i < count; i++)
        free(tokens[i]);
}

/*
 Exercise 15: Dynamic Menu-Driven Array
Goal: Handle operations on a dynamic array with growing size.

Activity:

Start with an empty array.
Provide a menu with options: Add element, Display, Exit.
Use realloc each time user adds an element.
Print array contents.
Free memory on exit.
 */
void menu_driven_array()
{
    int *arr=NULL,size=0,choice;
    do
    {
        printf("1. add element 2. display 3. exit\nchoice: ");
        scanf("%d",&choice);
        if (choice==1)
        {
            arr=realloc(arr,(size+1)*sizeof(int));
            printf("enter value: ");
            scanf("%d",&arr[size]);
            size++;
        }
        else if (choice==2)
        {
            for(int i=0;i<size;i++)
                printf("%d ",arr[i]);
            printf("\n");
        }
    } while(choice!=3);

    free(arr);
}

/*
 Exercise 16: Safe Memory Allocation Check
Goal: Practice error-checking after allocation.

Activity:

Try allocating a large chunk of memory (e.g., 1GB).
Check if the pointer is NULL.
If successful, print a success message.
If failed, handle the error gracefully.
Free if allocation succeeded.
 */
void safe_memory_allocation_check()
{
    long long size =1024 * 1024 * 1024;
    char *ptr=malloc(size);
    if (ptr==NULL)
        printf("allocation failed\n");
    else
    {
        printf("allocation successful\n");
        free(ptr);
    }
}

/*
 Exercise 17: Struct Array with Dynamic Allocation
Goal: Allocate memory for array of structs.

Activity:

Define a struct (e.g., name and age).
Ask user how many entries to store.
Allocate memory using malloc.
Accept values and display them.
Free the memory.
 */
struct person
{
    char name[50];
    int age;
};

void struct_array()
{
    int n;
    printf("how many entries: ");
    scanf("%d",&n);

    struct person *arr =malloc(n*sizeof(struct person));
    if(arr==NULL)
        return;

    for(int i=0;i<n;i++)
    {
        printf("enter name and age: ");
        scanf("%s %d",arr[i].name,&arr[i].age);
    }

    printf("entries:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",arr[i].name, arr[i].age);

    free(arr);
}

/*
Exercise 18: Insert Element at Any Position
Goal: Modify dynamic array and shift elements.

Activity:

Allocate memory for an array.
Accept n values.
Ask user to insert a value at a specific position.
Use realloc to increase size.
Shift elements and insert new value.
Print final array and free memory. 
 */
void insert_element_any_position()
{
    int n, i;
    int *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int value, position;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position (0 to %d): ", n);
    scanf("%d", &position);

    if (position < 0 || position > n)
    {
        printf("Invalid position\n");
        free(arr);
        return;
    }
    int *temp = (int *)realloc(arr, (n + 1) * sizeof(int));
    if (temp == NULL)
    {
        printf("Reallocation failed\n");
        free(arr);
        return;
    }
    arr = temp;

    for (i = n; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = value;
    n++;  
    printf("Final array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
}

/*
 Exercise 19: Dynamic Array of Pointers to Integers
Goal: Work with array of pointers using malloc.

Activity:

Ask user for count.
Allocate array of int* pointers.
Use malloc to assign an integer for each pointer.
Assign and print values.
Free all integers and the array.
 */
void pointers_to_integers()
{
    int n;
    printf("enter number of integers: ");
    scanf("%d", &n);

    int **arr=malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        arr[i]=malloc(sizeof(int));
        printf("enter value for element %d: ", i);
        scanf("%d",arr[i]);
    }

    printf("values:\n");
    for(int i=0;i<n;i++)
        printf("%d ", *arr[i]);

    for(int i=0;i<n;i++)
        free(arr[i]);
    free(arr);
}
/*
 Exercise 20: Simulate Memory Fragmentation
Goal: Understand fragmentation with sequential malloc and free.

Activity:

Allocate multiple memory blocks of varying sizes.
Free some in between.
Allocate a new block that fits only in fragmented space.
Observe behavior.
Free all at the end.
 */
int main()
{
	memory_for_int();
	zero_initialize_an_integer_array();
	compare_malloc_and_calloc();
	reallocate_an_array_dynamically();
	tokenize_string();
	log_session_a_dynamic_2d_array();
	dynamic_string();
	custom_strdup();
	log_session();
	insert_element_any_position();
	log_session_and_reverse_array();
	accept_characters_until_enter_pressed();
	frequency_of_elements();
	memory_leak_simulation();
	menu_driven_array();
	safe_memory_allocation_check();
	struct_array();
	pointers_to_integers();
	return 0;
}
