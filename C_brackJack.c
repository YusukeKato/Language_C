/*
 * BLACK JACK
 * C
 * 2016.
 * 2016.5.11
 */

/*
 * Ace 1or11 できた
 * 掛け金設定 できた
 * 11-13 → 10 できた
 * とりあえず基本機能は完成
 * お金に対応してディーラーが話しかけてくる
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterkey(void);

/* ブラックジャック */
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
	int aceNum = 0;//Aceの配列番号を保存
	int flag_ace = 0;//flag_ace = 1 → Ace = 11
	int flag_money = 0;
	
	while(qq!=0){
		for(i=0; i<100; i++){
			pRand[i] = 0;
			eRand[i] = 0;
		}
		system("cls");
		printf( "\n ブラックジャック\n"
				"\n 合計２１をめざせ！！\n"
				"\n 買ったら２倍！！！\n"
				);
		printf( "\n Enterkey\n");
		enterkey();
		printf( "\n お金：%d \n",money);
		printf( "\n 掛け金を入力してください\n"
				"\n 入力："
				);
		scanf("%d",&bed_money);
		if(bed_money > money){
			printf("\n お金が足りません・・・・・・\n");
			break;
		}
		enterkey();
		printf( "\n 所持金：%d\n"
				"\n 掛け金：%d\n"
				, money, bed_money
				);
		printf( "\n ゲームで遊びますか？\n"
				"\n 1.遊ぶ\n"
				"\n 2.遊ばない\n"
				);
		printf( "\n 入力：");
		scanf( "%d",&sele);
		switch(sele){
			case 1:
				q = 1;
				for(i=0; q!=0; ++i){
					system("cls");
					srand((unsigned)time(NULL));
					pRand[i] = rand()%13 + 1;
					/* 11から13の処理 */
					if(pRand[i]>=10&&pRand[i]<=13) pRand[i] = 10;
					/* Aceの処理 */
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
						printf( "\n %dつ目の値：%d \n",i+1 ,pRand[i]);
					} else if(i>=2){
						printf( "\n %dつ目の値：%d \n",i+1 ,pRand[i]);
					}
					sum = 0;
					for(j=0; pRand[j]!='\0'; j++){
						sum += pRand[j];
					}
					if(sum > 21&&flag_ace==1){
						printf("\n Ace 11 → 1\n");
						pRand[aceNum] = 1;
						sum -= 10;
						flag_ace = 0;
					}
					pSum = sum;
					if(i<2) {
						printf( "\n 合計：%d \n",pSum);
					} else if(i>=2) {
						printf( "\n 合計：%d \n",pSum);
					}
					printf( "\n この値で勝負しますか？\n"
							"\n 1.勝負する\n"
							"\n 2.まだ足りない\n"
							);
					printf( "\n 入力：");
					scanf("%d",&sele_2);
					switch(sele_2){
						case 1:
							q = 0;
							break;
						case 2:
							system("cls");
							printf( "\n エンターキー押して\n");
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
					printf( "\n 相手の%dつ目の値：%d \n",i+1,eRand[i]);
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
				printf( "\n 自分：%d	相手：%d \n",pSum ,eSum);
				if(pSum==eSum||pSum>21||((eSum>=1&&eSum<=21)&&eSum>pSum)){
					printf( "\n===============\n"
							"\n 負け\n"
							"\n===============\n"
							);
					money -= bed_money;
				} else {
					printf( "\n===============\n"
							"\n 勝ち\n"
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
		/* ディーラーお金イベント */
		if(money >= 20000&&flag_money == 0){
			printf("\n ディーラー「まずまずだね」\n");
			flag_money = 1;
		} else if(money >= 50000&&flag_money == 1){
			printf("\n ディーラー「なかなかやるね！」\n");
			flag_money = 2;
		} else if(money >= 100000&&flag_money == 2){
			printf("\n ディーラー「ここまでくるとは・・・・・・」\n");
			flag_money = 3;
		} else if(money >= 400000&&flag_money == 3){
			printf("\n ディーラー「もしや、人間じゃないな？」\n");
			flag_money = 4;
		} else if(money >= 1000000&&flag_money == 4){
			printf("\n ディーラー「もうやめようぜ」\n");
			flag_money = 5;
		} else if(money >= 2000000&&flag_money == 5){
			printf("\n ディーラー「ほんとにもうやめよう」\n");
			flag_money = 6;
		} else if(money >= 5000000&&flag_money == 6){
			printf("\n ディーラー「もう終わりだ。忠告はしたぞ」\n");
			flag_money = 7;
		} else if(money >= 10000000&&flag_money == 7){
			printf("\n ディーラー「終了・・・・・・」\n");
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