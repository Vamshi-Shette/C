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


int main()
{
	int num;
	set_lsb(&num);
	clear_lsb(&num);
	toggle_lsb(&num);
	set_msb(&num);
	clear_msb(&num);
        toggle_msb(&num);
	set_bit(&num);
 	clear_bit(&num);
        toggle_bit(&num);

	return 0;
}
