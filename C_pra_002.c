/* 
 * 2016.5.7
 * C
 */
 
/*
 * �ċA�Ăяo�����g���ČJ��Ԃ�
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
	func_1(data);	//�ċA�Ăяo��
}