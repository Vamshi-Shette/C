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
void sum_of_elements(int *arr,int num)
{
        int sum=0;
        for(int i=0;i<num;i++)
                sum+=arr[i];
        printf("sum=%d\n",sum);
        return;
}
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
        print(arr,num);
        sum_of_elements(arr);
        min_max(arr,num);
        count_even_odd(arr,num);
        copy_array(arr,num);
        find_element(arr,num);
        rev_array(arr,num);
        return 0;
}
     