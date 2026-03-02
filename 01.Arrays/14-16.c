#include<string.h>
#include<stdio.h>

/*
14. Question: Frequency of each element
Question description: Write a C program to count the frequency of each element in an array.
Sample data:
Input: 1 2 2 3 3 3
Expected output:
1 occurs 1 time
2 occurs 2 times
3 occurs 3 times
*/

void find_frequency(int *arr,int n)
{
        int flag,count,i,j,k;
        for(i=0;i<n;i++)
        {
                flag=0;
                count=1;
                for(j=i-1;j>=0;j--)
                {
                        if(arr[i]==arr[j])
                        {
                                flag++;
                                break;
                        }
                }
                if(flag)
                        continue;
                for(k=i+1;k<n;k++)
                {
                        if(arr[i]==arr[k])
                                count++;
                }
 printf("%d occurs %d times\n",arr[i],count);
        }
        return;
}
/*
Question: Remove duplicate elements
Question description: Write a C program to remove duplicate elements from an array.
Sample data:
Even numbers: 2 4 6
Odd numbers: 1 3 5
Input: 2 3 2 4 3 5
Expected output:
Array after removing duplicates: 2 3 4 5
*/

void print(int *arr,int num)
{
        printf("Sorted array: ");
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
}
void remove_duplicate(int *arr, int *num)
{
        int i,j;
        for(i=0;i<(*num);i++)
        {
                for(j=i+1;j<(*num);j++)
                {
                        if(arr[i]==arr[j])
                        {
                                memmove(arr+j,arr+j+1,sizeof(int)*((*num)-j));
                                *num=*num-1;
                        }
                }
        }
        print(arr,*num);
        return;
}
/*
Question: Find duplicate elements
Question description: Write a C program to find all duplicate elements in an array.
Sample data:
Input: 1 2 3 2 4 1
Expected output:
Duplicate elements: 1 2 
*/
void find_duplicate(int *arr,int n)
{
        int flag,count,i,j,k;
        printf("Duplicate elements: ");
        for(i=0;i<n;i++)
        {
                flag=0;
                count=1;
                for(j=i-1;j>=0;j--)
                {
                        if(arr[i]==arr[j])
                        {
                                flag++;
                                break;
                        }
                }
                if(flag)
                        continue;
                for(k=i+1;k<n;k++)
                {
                        if(arr[i]==arr[k])
                                count++;
                }
                if(count>1)
                printf("%d ",arr[i]);
        }

}
int main()
{
        int arr1[20],num1;
        printf("Enter the number of elements : ");
        scanf("%d",&num1);
        printf("Array1:");
        for(int i=0;i<num1;i++)
                scanf("%d",arr1+i);
        //find_frequency(arr1,num1);
        //remove_duplicate(arr1,&num1);
        find_duplicate(arr1,num1);
        return 0;

}
