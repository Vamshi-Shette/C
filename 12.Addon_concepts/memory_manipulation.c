/*
1. Write a program that copies one string to another using memcpy.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "Hello World";
    char destination[20];

    memcpy(destination, source, strlen(source) + 1);  // +1 to copy '\0'

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}


/*
2. Write a program to initialize an integer array of size 10 to all zeros using memset.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int arr[10];

    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    return 0;
}


/*
3. Write a code snippet to check if two character arrays are equal using memcmp.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "BitLearn";
    char str2[] = "BitLearn";

    if(memcmp(str1, str2, strlen(str1) + 1) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");

    return 0;
}


/*
4. Use memchr to find the first occurrence of character 'e' in the string "excellent".
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "excellent";

    char *ptr = memchr(str, 'e', strlen(str));

    if(ptr != NULL)
        printf("First occurrence of 'e' found at position: %ld\n", ptr - str);
    else
        printf("Character not found\n");

    return 0;
}


/*
5. Use memmove to shift a portion of an array forward safely.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    // Shift elements from index 0-2 to index 2-4
    memmove(&arr[2], &arr[0], 3 * sizeof(int));

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}

