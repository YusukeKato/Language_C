/*
 * 2016.5.10
 * 2015.5.11
 * C
 */
 
/*
 * とりあえず完成
 * やりたいことはできた
 */
 
/*
 * ちょっとしたデータ管理
 * 
 * 配列をもっと知る
 * 
 * "exit"で終了
 */
 
/*
 * 使い方
 * 1.文字列を入力
 * →dataBaseに入力された文字列が保存される
 * 		さらに、その文字列の文字数、文字列の初めの配列番号を保存する
 * 
 * 2.データ番号を入力
 * →そのデータ番号に該当するデータ（文字列）が出力される
 * →仕組みは、文字列の初めの配列番号から文字数分for文で繰り返して出力している
 *
 *
 */
 
/*
 * 問題
 * ・配列に０が入れられない
 * →dataBase[1]から入れ始める
 *
 * ・いろいろおかしい
 *
 * ・dataBase[],in_str[],宣言時に初期化しなければならないのかどうか
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
	
	dataPoint[0] = 1;//一番初めを指す
	
	while(1){
		/* 文字列入力 */
		printf("\n 入力（データ）：");
		for(i=0,char_count=0; (c=getchar())!=EOF&&c!='\n'; i++,char_count++){
			in_str[i] = c;
		}//for1
		in_str[i] = '\0';
		charNum[k] = char_count;//文字数をカウントして保存
		dataPoint[k+1] = dataPoint[k] + i;//文字列の最初を指すために保存
		k += 1;
		
		if(strcmp(in_str, "exit")==0){
			printf("終了・・・・・・\n");
			break;
		}//if
	
		/* 入力された文字列をデータベースに保存 */
		for(i=0; in_str[i]!='\0'; i++){
			dataBase[count+i+1] = in_str[i];
		}//for2
		
		count += i;/* dataBase[]の最後を指すため、+=が大事 */
		
		/* データベースの中身を出力 */
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
		
		/* データを出力 */
		printf("\n 入力（データ番号）：");
		scanf("%d",&dataNum);
		printf("\n");
		for(i = 0; i < charNum[dataNum]; i++){
			printf("%c",dataBase[dataPoint[dataNum] + i]);
		}//for6
		printf("\n");
		
		c = getchar();//エンターキー処理
		
	}//while
	
	return 0;
}