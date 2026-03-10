#include<stdio.h>
#include<string.h>

/*
Question: Insert element at position
Question description: Write a C program to insert a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Insert: 25 at position 2
Expected output:
Array after insertion: 10 20 25 30 40
*/
void insert(int *arr,int *num)
{
        int value,index;
        printf("insert:");
        scanf("%d",&value);
        printf("at position ");
        scanf("%d",&index);
        memmove(arr+(index+1),arr+index,sizeof(int)*( (*num)-index));
        arr[index]=value;
        *num=(*num)+1;
        return;
}

/*
Question: Delete element at position
Question description: Write a C program to delete a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Delete at position: 2
Expected output:
Array after deletion: 10 20 40
*/
void delete(int *arr,int *num)
{
        int position;
        printf("Delete at position: ");
        scanf("%d",&position);
        memmove(arr+position,arr+(position+1),sizeof(int)*(*num)-position);
        *num=(*num)-1;
}
int main()
{
        int arr[20],num;

        printf("Enter the number of elements : ");
        scanf("%d",&num);
        printf("Enter the elements:");
        for(int i=0;i<num;i++)
                scanf("%d",arr+i);
        insert(arr,&num);
        delete(arr,&num);
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        return 0;
}

