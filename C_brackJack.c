/*
 * YusukeKato
 * BLACK_JACK
 * C
 * 2016.3.
 * 2016.5.11
 */
 
/*
 * �Q�[���̎�ނ𑝂₷
 */

/*
 * Ace 1or11 �ł���
 * �|�����ݒ� �ł���
 * 11-13 �� 10 �ł���
 * �Ƃ肠������{�@�\�͊��� �ł���
 * �����ɑΉ����ăf�B�[���[���b�������Ă��� �ł���
 * �s��͂����������� �ł���
 * ���v��21�𒴂����ꍇ�͏I�������� �ł���
 * 2����21�ɂȂ�����[!!BRACKJACK!!]��\������ �ł���
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void high_low(int *, int *);//�n�C�����[�֐�
void janken(int *, int *);//����񂯂�֐�
void enterkey(void);//enterkey�����̂��߂̊֐�

/* �u���b�N�W���b�N */
int main(void)
{
	int pRand[100];//player�̈���������������
	int eRand[100];//enemy�̂Ђ�������������
	int i,j,q=1,qq=1,qqq=1;//loop�Ŏg��i,j�Aloop����q,qq,qqq
	int pSum,eSum;//���v
	int sum;//�ꎞ�I�ȍ��v�̕ۑ��ꏊ
	int sele;//select�A����O��scanf�œǂݎ��
	int sele_2;//select2
	int money = 10000;//������
	int bed_money = 0;//�|����
	int aceNum = 0;//Ace�̔z��ԍ���ۑ�
	int flag_ace = 0;//flag_ace = 1 �� Ace = 11
	int flag_money = 0;//�f�B�[���[�C�x���g�A�����ɉ�����
	int flag_21 = 0;//21�𒴂�����I��
	int flag_game = 1;//game�̎�ނ����߂�
	
	while(qq!=0){//��ԑ傫��while���[�v
		for(i=0; i<100; i++){//�z��̏������A���̕��@������
			pRand[i] = 0;
			eRand[i] = 0;
		}
		enterkey();//enterkey�����֐�
		/* �Q�[������ */
		printf( "\n ���u���b�N�W���b�N��\n"
				"\n ���v�Q�P���߂����I�I\n"
				"\n ��������Q�{�I�I�I\n"
				);
		printf( "\n ������񂯂�\n"
				"\n �������ĕ��ʂ̂���񂯂�\n"
				"\n ��������R�{�I�I�I\n"
				);
		printf( "\n ���n�C�����[��\n"
				"\n �傫�������������I�ׁI�I\n"
				"\n �����Ƃɔ{�I�I�I\n"
				);
		enterkey();
		/* �Q�[�������邩�ǂ��� */
		printf( "\n �f�B�[���[�u�V��ł������H�v\n"
				"\n 1.�V��\n"
				"\n 2.�V�΂Ȃ�\n"
				);
		printf( "\n ���́F");
		scanf( "%d",&sele);
		enterkey();
		/* �Q�[����I�� */
		if(sele == 1){
			printf( "\n �f�B�[���[�u�ǂ�ɂ���H�v\n"
					"\n 1.BRACKJACK\n"
					"\n 2.BRACKJACK 1���ډB��\n"
					"\n 3.BRACKJACK 3���ڂ���B��\n"
					"\n 4.����񂯂�\n"
					"\n 5.�n�C�����[\n"
					"\n ���́F"
					);
			scanf("%d",&flag_game);
			enterkey();
		}//if
		if(!(flag_game==1||flag_game==2||flag_game==3||flag_game==4||flag_game==5)){
			printf("\n �f�B�[���[�u����͂Ȃ����v\n");
			exit(0);
		}//if
		if(sele == 1){//�Q�[��������Ƃ�����
			printf("\n �f�B�[���[�u���Ə������v\n");
			/* �|�����ݒ� */
			printf( "\n �����F%d \n",money);
			printf( "\n �f�B�[���[�u�|���������߂ȁv\n"
					"\n ���́F"
					);
			scanf("%d",&bed_money);
			if(bed_money > money){
				printf("\n �f�B�[���[�u��������Ȃ����v\n");
				break;
			}
			enterkey();
			printf( "\n �������F%d\n"
					"\n �|�����F%d\n"
					,money, bed_money
					);
		}//if
		/* ����񂯂� */
		if(sele == 1&&flag_game == 4)
			sele = 3;
		/* �n�C�����[ */
		if(sele == 1&&flag_game == 5)
			sele = 4;
			
		switch(sele){
			case 1:
				q = 1;
				for(i=0; q!=0; ++i){
					system("cls");
					/* 1�`13�̂��������_���ŏo�� */
					srand((unsigned)time(NULL));
					pRand[i] = rand()%13 + 1;//�z��ɓ����
					/* 11����13�̏��� */
					if(pRand[i]>=10&&pRand[i]<=13) pRand[i] = 10;//1�`13��10�ɂ���
					/* Ace�̏��� */
					if(pRand[i] == 1){
						aceNum = i;//Ace���z��̂ǂ��ɓ��������ۑ�
						if(flag_game == 1||(flag_game == 2||i < 2)||(flag_game == 3&&i != 0))
							printf("\n Ace(1or11)\n");
						pRand[i] = 11;
						flag_ace = 1;//11�̎��̓t���O�𗧂Ă�
						/* player�̍��v�����߂� */
						sum = 0;
						for(j=0; pRand[j]!='\0'; j++){
							sum += pRand[j];
						}//for
						if(sum > 21){//21�����Ă�����A1�ɂ���
							pRand[i] = 1;
							flag_ace = 0;//(1or11)1�̎��̓t���O��0
						}//if
					}//if
					/* 2����21�Ȃ�BRACKJACK */
					if(i==1&&(pRand[0]==11&&pRand[1]==10||pRand[0]==10&&pRand[1]==11)){
						system("cls");
						printf( "\n--------------------------------------------------\n"
								"\n		!!!!! BRACK JACK !!!!!\n"
								"\n--------------------------------------------------\n"
								);
						enterkey();
					}//if
					/* 3�ڂ̐�������B���ꍇ�͂��������p���� */
					if(flag_game == 1)
						printf( "\n %d�ڂ̒l�F%d \n",i+1 ,pRand[i]);
					else if(flag_game == 2){
						if(i == 0)
							printf("\n %d�ڂ̒l�F��\n",i+1);
						else
							printf( "\n %d�ڂ̒l�F%d \n",i+1 ,pRand[i]);
					}//else_if
					else if(flag_game == 3){
						if(i < 2)
							printf( "\n %d�ڂ̒l�F%d \n",i+1 ,pRand[i]);
						else
							printf("\n %d�ڂ̒l�F��\n",i+1);
					}//else_if
							
					sum = 0;
					for(j=0; pRand[j]!='\0'; j++){
						sum += pRand[j];
					}
					/* ���v��21�𒴂��āA���A���ł�Ace�������Ă����ꍇ */
					if(sum > 21&&flag_ace==1){
						if(flag_game == 1)
							printf("\n Ace 11 �� 1\n");
						pRand[aceNum] = 1;//11��1�ɂ���
						sum -= 10;//Ace��11����1�ɕς������A���v��10���炷
						flag_ace = 0;//�t���O������
					}
					if(sum > 21&&flag_game == 1){
						printf("\n ���v�F%d\n",sum);
						printf("\n ���v���Q�P���z���Ă��܂����E�E�E�E�E�E\n");
						flag_21 = 1;
						q = 0;
						enterkey();
					}//if
					pSum = sum;//���v���ڂ��A���邩�ǂ����͍l����
					if(flag_21 == 0){
						if(flag_game == 1||(flag_game==3&&i<2))
							printf( "\n ���v�F%d \n",pSum);
						else
							printf("\n ���v�F��\n");
						printf( "\n ���̒l�ŏ������܂����H\n"
								"\n 1.��������\n"
								"\n 2.�܂�����Ȃ�\n"
								);
						printf( "\n ���́F");
						scanf("%d",&sele_2);
						switch(sele_2){
							case 1:
								q = 0;//���[�v�I��
								break;
							case 2:
								system("cls");//<windows.h>��ʃN���A
								enterkey();
								break;
							default:
								exit(0);
						}//switch
					}//if_flag_21
				}//for�傫��
				qqq = 1;//�G�̃��[�v����
				for(i=0; qqq!=0; i++){
					srand((unsigned)time(NULL));
					eRand[i] = rand()%13 + 1;
					if(eRand[i]>=10&&eRand[i]<=13) eRand[i] = 10;
					if(flag_21 == 0){//player��21���z���Ă����ꍇ�\�����Ȃ�
						printf( "\n �����%d�ڂ̒l�F%d \n",i+1,eRand[i]);
					}
					sum = 0;
					for(j=0; eRand[j]!='\0'; j++){
						sum += eRand[j];
					}
					eSum = sum;
					if(eSum>17&&eSum<=21){
						qqq = 0;//���������Ȃ�
					} else if(eSum>21) {
						eSum = 16;
						qqq = 0;//���������Ȃ�
					}
				}
				enterkey();
				printf( "\n �����F%d	����F%d \n",pSum ,eSum);
				if(pSum==eSum||pSum>21||((eSum>=1&&eSum<=21)&&eSum>pSum)){//player�����̏���
					printf( "\n===============\n"
							"\n ����\n"
							"\n===============\n"
							);
					printf("\n �f�B�[���[�u���̏������ȁv\n");
					money -= bed_money;//�|����������
				} else {//�����ȊO����
					printf( "\n===============\n"
							"\n ����\n"
							"\n===============\n"
							);
					printf("\n �f�B�[���[�u������͂����܂ł��E�E�E�E�E�E�v\n");
					money += bed_money;//2�{�ɑ�����
				}
				enterkey();
				break;
			case 2:
				printf("\n �f�B�[���[�u�܂�������v\n");
				qq = 0;
				break;
			case 3:
				janken(&money,&bed_money);
				break;
			case 4:
				high_low(&money, &bed_money);
				break;
			default:
				exit(0);
		}
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
			exit(0);//�������I��
		}
	}//while
	return 0;
}

