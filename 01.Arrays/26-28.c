#include<string.h>
#include<stdio.h>
/*
26. Find the union of two arrays
Question description:
Write a C program to find the union of two arrays (all unique elements from both arrays).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Union: 1 2 3 4 5 6
*/
void print(int *arr,int num)
{
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        //printf("\n");
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
        return;
}

void arrays_union(int *arr1,int num1,int *arr2,int num2)
{
        int j;
        remove_duplicate(arr1,&num1);
        remove_duplicate(arr2,&num2);
        printf("Union: ");
        print(arr1,num1);
        for(int i=0;i<num2;i++)
        {
                for( j=0;j<num1;j++)
                        if(arr2[i]==arr1[j])
                                break;
                if(j==num1)
                        printf("%d ",arr2[i]);
        }
        return;

}
/*
27. Find the intersection of two arrays
Question description:
Write a C program to find the intersection of two arrays (common elements).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Intersection: 3 4
 */
void intersection(int *arr1,int num1,int *arr2,int num2)
{
        int j;
        remove_duplicate(arr1,&num1);
        remove_duplicate(arr2,&num2);
        printf("Intersection: ");
        for(int i=0;i<num2;i++)
        {
                for( j=0;j<num1;j++)
                        if(arr2[i]==arr1[j])
                                break;
                if(j!=num1)
                        printf("%d ",arr2[i]);
        }
        return;

}
/*
 28. Find the difference of two arrays
Question description:
Write a C program to find the difference of two arrays (elements present in first array but not in second).
Sample data:
Array 1: 1 2 3 4 Array 2: 3 4 5 6
Expected output:
Difference (Array1 - Array2): 1 2
*/
void difference(int *arr1,int num1,int *arr2,int num2)
{
        int j;
        remove_duplicate(arr1,&num1);
        remove_duplicate(arr2,&num2);
        printf("Difference (Array1 - Array2): ");
        for(int i=0;i<num1;i++)
        {
                for( j=0;j<num2;j++)
                        if(arr1[i]==arr2[j])
                                break;
                if(j==num2)
                        printf("%d ",arr1[i]);
        }
        return;

}

int main()
{
        int arr1[20],num1;
        printf("Enter the number of elements : ");
        scanf("%d",&num1);
        printf("Array1:");
        for(int i=0;i<num1;i++)
                scanf("%d",arr1+i);

        int arr2[20],num2;
        printf("Enter the number of elements : ");
        scanf("%d",&num2);
        printf("Array2:");
        for(int i=0;i<num2;i++)
                scanf("%d",arr2+i);
        //arrays_union(arr1,num1,arr2,num2);
        //intersection(arr1,num1,arr2,num2);
        difference(arr1,num1,arr2,num2);
        return 0;
}