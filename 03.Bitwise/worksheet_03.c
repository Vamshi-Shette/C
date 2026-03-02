#include<stdio.h>

/*
 1. Check Least Significant Bit (LSB) of a number is set or not
Question: Write a C program to check if the Least Significant Bit (LSB) of a number is set (1) or not.
Sample data: Input: 5 (binary 0101)
Expected output: LSB of 5 is set (1)
 */
void check_lsb(int *num)
{
        if((*num)&1)
                printf("LSB of %d is set\n",*num);
        else
                printf("LSB of %d is clear\n",*num);
        return;
}


/*
2. Check Most Significant Bit (MSB) of a number is set or not
Question: Write a C program to check if the Most Significant Bit (MSB) of a number is set (1) or not.
Sample data: Input: 128 (binary 10000000 for 8-bit number)
Expected output: MSB of 128 is set (1)
 */

void check_msb(int *num)
{
        if( ( (*num)>>31)&1)
                printf("MSB of %d is set\n",*num);
        else
                printf("MSB of %d is clear\n",*num);
        return;
}

/*
 3. Get nth bit of a number
Question: Write a C program to get the value of the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 2
Expected output: Bit 2 of 10 is 1
 */
void check_nth_bit(int *num)
{
        int bit_position;
        scanf("%d",&bit_position);
        if( ( (*num)>>bit_position)&1)
                printf("bit %d of %d is set\n",bit_position,*num);
        else
                printf("bit %d of %d is clear\n",bit_position,*num);
        return;


}

/*
 4. Set nth bit of a number
Question: Write a C program to set (make 1) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 1
Expected output: Number after setting bit 1: 10 (binary 1010) — no change
Input number: 8 (binary 1000), bit position: 0
Expected output: Number after setting bit 0: 9 (binary 1001)
 */
void set_nth_bit(int *num)
{
        int bit_position;
        scanf("%d",&bit_position);
        (*num)=(*num)|(1<<bit_position);
	printf("number after setting bit %d:%d\n",bit_position,*num);
        return;
}

/*
 5. Clear nth bit of a number
Question: Write a C program to clear (make 0) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 3
Expected output: Number after clearing bit 3: 2 (binary 0010)
 */
void clear_bit(int *num)
{
        int bit_position;
        scanf("%d",&bit_position);

        (*num)=(*num)&~(1<<bit_position);
    	printf("number after clearing bit %d:%d\n",bit_position,*num);
    	return;
}

/*
 6. Toggle nth bit of a number
Question: Write a C program to toggle (flip) the nth bit of a number.
Sample data: Input number: 10 (binary 1010), bit position: 1
Expected output: Number after toggling bit 1: 8 (binary 1000)
 */
void toggle_bit(int *num)
{
        int bit_position;
        scanf("%d",&bit_position);

        (*num)=(*num)^(1<<bit_position);
 	printf("number after toggling bit %d:%d\n",bit_position,*num);
 	return;
}

/*
 7. Get highest set bit of a number
Question: Write a C program to find the position of the highest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Highest set bit of 18 is at position 4 (zero-based)
 */
void highest_set_bit(int *num)
{
	int i;
	for( i=31;i>=0;i--)
		if((num>>i)&1)
			break;
	printf("Highest set bit of %d is at position %d",i,*num);
	return;

	/*
	 count=-1;
	 while(num>0)
	 {
	 	num=num>>1;
		count++;
	}
	*/
	return;
}

/*
  Get lowest set bit of a number
Question: Write a C program to find the position of the lowest set bit in a number.
Sample data: Input: 18 (binary 10010)
Expected output: Lowest set bit of 18 is at position 1 (zero-based)
 */
void lowest_set_bit(int *num)
{
        int i;
        count=-1;
	while(num>0)
	{
		if(num&1)
		{
			count++;
			break;
		}
		num=num>>1;
	}
        printf("lowest set bit of %d is at position %d",i,*num);
        return;
}

/*
 Count trailing zeros in a binary number
Question: Write a C program to count the number of trailing zeros in the binary representation of a number.
Sample data: Input: 40 (binary 101000)
Expected output: Number of trailing zeros: 3
 */
