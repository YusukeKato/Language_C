/*
 * 2016.5.10
 * C
 */
 
/*
 * ������Ƃ����f�[�^�Ǘ�
 * 
 * dataBase[],in_s[],�錾���ɏ��������Ȃ���΂Ȃ�Ȃ�
 * 
 * �z��������ƒm��
 * 
 * "exit"�ŏI��
 */
 
#include <stdio.h>
#include <string.h>

#define MAXDATA 256

int main(void)
{
	char dataBase[MAXDATA] = {0};
	char in_str[MAXDATA] = {0};
	char c;
	int count = 0;
	int i;
	
	while(1){
		/* ��������� */
		for(i=0; (c=getchar())!=EOF&&c!='\n'; i++){
			in_str[i] = c;
		}//for1
		in_str[i] = '\0';
		
		if(strcmp(in_str, "exit")==0){
			printf("�I���E�E�E�E�E�E\n");
			break;
		}//if
	
		/* ���͂��ꂽ��������f�[�^�x�[�X�ɕۑ� */
		for(i=0; in_str[i]!='\0'; i++){
			dataBase[count+i] = in_str[i];
		}//for2
		
		count += i;/* dataBase[]�̍Ō���w�����߁A+=���厖 */
		
		/* �f�[�^�x�[�X�̒��g���o�� */
		for(i=0; dataBase[i]!='\0'; i++){
			printf("%c",dataBase[i]);
		}//for3
		printf("\n");
	}//while
	
	return 0;
}