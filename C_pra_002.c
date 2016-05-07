/* 
 * 2016.5.7
 * C
 */
 
/*
 * 再帰呼び出しを使って繰り返し
 */

#include <stdio.h>

int func_1(int );

int main(void)
{
	int data;
	
	scanf("%d",&data);
	
	func_1(data);
	
	return 0;
}

int func_1(int data)
{
	if(data <= 0)
		return 0;
	data -= 1;
	printf("%d\n",data);
	func_1(data);	//再帰呼び出し
}