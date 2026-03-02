#include<stdio.h>

/*
24.Question: Split array into halves
Question description: Write a C program to split the array into two halves and print them separately.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
First half: 1 2 3
Second half: 4 5 6
 */
void print(int *arr,int num)
{

        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
}


void split_array(int *arr,int num)
{
        int n1,n2,i;
        int arr1[20],arr2[20];
        if(num%2==0)
        {
                n1=num/2;
                n2=n1;

        }
        else
        {
                n2=num/2;
                n1=n2+1;
        }
for(i=0;i<n2;i++)
        {
              arr1[i]=arr[i];
              arr2[i]=arr[i+n1];
        }
        if(n1>n2)
                arr1[n2]=arr[n2];
        printf("First half: ");
        print(arr1,n1);
        printf("Second half: ");
        print(arr2,n2);
        return;

}
/*
 Question: Segregate even and odd
Question description: Write a C program to arrange all even numbers first and then all odd numbers.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
Even numbers: 2 4 6
Odd numbers: 1 3 5
 */
void segregate_even_odd(int *arr,int num)
{
        int even[num],odd[num];
        int i=0,j=0;
        for(int k=0;k<num;k++)
        {
                if(arr[k]%2==0)
                        even[i++]=arr[k];
                else
                        odd[j++]=arr[k];
        }
        printf("Even numbers: ");
        print(even,i);
        printf("Odd numbers: ");
        print(odd,j);
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
        //split_array(arr,num);
        segregate_even_odd(arr,num);
        return 0;

}
