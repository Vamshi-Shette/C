#include<stdio.h>

/*
 Write a program to perform the following operations on the Least and Most Significant Bits (LSB/MSB) of a given integer:
Set the LSB to 1
Clear the LSB (set to 0)
Toggle the LSB
Set the MSB to 1
Clear the MSB (set to 0)
Toggle the MSB
Set a specific bit to 1
Clear a specific bit
Toggle a specific bit
 */

void set_lsb(int *num)
{
	(*num)=(*num)|1;
	return;
}

void clear_lsb(int *num)
{
        (*num)=(*num)&~1;
        return;
}
void toggle_lsb(int *num)
{
        (*num)=(*num)^1;
        return;
}

void set_msb(int *num)
{
        (*num)=(*num)|(1<<31);
        return;
}

void clear_msb(int *num)
{
        (*num)=(*num)&~(1<<31);
        return;
}
void toggle_msb(int *num)
{
        (*num)=(*num)^(1<<31);
        return;
}

void set_bit(int *num)
{
	int bit_position;
	scanf("%d",&bit_position);
        (*num)=(*num)|(1<<bit_position);
        return;
}

void clear_bit(int *num)
{
	int bit_position;
        scanf("%d",&bit_position);

        (*num)=(*num)&~(1<<bit_position);
        return;
}
void toggle_bit(int *num)
{
	int bit_position;
        scanf("%d",&bit_position);

        (*num)=(*num)^(1<<bit_position);
        return;
}

 /*
 *Write a program to modify specific portions of a given integer:
Set all bits in the Least Significant Byte (LSB) to 1
Set all bits in the Most Significant Byte (MSB) to 1
Set all bits in the Least Significant Nibble to 1
Set all bits in the Most Significant Nibble to 1
Set n bits to 1 (user input)
Clear n bits (set to 0), with n as input
Toggle n bits (user input)
*/

void set_LSByte(int *num)
{       
	(*num)=(*num)|0xff;
        return;

}    

void set_MSByte(int *num)
{
        (*num)=(*num)|(0xff<<24);
        return;
}

void set_LSNibble(int *num)
{
        (*num)=(*num)|0x0f;
        return;

}

void set_MSNibble(int *num)
{
        (*num)=(*num)|(0xf<<28);
        return;
}

void set_n_bits(int *num)
{
        int bits;
        scanf("%d",&bits);
	for(int i=0;i<bits;i++)
        	(*num)=(*num)|(1<<i);
	//or (*num)=(*num)|(pow(2,bits)-1);
        return;
}

void clear_n_bits(int *num)
{
        int bits;
        scanf("%d",&bits);
	for(int i=0;i<bits;i++)
        	(*num)=(*num)&~(1<<i);
	//or (*num)=(*num)&~(pow(2,bits)-1);

        return;
}
void toggle_n_bits(int *num)
{
        int bits;
        scanf("%d",&bits);
	for(int i=0;i<bits;i++)
        	(*num)=(*num)^(1<<i);
	//or (*num)=(*num)^(pow(2,bits)-1);

        return;
}

/*
 Write a program to check bit status in an integer:
Check if LSB is set (1) or not (0)
Check if MSB is set (1) or not (0)
Check if the nth bit is set (1) or not (0) (user input)
 */
void check_lsb(int *num)
{
	if((*num)&1)
		printf("LSB is set\n");
	else
		printf("LSB is clear\n");
	return;
}

void check_msb(int *num)
{
        if( ( (*num)>>31)&1)
                printf("MSB is set\n");
        else
                printf("MSB is clear\n");
        return;
}

void check_nth_bit(int *num)
{
	int bit_position;
        scanf("%d",&bit_position);
	if( ( (*num)>>bit_position)&1)
                printf("nth bit is set\n");
        else
                printf("nth bit is clear\n");
        return;


}

/*
 Write a C program to count the number of set bits in an unsigned integer.
 */
void count_no_of_set_bits(int num)
{
	int count=0;
	for(int i=0;i<32;i++)
		if( (num>>i)&1)
			count++;
	printf("No of set bits are: %d",count);
	return;
}

