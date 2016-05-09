/*
 * 2016.5.8
 * 2016.5.9
 * C
 */
 
/*
 * 文字列の比較strcmp
 * 一致すると０を出す
 * 
 * hero_rightの後に
 * hero_upといれると
 * 配列内ではhero_upghtとなって
 * 望んだとおりにならない
 * 
 * アドバイスにより、
 * s[i] = '\0'を最後に入れることで解決した
 * 
 */
 
 
#include <stdio.h>
#include <string.h>

void hero_up(int *);
void hero_down(int *);
void hero_right(int *);
void hero_left(int *);

int main(void)
{
	int hero_x = 0, hero_y = 0;
	int i;
	int c;
	char s[255] = {0};
	
	while(1){
		/*
		for(i = 0; i < 255; i++){
			s[i] = 0;
		}//for1
		*/
		for(i = 0;(c=getchar())!=EOF&&c!='\n';i++){
			s[i] = c;
		}//for2
		s[i] = '\0';
	
		if(strcmp(s,"hero_up" ) == 0)
			hero_up(&hero_y);
			
		else if(strcmp(s, "hero_down") == 0)
			hero_down(&hero_y);
		
		else if(strcmp(s, "hero_right") == 0)
			hero_right(&hero_x);
			
		else if(strcmp(s, "hero_left") == 0)
			hero_left(&hero_x);
			
		else if(strcmp(s, "exit") == 0)
			break;
			
		else
			printf("error\n");
		
		printf("%d,%d\n",hero_x, hero_y);
	}//while
	
	return 0;
}

void hero_up(int *y)
{
	*y += 1;
}

void hero_down(int *y)
{
	*y -= 1;
}

void hero_right(int *x)
{
	*x += 1;
}

void hero_left(int *x)
{
	*x -= 1;
}