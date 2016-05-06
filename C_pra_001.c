/*
 * 2016.5.6
 * C
 * —ûK‚P
 */
 
#include <stdio.h>

int func_1(int data_1, int data_2, int data_3)
{
	return data_1 + data_2 + data_3;
}

int func_2(int data_4, int data_5, int data_6)
{
	return data_4 + data_5 + data_6;
}

int func_3(int data_7, int data_8, int data_9)
{
	return data_7 + data_8 + data_9;
}

int func_4(int data_10, int data_11, int data_12)
{
	return data_10 + data_11 + data_12;
}

int main(void)
{
	int data;
	
	data = func_1(func_2(1,2,3),func_3(4,5,6), func_4(7,8,9));
	
	printf("%d\n",data);
	
	return 0;
}