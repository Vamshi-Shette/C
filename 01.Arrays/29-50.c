#include<stdio.h>

void print(int *arr,int num)
{
        printf("Sorted array: ");
        for(int i=0;i<num;i++)
                printf("%d ",arr[i]);
        printf("\n");
}

/*
29. Check if array is palindrome
Question description:
Write a C program to check whether an array is palindrome (reads the same forward and backward).
Sample data:
Input: 1 2 3 2 1
Expected output:
The array is a palindrome.
 */
void isPalindrome(int *arr,int num)
{
        for(int i=0;i<num/2;i++)
        {
                if(arr[i]!=arr[num-1-i])
                {
                        printf("The array is not a palindrome\n");
                        return;
                }
        }
        printf("The array is a palindrome\n");
        return;
}
/*
30. Count pairs with given sum
Question description:
Write a C program to find number of pairs in the array whose sum is equal to a given value.
Sample data:
Input array: 1 5 7 -1 5 Sum = 6
Expected output:
Number of pairs: 3
 */
void count_pairs(int *arr,int num)
{
        int sum,count=0;
        printf("Sum: ");
        scanf("%d",&sum);
        for(int i=0;i<num-1;i++)
        {
                for(int j=i+1;j<num;j++)
                        if(arr[i]+arr[j]==sum)
                                count++;
        }
        printf("Number of pairs: %d",count);
        return;
}
/*
 31. Find missing number in array
Question description:
Write a C program to find the missing number in an array of size n containing numbers from 1 to n+1.
Sample data:
Input: 1 2 4 5 6
Expected output:
Missing number is: 3
 */
void missing_number(int *arr,int num)
{
        int missing_no=0;
        for(int i=0;i<num;i++)
                if(arr[i]!=i+1)
                {
                        printf("%d\n",i);
                        break;
                }
        return;
}
/*
 32. Find the majority element
Question description:
Write a C program to find the majority element in an array (element appearing more than n/2 times).
Sample data:
Input: 2 2 1 2 3 2 2
Expected output:
Majority element: 2
 */
void majority_element(int *arr,int n)
{
        int flag,count,i,j,k;
        int max_count=0,val;
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
if(count>max_count)
                {
                        max_count=count;
                        val=arr[i];
                }
        }
        printf("Majority element: %d\n",val);
        return;
}

/*
34. Find leader elements in array
Question description:
Write a C program to find all leader elements in the array (elements greater than all elements to their right).
Sample data:
Input: 16 17 4 3 5 2
Expected output:
Leader elements: 17 5 2
*/
void leaders(int *arr,int num)
{
        int i,j;
        printf("Leader elements: ");
        for(i=0;i<num-1;i++)
        {
                for(j=i+1;j<num;j++)
                {
                        if(arr[j]>arr[i])
                                break;
                }
                if(j==num)
                        printf("%d ",arr[i]);
        }
        printf("%d\n",arr[num-1]);
        return;
}

/*
35. Find equilibrium index
Question description:
Write a C program to find the index where the sum of elements to the left is equal to the sum to the right.
Sample data:
Input: -7 1 5 2 -4 3 0
Expected output:
Equilibrium index is 3
 */
void equilibrium_index(int *arr,int num)
{
        int lsum=0,rsum=0,i;
        for(i=0;i<num/2;i++)
        {
                lsum+=arr[i];
                rsum+=arr[num-1-i];
                if(lsum==rsum)
                {
                        printf("Equilibrium index is: %d\n",i+1);
                        return;
                }
        }
        printf("Not found\n");
        return;

}
/*
 36. Find second smallest element
Question description:
Write a C program to find the second smallest element in the array.
Sample data:
Input: 12 13 1 10 34 1
Expected output:
Second smallest element is 10
 */
void second_smallest(int *arr,int num)
{
        int small,sec_small=arr[0];
        small=arr[0];
        for(int i=1;i<num;i++)
        {
                if(arr[i]<small)
                {
                        sec_small=small;
                        small=arr[i];
                }
                else if(arr[i]<sec_small && arr[i]!=small)
                        sec_small=arr[i];
        }
        if(small==sec_small)
        {
                printf("no second smallest number exist\n");
                return;
        }
        printf("Second smallest number: %d\n",sec_small);
        return;

}