void count_trailing_zeros(int num)
{
	int count=0;

	if(num==0)
		printf("32\n");
	while(num&1==0)
	{
		count++;
		num=num>>1;
	}
	printf("Number of trailing zeros:%d",couunt);
	return;

}

/*
10. Count leading zeros in a binary number
Question: Write a C program to count the number of leading zeros in the binary representation of a number (assuming 32-bit integer).
Sample data: Input: 16 (binary 00000000000000000000000000010000)
Expected output: Number of leading zeros: 27
 */
void count_leading_zeros(int num)
{
        int count=0;
	int i;
        if(num==0)
                printf("32\n");
        for(i=31;i>=0;i++)
	{
		if((num>>i)&1)
			break;
		count++;
	}
			
        printf("Number of leading zeros:%d",couunt);
        return;

}

/*
 11. Flip bits of a binary number using bitwise operator
Question: Write a C program to flip all bits of a number using bitwise operators.
Sample data: Input: 5 (binary 00000101)
Expected output: Flipped bits: 250 (binary 11111010) (assuming 8-bit)
 */
void flip_bits(int num)
{
	flip_num=~(num);
	printf("%d",flip_num);
	return;
}

/*
 12. Count total zeros and ones in a binary number
Question: Write a C program to count the total number of zeros and ones in the binary representation of a number.
Sample data: Input: 15 (binary 00001111)
Expected output: Number of ones: 4, Number of zeros: 4 (assuming 8-bit)
 */
void count_zeors_ones(int num)
{
	int zeros=0,ones=0;
	for(int i=0;i<32;i++)
	{
		if((num>>i)&1)
			ones++;
		else
			zeros++;
	}
	printf("number of ones:%d, number of zeros:%d\n",ones,zeros);
	return ;

}	


/*
 13. Rotate bits of a given number
Question: Write a C program to rotate bits of a number to the left or right by a given number of positions.
Sample data: Input: number=16 (binary 00010000), rotate left by 2
Expected output: Result after rotation: 64 (binary 01000000)
 */
void rotate_bits(int num)
{
	unsigned num=num;
	int rotations;
	printf("r:rotate right l:rotate left\n");
	char ch;
	scanf(" %c",&ch);
	scanf("%d",&rotations);
	int bit=0;
	for(int i=1;i<=rotations;i++)
	{
		if(ch=='r')
		{
			bit=num&1;
			num=num>>1;
			num=num|(bit<<31);
		}
		else if(ch=='l')
		{
			bit=(num>>31)&1;
			num=num<<1;
			num=num|(bit);
		}
	}
	printf("result after rotation : %d",num);
	return;

}

/*
 14. Convert decimal to binary using bitwise operator
Question: Write a C program to convert a decimal number to binary representation using bitwise operators.
Sample data: Input: 13
Expected output: Binary representation: 1101
 */
void decimal_to_binary(int num)
{
	for(int i=31;i>=0;i--)
	{
		printf("%d",(num>>i)&1);
	}
	return;
}

/*
 15. Swap two numbers using bitwise operator
Question: Write a C program to swap two numbers using bitwise XOR operator without using a temporary variable.
Sample data: Input: a=5, b=9
Expected output: After swapping: a=9, b=5
 */
void swap(int a)
{
	int b;
	scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("After swappig:a=%d b=%d",a,b);
	return;

}

/*
 16. Check whether a number is even or odd using bitwise operator
Question: Write a C program to check whether a number is even or odd using bitwise AND operator.
Sample data: Input: 7
Expected output: 7 is odd
*/
void check_even_odd(int num)
{
	if(num&1)
		printf("odd\n");
	else
		printf("even\n");
	return;

}
int mian()
{
	int num;
        scanf("%d",&num);
	
	check_lsb(&num);
        check_msb(&num);
        check_nth_bit(&num);

	set_bit(&num);
        clear_bit(&num);
        toggle_bit(&num);

	highest_set_bit(&num);
	lowest_set_bit(&num);
	count_trailing_zeros(num);
	count_leading_zeros(num);
	flip_bits(num);
	count_zeors_ones(num);
	rotate_bits(num);
	decimal_to_binary(num);

	return 0;
}