/*
 Write a C program to check whether a number is a power of 2 using bitwise operations.
 */

void check_the_number(int num)
{
	int count=0;
        for(int i=0;i<32;i++)
                if( (num>>i)&1)
                        count++;
	if(count==1)
        	printf("Yes, the given number is a power of 2\n");
	else
		printf("No");
        return;
}

/*
 Write a C program to determine whether a number is odd or even using bitwise operators.
 */
void check_odd_or_even(int num)
{
	if(num&1)
		printf("number is odd\n");
	else
		printf("number is even\n");
	return;

}

/*
 Implement the function setbits(x, p, n, y) that sets n bits in x starting at position p with the rightmost n bits of y.
 */
//void setbits()
//Given two integers A and B, write a program to count the number of bits that need to be flipped to convert A into B
void bit_flip_compare(int num1)
{
	int num2,count=0;
	scanf("%d"&num2);
	for(int i=0;i<32;i++)
	{
		if( ((num1>>i)&1)!=((num2>>i)&1) )
			count++;
	}
	printf("%d flips are needed\n",count);
	return;
}

//Write a program to reverse all bits in an integer.
void reverse_all_bits(int num)
{
	unsigned int reverse=0;
	for(int i=0;i<32;i++)
	{
		reverse=reverse|( ((num>>i)&1) <<(31-i));
	}
	printf("%d",reverse);
	return;
}

/*
 Write a program to reverse:
Bits at odd positions
Bits at even positions
 */
void reverse_odd_bits(int num)
{
	unsigned int result = num;
	int left = 1;        // first odd position
	int right = 31;      // last possible odd position
    while (left < right)
    {
        // extract bits
        unsigned int bit1 = (num >> left) & 1;
        unsigned int bit2 = (num >> right) & 1;

        // if bits differ, swap them
        if (bit1 != bit2)
        {
            result ^= (1 << left);
            result ^= (1 << right);
        }

        left += 2;
        right -= 2;
    }
    printf("%d",result);
    return;
}

void reverse_even_bits(int num)
{
        unsigned int result = num;
        int left = 0;        // first odd position
        int right = 30;      // last possible odd position
    while (left < right)
    {
        // extract bits
        unsigned int bit1 = (num >> left) & 1;
        unsigned int bit2 = (num >> right) & 1;

        // if bits differ, swap them
        if (bit1 != bit2)
        {
            result ^= (1 << left);
            result ^= (1 << right);
        }

        left += 2;
        right -= 2;
    }
    printf("%d",result);
    return;
}

//Write a program to multiply a number by 9 using bitwise shift operations
void multiple_of_9(int num)
{
	printf("%d",(num<<3)+num);
	return;

}
//Write a program to determine the size (in bits) of an integer using bit shifts.
void size_of_int()
{
    unsigned int x = 1;
    int count = 0;
    while (x != 0)
    {
        x = x << 1;
        count++;
    }
    printf("Size of unsigned int = %d bits\n", count);
    return;
}

//Write a program to convert a Little Endian integer to its Big Endian equivalent.
void little_endian_to_big_endian(int num)
{
	int result=0;
	res=( ( (num>>24)&&0x000000ff)| ((num>>8)&&0x0000ff00)| ((num<<8)&&0x00ff00000)| ((num<<24)&&0xff000000) );
	printf("%d",result);
	return;
}

int main()
{
	int num;
	scanf("%d",&num);
	set_bit(&num);
        clear_bit(&num);
        toggle_bit(&num);
	set_lsb(&num);
	clear_lsb(&num);
	toggle_lsb(&num);
	set_msb(&num);
	clear_msb(&num);
        toggle_msb(&num);
	set_bit(&num);
 	clear_bit(&num);
        toggle_bit(&num);

	set_MSByte(&num);
	set_LSByte(&num);
	set_MSNibble(&num);
	set_MSNibble(&num);
	set_n_bits(&num);
	clear_n_bits(&num);
	toggle_n_bits(&num);

	check_lsb(&num);
	check_msb(&num);
	check_nth_bit(&num);

	count_no_of_set_bits(num);
	check_the_number(num);
	

	return 0;
}
