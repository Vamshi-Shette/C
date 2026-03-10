/*
1. Variadic Sum Function Challenge

Description
Write a C program to compute the sum of any number of integers
 passed as arguments to a function using variadic functions.
Key Concept: Use stdarg.h macros (va_list, va_start, va_arg, va_end)
 to access a variable number of arguments.

Sample Input & Output
Function calls:
sum(3, 1, 2, 3) → Output: 6
sum(5, 1, 2, 3, 4, 5) → Output: 15
sum(3, -1, -2, -3) → Output: -6

Explanation
The first argument is the count of values, followed by that many integers. 
The function returns their sum.
*/
#include<stdio.h>
#include<stdarg.h>
int sum(int count,...)
{
    va_list args;
    va_start(args,count);
    int total=0;
    for(int i=0;i<count;i++)
        total+=va_arg(args,int);
    va_end(args);
    return total;
}

/*
2. Variadic Product Function Challenge

Description
Write a C program to compute the product of any number of integers
 passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h macros to process a variable number of integer arguments.

Sample Input & Output
Function calls:
product(3, 1, 2, 3) → Output: 6
product(4, 1, 2, 3, 4) → Output: 24
product(3, -1, -2, -3) → Output: -6

Explanation
The first argument is the count of values, followed by that many integers.
 The function returns their product.
*/

int product(int count,...)
{
    va_list args;
    va_start(args,count);
    int total=1;
    for(int i=0;i<count;i++)
        total*=va_arg(args,int);
    va_end(args);
    return total;
}

/*
3. Variadic Max-Min Function Challenge

Description
Write a C program to find the maximum and minimum values of a variable number of integers 
passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to process each integer, compare and 
update max and min values.

Sample Input & Output
Function calls:
find_max_min(5, 3, 5, 9, 0, 7)
Output:
Maximum value: 9
Minimum value: 0

Explanation
The first argument is the count of integers, followed by the values.
 The function finds both maximum and minimum among them.
*/

int find_min_max(int count,...)
{
    va_list args;
    va_start(args,count);
    int total=1;
    int value=va_arg(args,int);
    int min=value;
    int max=value;
    for(int i=1;i<count;i++)
    {
        value=va_arg(args,int);
        if(value>max)
            max=value;
        if(value<min)
            min=value;
    }
    printf("min:%d\n",min);
    printf("max:%d\n",max);
    va_end(args);
    return total;
}

/*
4. Variadic String Concatenation Challenge

Description
Write a C program to concatenate a variable number of strings passed 
as arguments to a function using variadic functions.

Key Concept: Use stdarg.h with const char* arguments; 
copy and concatenate each string into a buffer.

Sample Input & Output
Function call:
concat_strings(3, "BitLearn", ".", "Bitsilica")
Output:
Concatenate said strings: BitLearn.Bitsilica

Explanation
The first argument is the count of strings, followed by the strings to concatenate.
 All are joined in order.
*/
#include<string.h>
#include<stdlib.h>
char* string_concat(int count,...)
{
    
    va_list args;
    va_start(args,count);
    va_list temp;
    va_copy(temp,args);
    int len=0;
    int i;
    for(i=0;i<count;i++)
    {
        char* str=va_arg(temp,char *);
        len+=strlen(str);
    }
    va_end(temp);
    
    //allocate memory
    char *result=calloc(len+1,1);
    if(result==NULL)
    {
        va_end(args);
        return NULL;
    }

    for(i=0;i<count;i++)
    {
        char* str=va_arg(args,char*);
        strcat(result,str);
    }

    va_end(args);
    return result;
}

/*
5. Variadic Character Count Challenge

Description
Write a C program to count the number of characters in a variable number of 
strings passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to access each string and strlen() to count their lengths.

Sample Input & Output
Function call:
count_characters(3, "BitLearn", ".", "Bitsilica")
Output:
The total number of characters is 17

Explanation
The first argument is the count of strings, followed by the strings. Their lengths are summed.
*/
int char_count(int count,...)
{
    va_list args;
    va_start(args,count);
    int total=0;
    for(int i=0;i<count;i++)
    {
        char* str=va_arg(args,char*);
        total+=strlen(str);
    }
    va_end(args);
    return total;
}

/*
6. Variadic Average Function Challenge

Description
Write a C program to find the average of a variable number of doubles passed 
as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to process double arguments and calculate their mean.

Sample Input & Output
Function call:
average(4, 10.5, 30.2, 40.1, 20.6)
Output:
The average is: 25.350000

Explanation
The first argument is the count of double values, followed by the values.
 The average is computed and returned.
*/
double average(int count,...)
{
    va_list args;
    va_start(args,count);
    double total;
    for(int i=0;i<count;i++)
        total+=va_arg(args,double);
    va_end(args);
    return total/count;
}

/*
7. Variadic printf() Implementation Challenge

Description
Write a C program to implement a simple printf() function using variadic functions.

Key Concept: Use stdarg.h to accept a format string and variable arguments; 
print accordingly (simplified version).

Sample Input & Output
Function call:
my_printf(3, 10, 20, 30)
Output:
The values are: 10 20 30

Explanation
The first argument is the count of values to print, followed by those values. All are printed in sequence.
*/
void my_printf(int count, ...) 
{
    va_list args;
    va_start(args, count);
    printf("The values are: ");
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    printf("\n");
    va_end(args);
}

/*
8. Variadic Sorting Function Challenge

Description
Write a C program to sort a variable number of integers passed as arguments to a function
 using variadic functions.

Key Concept: Use stdarg.h to gather all integers, copy them to an array, sort, and print.

Sample Input & Output
Function calls:
sort_numbers(5, 9, 5, 7, 1, 3) → Output: 1 3 5 7 9
sort_numbers(3, 1, -2, 0) → Output: -2 0 1

Explanation
The first argument is the count of integers, followed by their values. The function sorts and prints them.
*/
void sort_numbers(int count, ...) 
{
    if (count <= 0) 
        return;
    int numbers[count];
    va_list args;
    va_start(args, count);

    // Copy all numbers into array
    int i;
    for(i=0;i<count;i++)
    {
        numbers[i]=va_arg(args, int);
    }
    va_end(args);
    int temp=0;
    for (i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++) 
        {
            if(numbers[j]>numbers[j+1]) 
            {
                temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
    }

    // Print sorted array
    for (i=0;i<count;i++)
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");
}

// Function to greet multiple people
void greet(int count, ...) 
{
    va_list args;
    va_start(args, count);
    for (int i=0;i<count;i++)
    {
        const char* name=va_arg(args,const char*);
        printf("Hello, %s!\n", name);
    }
    va_end(args);
}

int main()
{
    printf("sum:%d\n",sum(3,10,20,30));
    
    printf("sum:%d\n",product(3,10,5,2));
    
    find_min_max(5,3,5,9,0,7);
    
    char* final = string_concat(3,"BitLearn",".","Bitsilica");
    if (final != NULL) 
    {
        printf("Concatenated said strings: %s\n",final);
        free(final);  
    }

    printf("The total number of characters is:%d\n",char_count(3,"BitLearn", ".", "Bitsilica"));

    double result=average(4,10.5,30.2,40.1,20.6);
    printf("The average is: %f\n", result);

    my_printf(3,10,20,30);

    sort_numbers(5,9,5,7,1,3);  
    
    greet(3,"Alice","Bob","Charlie");
    return 0;
}