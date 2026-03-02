/*
11.Question: Sort array in ascending order
Question description: Write a C program to sort elements in ascending order.
Sample data:
Input: 20 5 10 8
Expected output:
Sorted array: 5 8 10 20

12.Question: Sort array in descending order
Question description: Write a C program to sort array elements in descending order.
Sample data:
Input: 7 2 9 4
Expected output:
Sorted array: 9 7 4 2
*/

#include<stdio.h>
void print(int *arr,int num)
{
        printf("Sorted array: ");
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
}
void ascending_sort(int *arr,int num)
{
        int temp;
        for(int i=0;i<num-1;i++)
        {
                for(int j=i+1;j<num;j++)
                {
                        if(arr[i]>arr[j])
                        {
                                temp=arr[i];
                                arr[i]=arr[j];
                                arr[j]=temp;
                        }
                }
        }
        print(arr,num);
        return;
}
void descending_sort(int *arr,int num)
{
        int temp;
        for(int i=0;i<num-1;i++)
        {
                for(int j=i+1;j<num;j++)
                {
                        if(arr[i]<arr[j])
                        {
                                temp=arr[i];
                                arr[i]=arr[j];
                                arr[j]=temp;
                        }
                }
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
        //ascending_sort(arr,num);
        descending_sort(arr,num);
        return 0;
}