/* ����񂯂�֐� */
void janken(int *money, int *bed_money)
{
	int ran;
	int sele;
	int q;
	char c;
	
	while(q!=0){
		enterkey();
		printf("\n �f�B�[���[�u�����o�������ȁv\n");
		printf( "\n 1.���[\n"
				"\n 2.�ρ[\n"
				"\n 3.���傫\n"
				"\n ���́F"
				);
		scanf("%d",&sele);
		c = getchar();//���͂̂Ƃ���enterkey����
		enterkey();
	
		srand((unsigned)time(NULL));
		ran = rand()%3 + 1;
		
		printf("\n �����F%d	����F%d \n",sele ,ran);
		
		if(sele==ran){
			printf( "\n --- �������� ---\n");
			printf("\n �f�B�[���[�u���������v\n");
		} else if((sele==1&&ran==3)||(sele==2&&ran==1)||(sele==3&&ran==2)) {
			printf("\n !!! ������ !!!\n\n");
			printf("\n �f�B�[���[�u�܂��܂����ꂩ�炾�v\n");
			*money += *bed_money * 2;
			q = 0;
		} else {
			printf("\n ����......\n\n");
			printf("\n �f�B�[���[�u����ɂȂ�Ȃ��ȁv\n");
			*money -= *bed_money;
			q = 0;
		}
	}
}

