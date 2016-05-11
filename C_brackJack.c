/*
 * YusukeKato
 * BLACK JACK
 * C
 * 2016.3.
 * 2016.5.11
 */

/*
 * Ace 1or11 できた
 * 掛け金設定 できた
 * 11-13 → 10 できた
 * とりあえず基本機能は完成
 * お金に対応してディーラーが話しかけてくる
 * 不具合はだいたい直した
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterkey(void);//enterkey処理のための関数

/* ブラックジャック */
int main(void)
{
	int pRand[100];//playerの引いた数字を入れる
	int eRand[100];//enemyのひいた数字を入れる
	int i,j,q=1,qq=1,qqq=1;//loopで使うi,j、loop条件q,qq,qqq
	int pSum,eSum;//合計
	int sum;//一時的な合計の保存場所
	int sele;//select、分岐前のscanfで読み取る
	int sele_2;//select2
	int money = 10000;//所持金
	int bed_money = 0;//掛け金
	int aceNum = 0;//Aceの配列番号を保存
	int flag_ace = 0;//flag_ace = 1 → Ace = 11
	int flag_money = 0;//ディーラーイベント、お金に応じて
	
	while(qq!=0){//一番大きいwhileループ
		for(i=0; i<100; i++){//配列の初期化、他の方法がある
			pRand[i] = 0;
			eRand[i] = 0;
		}
		enterkey();//enterkey処理関数
		/* ゲーム説明 */
		printf( "\n ブラックジャック\n"
				"\n 合計２１をめざせ！！\n"
				"\n 買ったら２倍！！！\n"
				);
		enterkey();
		/* ゲームをするかどうか */
		printf( "\n ゲームで遊びますか？\n"
				"\n 1.遊ぶ\n"
				"\n 2.遊ばない\n"
				);
		printf( "\n 入力：");
		scanf( "%d",&sele);
		if(sele == 1){//ゲームをするときだけ
			/* 掛け金設定 */
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
					,money, bed_money
					);
		}//if
		switch(sele){
			case 1:
				q = 1;
				for(i=0; q!=0; ++i){
					system("cls");
					/* 1～13のうちランダムで出す */
					srand((unsigned)time(NULL));
					pRand[i] = rand()%13 + 1;//配列に入れる
					/* 11から13の処理 */
					if(pRand[i]>=10&&pRand[i]<=13) pRand[i] = 10;//1～13を10にする
					/* Aceの処理 */
					if(pRand[i] == 1){
						aceNum = i;//Aceが配列のどこに入ったか保存
						printf("\n Ace(1or11)\n");
						pRand[i] = 11;
						flag_ace = 1;//11の時はフラグを立てる
						/* playerの合計を求める */
						sum = 0;
						for(j=0; pRand[j]!='\0'; j++){
							sum += pRand[j];
						}//for
						if(sum > 21){//21超えていたら、1にする
							pRand[i] = 1;
							flag_ace = 0;//1の時はフラグは0
						}//if
					}
					/* 3つ目の数字から隠す場合はここを活用する */
					if(i<2){
						printf( "\n %dつ目の値：%d \n",i+1 ,pRand[i]);
					} else if(i>=2){
						printf( "\n %dつ目の値：%d \n",i+1 ,pRand[i]);
					}
					sum = 0;
					for(j=0; pRand[j]!='\0'; j++){
						sum += pRand[j];
					}
					/* 合計が21を超えて、かつ、すでにAceを引いていた場合 */
					if(sum > 21&&flag_ace==1){
						printf("\n Ace 11 → 1\n");
						pRand[aceNum] = 1;//11を1にする
						sum -= 10;//Aceを11から1に変えた分、合計を10減らす
						flag_ace = 0;//フラグを下す
					}
					pSum = sum;//合計を移す、いるかどうかは考える
					/* 3つ目の数字から合計の値を隠す場合はここを活用する */
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
							system("cls");//<windows.h>画面クリア
							enterkey();
							break;
						default:
						exit(0);
					}
				}
				qqq = 1;//敵のループ条件
				for(i=0; qqq!=0; i++){
					srand((unsigned)time(NULL));
					eRand[i] = rand()%13 + 1;
					if(eRand[i]>=10&&eRand[i]<=13) eRand[i] = 10;
					printf( "\n 相手の%dつ目の値：%d \n",i+1,eRand[i]);
					sum = 0;
					for(j=0; eRand[j]!='\0'; j++){
						sum += eRand[j];
					}
					eSum = sum;
					enterkey();
					if(eSum>17&&eSum<=21){
						qqq = 0;//もう引かない
					} else if(eSum>21) {
						eSum = 16;
						qqq = 0;//もう引かない
					}
				}
				printf( "\n 自分：%d	相手：%d \n",pSum ,eSum);
				if(pSum==eSum||pSum>21||((eSum>=1&&eSum<=21)&&eSum>pSum)){//player負けの条件
					printf( "\n===============\n"
							"\n 負け\n"
							"\n===============\n"
							);
					money -= bed_money;//掛け金分減る
				} else {//負け以外勝ち
					printf( "\n===============\n"
							"\n 勝ち\n"
							"\n===============\n"
							);
					money += bed_money;//2倍に増える
				}
				enterkey();
				break;
			case 2:
				qq = 0;
				break;
			default:
				exit(0);
		}
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
			exit(0);//無理やり終了
		}
	}//while
	return 0;
}

/* enterkey処理 */
void enterkey(void)
{
	char c;
	printf("\n Enterkey\n");
	c = getchar();
	system("cls");
}