/*
 37. Check if array is subset of another
Question description:
Write a C program to check if one array is a subset of another array.
Sample data:
Array 1: 1 2 3 4 5 Array 2: 2 4 5
Expected output:
Array2 is a subset of Array1
 */
void check_subset(int *arr,int num)
{
        int arr2[20],num2;
        printf("Enter the number of elements : ");
        scanf("%d",&num2);
        printf("Array 2:");
        for(int i=0;i<num;i++)
                scanf("%d",arr2+i);
        if(num2>num)
        {
                printf("array2 is not a subset\n");
                return;
        }
        int i,j,count=0;
        for(i=0;i<num2;i++)
        {
                for(j=0;j<num;j++)
                        if(arr2[i]==arr[j])
                        {
                                count++;
                                break;
                        }
        }
        if(count==num2)
                printf("Array2 is a subset of Array1\n");
        else
                printf("Array2 is not a subset\n");
        return;
}

/*
 38. Sort array of 0s, 1s and 2s
Question description:
Write a C program to sort an array consisting of only 0s, 1s, and 2s.
Sample data:
Input: 0 1 2 0 1 2 1 0
Expected output:
Sorted array: 0 0 0 1 1 1 2 2
 */
void sort_array(int *arr,int num)
{
        int i,j,temp;
        for(i=0;i<num;i++)
                if(arr[i]<0 && arr[i]>2)
                {
                        printf("elements must be 0/1/2\n");
                        return;
                }
        for(i=0;i<num;i++)
        {
                for(j=i+1;j<num;j++)
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

/*
 39. Find product of all elements
Question description:
Write a C program to find the product of all elements in the array.
Sample data:
Input: 1 2 3 4
Expected output:
Product: 24
 */
void product(int *arr,int num)
{
        int product=1,i;
        for(i=0;i<num;i++)
                product*=arr[i];
        printf("Product: %d",product);
        return;
}

/*
40. Find the maximum difference between two elements such that larger element appears after the smaller
Question description:
Write a C program to find the maximum difference between two elements in an array such that the larger element appears after the smaller element.
Sample data:
Input: 2 3 10 6 4 8 1
Expected output:
Maximum difference: 8 (10 - 2)
*/
void max_difference(int *arr,int num)
{
        int diff,min=arr[0],max=arr[0],i,highest_element_index;
        for(i=0;i<num;i++)
                if(max<arr[i])
                {
                        max=arr[i];
                        highest_element_index=i;
                }
        for(i=0;i<highest_element_index;i++)
                if(min>arr[i])
                        min=arr[i];
        printf("Maximum difference: %d(%d - %d)\n",max-min,max,min);
        return;
}

/*
 42. Count occurrences of a number
Question description:
Write a C program to count how many times a specific number appears in an array.
Sample data:
Input array: 1 2 3 2 2 5 Number to count: 2
Expected output:
Number 2 occurs 3 times
 */
void count_occurrence(int *arr,int num)
{
        int n,count=0;
        printf("Number to count: ");
        scanf("%d",&n);
        for(int i=0;i<num;i++)
                if(arr[i]==n)
                        count++;
        printf("Number %d occurs %d times\n",n,count);
   printf("Number %d occurs %d times\n",n,count);
        return;

}

/*
 43. Find two elements whose sum is closest to zero
Question description:
Write a C program to find two elements whose sum is closest to zero.
Sample data:
Input: 1 60 -10 70 -80 85
Expected output:
Pair whose sum is closest to zero: -80 85
 */
  void sum_close_to_zero(int *arr,int num)
{
        int sum,min_sum=arr[0]+arr[1];
        int ele1=arr[0],ele2=arr[1];
        for(int i=0;i<num-1;i++)
        {
                for(int j=i+1;j<num;j++)
                {
                        sum=arr[i]+arr[j];

                        if(sum<0)
                                sum*=-1;
                        if(sum<min_sum)
                        {
                                min_sum=sum;
                                ele1=arr[i];
                                ele2=arr[j];
                        }
                }
        }
        printf("Pair whose sum is closest to zero: %d %d\n",ele1,ele2);


}

/*
45. Move all zeros to end of array
Question description:
Write a C program to move all zeros in the array to the end while maintaining the order of non-zero elements.
Sample data:
Input: 1 0 2 0 0 3 4
Expected output:
Output: 1 2 3 4 0 0 0
*/
void all_zeros_last(int *arr,int num)
{
        int i,k,flag;
        for(i=0;i<num;i++)
        {
                flag=0;
                if(arr[i]==0)
                {
                        for(k=i+1;k<num;k++)
                        {
                                if(arr[k]!=0)
                                        break;
                        }
                        if(k!=num)
                        {
                                arr[i]=arr[k];
                                arr[k]=0;
                        }
                        else
                                flag++;
                }
                if(flag)
                        break;
        }
        print(arr,num);
        return;
}
/*
 46. Find the frequency of each element
Question description:
Write a C program to find the frequency of each element in the array.
Sample data:
Input: 10 20 10 30 20 20 10 10
Expected output:
10: 4 20: 3 30: 1
 */
void frequency_of_elements(int *arr,int n)
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
                printf("%d: %d ",arr[i],count);
        }
        return;
}
/*
 47. Find maximum sum of k consecutive elements
Question description:
Write a C program to find maximum sum of k consecutive elements in an array.
Sample data:
Input: 2 3 4 1 5 6 7 k = 3
Expected output:
Maximum sum of 3 consecutive elements: 18
 */
