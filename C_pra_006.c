/*
 * 2016.5.10
 * 2015.5.10
 * C
 */
 
/*
 * ちょっとしたデータ管理
 * 
 * dataBase[],in_s[],宣言時に初期化しなければならない
 * 
 * 配列をもっと知る
 * 
 * "exit"で終了
 */
 
#include <stdio.h>
#include <string.h>

#define MAXDATA 256

int main(void)
{
	char dataBase[MAXDATA] = {0};
	int p_dataBase[MAXDATA] = {0};
	char in_str[MAXDATA] = {0};
	char c;
	int count = 0;
	int char_count = 0;
	int char_num = 0;
	int i = 0;
	
	while(1){
		/* 文字列入力 */
		for(i=0,char_count=0; (c=getchar())!=EOF&&c!='\n'; i++,char_count++){
			in_str[i] = c;
		}//for1
		in_str[i] = '\0';
		
		p_dataBase[MAXDATA] = char_count;//文字数を保存
		
		if(strcmp(in_str, "exit")==0){
			printf("終了・・・・・・\n");
			break;
		}//if
	
		/* 入力された文字列をデータベースに保存 */
		for(i=0; in_str[i]!='\0'; i++){
			dataBase[count+i] = in_str[i];
		}//for2
		
		count += i;/* dataBase[]の最後を指すため、+=が大事 */
		
		/* データベースの中身を出力 */
		for(i=0; dataBase[i]!='\0'; i++){
			printf("%c",dataBase[i]);
			printf("%d",p_dataBase[i]);
		}//for3
		printf("\n");
	}//while
	
	return 0;
}