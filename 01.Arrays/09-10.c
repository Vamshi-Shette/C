#include<stdio.h>
#include<string.h>
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
//      printf("%d",sizeof(int)*((4)-2));
        return 0;
}
