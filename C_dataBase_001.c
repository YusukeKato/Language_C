/*
 * 2016.5.10
 * 2015.5.11
 * C
 */
 
/*
 * �Ƃ肠��������
 * ��肽�����Ƃ͂ł���
 */
 
/*
 * ������Ƃ����f�[�^�Ǘ�
 * 
 * �z��������ƒm��
 * 
 * "exit"�ŏI��
 */
 
/*
 * �g����
 * 1.����������
 * ��dataBase�ɓ��͂��ꂽ�����񂪕ۑ������
 * 		����ɁA���̕�����̕������A������̏��߂̔z��ԍ���ۑ�����
 * 
 * 2.�f�[�^�ԍ������
 * �����̃f�[�^�ԍ��ɊY������f�[�^�i������j���o�͂����
 * ���d�g�݂́A������̏��߂̔z��ԍ����當������for���ŌJ��Ԃ��ďo�͂��Ă���
 *
 *
 */
 
/*
 * ���
 * �E�z��ɂO��������Ȃ�
 * ��dataBase[1]�������n�߂�
 *
 * �E���낢�남������
 *
 * �EdataBase[],in_str[],�錾���ɏ��������Ȃ���΂Ȃ�Ȃ��̂��ǂ���
 */
 
#include <stdio.h>
#include <string.h>

#define MAXDATA 256
#define MAX_2 64

int main(void)
{
	char dataBase[MAXDATA] = {0};
	int dataPoint[MAX_2] = {0};
	int charNum[MAX_2] = {0};
	char in_str[MAXDATA] = {0};
	char c;
	int count = 0;
	int char_count = 0;
	int char_num = 0;
	int i = 0;
	int k = 0;
	int dataNum = 0;
	
	dataPoint[0] = 1;//��ԏ��߂��w��
	
	while(1){
		/* ��������� */
		printf("\n ���́i�f�[�^�j�F");
		for(i=0,char_count=0; (c=getchar())!=EOF&&c!='\n'; i++,char_count++){
			in_str[i] = c;
		}//for1
		in_str[i] = '\0';
		charNum[k] = char_count;//���������J�E���g���ĕۑ�
		dataPoint[k+1] = dataPoint[k] + i;//������̍ŏ����w�����߂ɕۑ�
		k += 1;
		
		if(strcmp(in_str, "exit")==0){
			printf("�I���E�E�E�E�E�E\n");
			break;
		}//if
	
		/* ���͂��ꂽ��������f�[�^�x�[�X�ɕۑ� */
		for(i=0; in_str[i]!='\0'; i++){
			dataBase[count+i+1] = in_str[i];
		}//for2
		
		count += i;/* dataBase[]�̍Ō���w�����߁A+=���厖 */
		
		/* �f�[�^�x�[�X�̒��g���o�� */
		printf("dataBase:");
		for(i=1; dataBase[i]!='\0'; i++){
			printf("%c",dataBase[i]);
		}//for3
		printf("\n");
		
		printf("dataPoint:");
		for(i=0; dataPoint[i]!='\0'; i++){
			printf("%d",dataPoint[i]);
		}//for4
		printf("\n");
		
		printf("charNum:");
		for(i=0; charNum[i]!='\0'; i++){
			printf("%d",charNum[i]);
		}//for5
		printf("\n");
		
		/* �f�[�^���o�� */
		printf("\n ���́i�f�[�^�ԍ��j�F");
		scanf("%d",&dataNum);
		printf("\n");
		for(i = 0; i < charNum[dataNum]; i++){
			printf("%c",dataBase[dataPoint[dataNum] + i]);
		}//for6
		printf("\n");
		
		c = getchar();//�G���^�[�L�[����
		
	}//while
	
	return 0;
}