void max_sum_of_consecutives(int *arr,int num)
{
        int i,j,k,sum=0,max_sum=0;
        printf("k = ");
        scanf("%d",&k);
        for(i=0;i<=num-k;i++)
        {
                for(j=0;j<k;j++)
                {
                        sum+=arr[i+j];
                }
                if(max_sum<sum)
                {
                        max_sum=sum;
                }
                sum=0;
        }
        printf("Maximum sum of %d consecutive elements: %d",k,max_sum);

}

/*
 48. Rotate array by k positions
Question description:
Write a C program to rotate the elements of an array by k positions to the right.
Sample data:
Input: 1 2 3 4 5 k = 2
Expected output:
Output: 4 5 1 2 3
 */
void rotate_by_k_times(int *arr,int num)
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
 50. Find the missing two numbers in an array
Question description:
Write a C program to find two missing numbers from an array containing numbers from 1 to n+2.
Sample data:
Input: 1 2 4 6
Expected output:
Missing numbers: 3 5
 */
void missing_numbers(int *arr,int num)
{
        int i,count;
        printf("Missing numbers:");
        for(i=0,count=1;i<num;i++,count++)
        {
                if(arr[i]==count)
                        continue;
                else
                {
                        printf(" %d",count);
                        count=arr[i];
                }
        }
        return;
}
/*
 49. Find longest consecutive sequence
Question description:
Write a C program to find the length of the longest consecutive elements sequence.
Sample data:
Input: 100 4 200 1 3 2
Expected output:
Longest consecutive sequence length: 4 (1, 2, 3, 4)
 */
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
        //print(arr,num);
        return;
}
void longest_consecutive_sequence(int *arr,int num)
{
        ascending_sort(arr,num);
        for(i=0;i<num-1;i++)
        {
                for(j=i;i<num;i++)

        }
}
int main()
{
        int arr[20],num;
        printf("Enter the number of elements : ");
        scanf("%d",&num);
        printf("Array:");
        for(int i=0;i<num;i++)
                scanf("%d",arr+i);
        sum_close_to_zero(arr,num);
        isPalindrome(arr,num);
        majority_element(arr,num);
        equilibrium_index(arr,num);
        sort_array(arr,num);
        second_smallest(arr,num);
        product(arr,num);
        max_difference(arr,num);
        count_occurrence(arr,num);
        all_zeros_last(arr,num);
        max_sum_of_consecutives(arr,num);
        frequency_of_elements(arr,num);
        rotate_by_k_times(arr,num);
        missing_numbers(arr,num);
        return 0;
}
