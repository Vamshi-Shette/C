#include<stdio.h>

void print(int *arr,int num)
{
        //printf("Elements in array are: ");
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
        return;
}

/*
17.Question: Find second largest element
Question description: Write a C program to find the second largest number in the array.
Sample data:
Input: 10 20 50 40
Expected output:
Second largest: 40
*/
void second_largest(int *arr,int num)
{
        int large,sec_large=arr[0];
        large=arr[0];
        for(int i=1;i<num;i++)
        {
                if(arr[i]>large)
                {
                        sec_large=large;
                        large=arr[i];
                }
                else if(arr[i]>sec_large)
                        sec_large=arr[i];
        }
        printf("Second largest: %d",sec_large);
        return;

}
/*
18.Question: Difference between max and min
Question description: Write a C program to find the difference between largest and smallest elements in an array.
Sample data:
Input: 5 1 9 3 6
Expected output:
Difference: 8
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
        printf("Difference: %d",max-min);
        return;
}

/*
19.Question: Left rotate array by n
Question description: Write a C program to rotate an array to the left by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 3 4 5 1 2
*/
void left_rotate(int *arr,int num)
{
        int rotate,temp;
        printf("Rotate by: ");
        scanf("%d",&rotate);
        if(rotate>=num)
                rotate=rotate-num;
        for(int i=0;i<rotate;i++)
        {
                for(int j=0;j<num-1;j++)
                {

                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                }
        }
        printf("Rotated array:");
        print(arr,num);
        return;
}
/*
20.Question: Right rotate array by n
Question description: Write a C program to rotate an array to the right by n positions.
Sample data:
Array: 1 2 3 4 5
Rotate by: 2
Expected output:
Rotated array: 4 5 1 2 3
*/
void right_rotate(int *arr,int num)
{
        int rotate,temp;
        printf("Rotate by: ");
        scanf("%d",&rotate);
        if(rotate>=num)
                rotate=rotate-num;
        for(int i=0;i<rotate;i++)
        {
                for(int j=num-1;j>0;j--)
                {

                        temp=arr[j];
                        arr[j]=arr[j-1];
                        arr[j-1]=temp;
                }
        }
        printf("Rotated array:");
        print(arr,num);
        return;
}

/*
21.Question: Sum of even numbers
Question description: Write a C program to find the sum of all even numbers in an array.
Sample data:
Input: 2 3 4 5 6
Expected output:
Sum of even numbers: 12
*/
void sum_of_even(int *arr,int num)
{
        int sum=0;
        for(int i=0;i<num;i++)
        {
                if(arr[i]%2==0)
                        sum+=arr[i];
        }
        printf("Sum of even numbers: %d",sum);
        return;
}
/*
22.Question: Count prime numbers
Question description: Write a C program to count and display all prime numbers in an array.
Sample data:
Input: 2 4 5 6 7 8
Expected output:
Primes: 2 5 7
Count: 3
*/
int prime(int num)
{
        if(num==1)
                return 0;
        for(i=2;i<num;i++)
        {
                if(num%i==0)
                        count++;
        }
        if(count>1)
                return 0;
        else
                return 1;
}
void count_prime(int *arr,int num)
{
        printf("Primes: ");
        for(i=0;i<num;i++)
        {
                if(prime(arr[i]))
                {
                        printf("%d ",arr[i]);
                        count++;
                }
        }
        printf("\nCounts: %d\n",count);
        return;
}

/*
23.Question: Count duplicate elements
Question description: Write a C program to count how many duplicate values are in the array.
Sample data:
Input: 1 2 3 1 4 2
Expected output:
Total duplicate elements: 2
*/
void count_duplicate(int *arr,int num)
{
        int flag,count,i,j,k,dup_count=0;
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
                        dup_count++;
        }
        printf("Total duplicate elements: %d",dup_count);
        return;
}
int main()
{
        int arr[20],num;
        printf("Enter the number of elements : ");
        scanf("%d",&num);
        printf("Array:");
        for(int i=0;i<num;i++)
                scanf("%d",arr+i);
        //second_largest(arr,num);
        //min_max(arr,num);
        //left_rotate(arr,num);
        //right_rotate(arr,num);
        sum_of_even(arr,num);
        return 0;
}