/* �n�C�����[ */
void high_low(int *money, int *bed_money)
{
	int q;
	int sele;
	int sele_p;
	int ran;
	int ran_p;
	int i = 0;
	char c;
	
	while(q!=0){
		if(*money < *bed_money){
			for(;*money < *bed_money;){
				printf("\n ��������˂���\n");
				printf("\n �|�������́F");
				scanf("%d",*bed_money);
				enterkey();
			}
		}//if
		i += 1;
		printf( "\n �����F%d \n"
				"\n �u�n�C�����[�v(%d���)\n"
				"\n �|�����F%d�~\n"
				"\n ��������%d�{�I�I\n"
				"\n 1.�V��\n"
				"\n 2.��߂Ă���\n"
				"\n ���́F"
				,*money ,i ,i * *bed_money,i*2
				);
		scanf( "%d",&sele);
		enterkey();
		switch(sele){
			case 1:
				printf( "\n �u�n�C�����[�v\n"
						"\n ��ƂȂ鐔���ɑ΂���\n"
						"\n �����̐������傫���������������Ă�\n"
						"\n ���͂P�`�P�O\n"
						);
				enterkey();
				srand((unsigned)time(NULL));
				ran = rand()%9 + 1;
				if(ran == 1) ran = 5;
				printf( "\n\n ��ƂȂ鐔���F%d \n",ran);
				enterkey();
				srand((unsigned)time(NULL));
				ran_p = rand()%10 + 1;
				printf( "\n ���Ȃ��̐����F�� \n");
				enterkey();
				printf( "\n ���Ȃ��̐����� %d ����H���H�i1�`10�j\n"
						"\n 1.��\n"
						"\n 2.��\n"
						"\n ���́F"
						,ran
						);
				scanf("%d",&sele_p);
				system("cls");
				printf( "\n ��ƂȂ鐔���F%d \n"
						"\n ���Ȃ��̐����F%d \n"
						,ran ,ran_p
						);
				enterkey();
				if((ran>ran_p)&&sele_p==2) {
					printf( "\n==============\n"
							"\n   ����\n"
							"\n==============\n"
							);
					printf("\n �f�B�[���[�u���q��������˂����v\n");
					*money += (i * *bed_money)*(i*2);
				} else if((ran<ran_p)&&sele_p==1) {
					printf( "\n==============\n"
							"\n   ����\n"
							"\n==============\n"
							);
					printf("\n �f�B�[���[�u�Ȃ��Ȃ���邶��˂����v\n");
					*money += (i * *bed_money)*(i*2);
				} else if(ran==ran_p) {
					printf( "\n �����������Ȃ畉��\n");
					printf( "\n==============\n"
							"\n   ����\n"
							"\n==============\n"
							);
					printf("\n �f�B�[���[�u�ǂ������H ����Ȃ��񂩁H�v\n");	
					*money -= i * *bed_money * (i*2);
					i = 0;
				} else {
					printf( "\n==============\n"
							"\n   ����\n"
							"\n==============\n"
							);
					printf("\n �f�B�[���[�u���q�����񂶂�˂����H�v\n");
					*money -= i * *bed_money * (i*2);
					i = 0;
				}
				if(*money <= 0){
					printf("\n �f�B�[���[�u�����Ȃ��Ȃ�A��ȁv\n");
					exit(0);
				}//if
				break;
			case 2:
				q = 0;
				break;
			default:
				break;
		}
	}
}

/* enterkey���� */
void enterkey(void)
{
	char c;
	printf("\n Enterkey\n");
	c = getchar();
	system("cls");
}