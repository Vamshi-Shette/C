/*
Question: Print elements of an array
Question description: Write a C program to read n elements into an array and display them.
Sample data:
Enter the number of elements: 5
Enter the elements: 10 20 30 40 50
Expected output:
Elements in array are: 10 20 30 40 50
*/

#include<stdio.h>
void print(int *arr,int num)
{
        printf("Elements in array are: ");
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
        return;
}
/*
Question: Sum of all elements in array
Question description: Write a C program to find the sum of all array elements entered by the user.
Sample data:
Input: 1 2 3 4 5
Expected output:
Sum = 15
*/
void sum_of_elements(int *arr,int num)
{
        int sum=0;
        for(int i=0;i<num;i++)
                sum+=arr[i];
        printf("sum=%d\n",sum);
        return;
}
/*
Question: Find maximum and minimum element
Question description: Write a C program to find the largest and smallest element in the array.
Sample data:
Input: 8 3 15 6 2
Expected output:
Maximum = 15
Minimum = 2
 */       
void min_max(int *arr,int num)
{
        int min,max=arr[0];
        min=max;
        for(int i=0;i<num;i++)
        {
                if(min>arr[i])
                        min=arr[i];
                if(max<arr[i])
                        max=arr[i];
        }
        printf("maximum=%d\nminimum=%d\n",max,min);
        return;
}

/*
Question: Count even and odd elements
Question description: Write a C program to count how many even and odd numbers are in the array.
Sample data:
Input: 4 7 9 10 22
Expected output:
Even: 3
Odd: 2
*/
void count_even_odd(int *arr,int num)
{
        int even=0,odd=0;
        for(int i=0;i<num;i++)
        {
                if(arr[i]%2==0)
                        even++;
                else
                        odd++;
        }
        printf("even=%d\nodd=%d\n",even,odd);
        return;
}

/*
Question: Copy array elements
Question description: Write a C program to copy all elements from one array to another.
Sample data:
Input: 1 2 3 4 5
Expected output:
Copied array: 1 2 3 4 5
*/
void copy_array(int *arr,int num)
{
        static int arr2[20];
        printf("Copied array: ");
        for(int i=0;i<num;i++)
        {
                arr2[i]=arr[i];
                printf("%d",arr2[i]);
        }
        return;
}

/*
Question: Count negative elements

Question description:
Write a C program to count total number of negative elements in an array.

Sample data:
Input: -1 3 -4 5 0 -7

Expected output:
Total negative elements: 3
*/

void count_neg()
{
    int n, i, count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i] < 0)
        {
            count++;
        }
    }
    printf("Total negative elements: %d\n", count);
        return;
}
/*
Question: Find for an element
Question description: Write a C program to search for a number in an array and print its index.
Sample data:
Array: 10 20 30 40 50
Find: 30
Expected output:
Element found at index: 2
*/
void find_element(int *arr,int num)
{
        int find,count=0;
        printf("find:");
        scanf("%d",&find);
        for(int i=0;i<num;i++)
                if(arr[i]==find)
                {
                        printf("Element found at index: %d",i);
                        count++;
                }
        if(count==0)
                printf("Not found\n");
        return;
}

/*
Question: Reverse an array
Question description: Write a C program to reverse an array in-place.
Sample data:
Input: 10 20 30 40 50
Expected output:
Reversed array: 50 40 30 20 10
*/

void rev_array(int *arr,int num)
{
        int temp;
        for(int i=0;i<num/2;i++)
        {
                temp=arr[num-1-i];
                arr[num-1-i]=arr[i];
                arr[i]=temp;
        }
        print(arr,num);
        return;
}



int main()
{
        int arr[20],num;
        printf("Enter the number of elements : ");
        scanf("%d",&num);
        printf("Enter the elements:");
        for(int i=0;i<num;i++)
                scanf("%d",arr+i);
        count_neg();
        print(arr,num);
        sum_of_elements(arr);
        min_max(arr,num);
        count_even_odd(arr,num);
        copy_array(arr,num);
        find_element(arr,num);
        rev_array(arr,num);
        return 0;
}

     
