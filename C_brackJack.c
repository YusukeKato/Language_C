/*
 * BLACK JACK
 * C
 * 2016.
 * 2016.5.11
 */

/*
 * Ace 1or11 �ł���
 * �|�����ݒ� �ł���
 * 11-13 �� 10 �ł���
 * �Ƃ肠������{�@�\�͊���
 * �����ɑΉ����ăf�B�[���[���b�������Ă���
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterkey(void);

/* �u���b�N�W���b�N */
int main(void)
{
	int pRand[100];
	int eRand[100];
	int i,j,q=1,qq=1,qqq=1;
	int pSum,eSum;
	int sum;
	int sele;
	int sele_2;
	int money = 10000;
	int bed_money = 0;
	int aceNum = 0;//Ace�̔z��ԍ���ۑ�
	int flag_ace = 0;//flag_ace = 1 �� Ace = 11
	int flag_money = 0;
	
	while(qq!=0){
		for(i=0; i<100; i++){
			pRand[i] = 0;
			eRand[i] = 0;
		}
		system("cls");
		printf( "\n �u���b�N�W���b�N\n"
				"\n ���v�Q�P���߂����I�I\n"
				"\n ��������Q�{�I�I�I\n"
				);
		printf( "\n Enterkey\n");
		enterkey();
		printf( "\n �����F%d \n",money);
		printf( "\n �|��������͂��Ă�������\n"
				"\n ���́F"
				);
		scanf("%d",&bed_money);
		if(bed_money > money){
			printf("\n ����������܂���E�E�E�E�E�E\n");
			break;
		}
		enterkey();
		printf( "\n �������F%d\n"
				"\n �|�����F%d\n"
				, money, bed_money
				);
		printf( "\n �Q�[���ŗV�т܂����H\n"
				"\n 1.�V��\n"
				"\n 2.�V�΂Ȃ�\n"
				);
		printf( "\n ���́F");
		scanf( "%d",&sele);
		switch(sele){
			case 1:
				q = 1;
				for(i=0; q!=0; ++i){
					system("cls");
					srand((unsigned)time(NULL));
					pRand[i] = rand()%13 + 1;
					/* 11����13�̏��� */
					if(pRand[i]>=10&&pRand[i]<=13) pRand[i] = 10;
					/* Ace�̏��� */
					if(pRand[i] == 1){
						aceNum = i;
						printf("\n Ace(1or11)\n");
						pRand[i] = 11;
						flag_ace = 1;
						sum = 0;
						for(j=0; pRand[j]!='\0'; j++){
							sum += pRand[j];
						}//for
						if(sum > 21){
							pRand[i] = 1;
							flag_ace = 0;
						}//if
					}
					if(i<2){
						printf( "\n %d�ڂ̒l�F%d \n",i+1 ,pRand[i]);
					} else if(i>=2){
						printf( "\n %d�ڂ̒l�F%d \n",i+1 ,pRand[i]);
					}
					sum = 0;
					for(j=0; pRand[j]!='\0'; j++){
						sum += pRand[j];
					}
					if(sum > 21&&flag_ace==1){
						printf("\n Ace 11 �� 1\n");
						pRand[aceNum] = 1;
						sum -= 10;
						flag_ace = 0;
					}
					pSum = sum;
					if(i<2) {
						printf( "\n ���v�F%d \n",pSum);
					} else if(i>=2) {
						printf( "\n ���v�F%d \n",pSum);
					}
					printf( "\n ���̒l�ŏ������܂����H\n"
							"\n 1.��������\n"
							"\n 2.�܂�����Ȃ�\n"
							);
					printf( "\n ���́F");
					scanf("%d",&sele_2);
					switch(sele_2){
						case 1:
							q = 0;
							break;
						case 2:
							system("cls");
							printf( "\n �G���^�[�L�[������\n");
							enterkey();
							break;
						default:
						exit(0);
					}
				}
				qqq = 1;
				for(i=0; qqq!=0; i++){
					srand((unsigned)time(NULL));
					eRand[i] = rand()%13 + 1;
					if(pRand[i]>=10&&pRand[i]<=13) pRand[i] = 10;
					printf( "\n �����%d�ڂ̒l�F%d \n",i+1,eRand[i]);
					sum = 0;
					for(j=0; eRand[j]!='\0'; j++){
						sum += eRand[j];
					}
					eSum = sum;
					enterkey();
					if(eSum>17&&eSum<=21){
						qqq = 0;
					} else if(eSum>21) {
						eSum = 16;
						qqq = 0;
					}
				}
				printf( "\n �����F%d	����F%d \n",pSum ,eSum);
				if(pSum==eSum||pSum>21||((eSum>=1&&eSum<=21)&&eSum>pSum)){
					printf( "\n===============\n"
							"\n ����\n"
							"\n===============\n"
							);
					money -= bed_money;
				} else {
					printf( "\n===============\n"
							"\n ����\n"
							"\n===============\n"
							);
					money += bed_money;
				}
				enterkey();
				break;
			case 2:
				qq = 0;
				break;
			default:
				exit(0);
		}
		printf(" \nEnterkey\n");
		enterkey();
		/* �f�B�[���[�����C�x���g */
		if(money >= 20000&&flag_money == 0){
			printf("\n �f�B�[���[�u�܂��܂����ˁv\n");
			flag_money = 1;
		} else if(money >= 50000&&flag_money == 1){
			printf("\n �f�B�[���[�u�Ȃ��Ȃ����ˁI�v\n");
			flag_money = 2;
		} else if(money >= 100000&&flag_money == 2){
			printf("\n �f�B�[���[�u�����܂ł���Ƃ́E�E�E�E�E�E�v\n");
			flag_money = 3;
		} else if(money >= 400000&&flag_money == 3){
			printf("\n �f�B�[���[�u������A�l�Ԃ���Ȃ��ȁH�v\n");
			flag_money = 4;
		} else if(money >= 1000000&&flag_money == 4){
			printf("\n �f�B�[���[�u������߂悤���v\n");
			flag_money = 5;
		} else if(money >= 2000000&&flag_money == 5){
			printf("\n �f�B�[���[�u�ق�Ƃɂ�����߂悤�v\n");
			flag_money = 6;
		} else if(money >= 5000000&&flag_money == 6){
			printf("\n �f�B�[���[�u�����I��肾�B�����͂������v\n");
			flag_money = 7;
		} else if(money >= 10000000&&flag_money == 7){
			printf("\n �f�B�[���[�u�I���E�E�E�E�E�E�v\n");
			exit(0);
		}
	}//while
	return 0;
}

void enterkey(void)
{
	char c;
	c = getchar();
	system("cls");
}