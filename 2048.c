#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<getch.h>
#include<time.h>
#include<unistd.h>
//定义棋盘
int  board[6][6]={};
//获得随机数函数
bool b=true;
void get_rand(void)
{
    srand(time(NULL));
	int get_x=0,get_y=0;
	while(true)
	{
		if(b)
		{	
			get_x=rand()%4+1;
			get_y=rand()%4+1;
			if(board[get_x][get_y]==0)
			{
				board[get_x][get_y]=2;
				break;
			}
		}	
		else
			break;
	}
}
//显示棋盘函数
void show_board(void)
{
	//清屏
	system("clear");
    printf("--------------------\n");
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(board[i][j]!=0)
			printf("%4d",board[i][j]);
			else
			printf("    ");
			printf("|");
		}
		printf("\n");
		printf("--------------------\n");
	}
}

bool move_up(void)
{
	int k=0;
	int arr[5]={};
	int brr[5]={};
	int crr[4][4]={};
	for(int j=1;j<5;j++)
	{
		k=0;
		for(int i=1;i<5;i++)
		{
			crr[i-1][j-1]=board[i][j];
			if(board[i][j]!=0)
			{
				arr[k]=board[i][j];
				k++;
			}
		}
		k=0;
		for(int i=0;i<4;i++)
		{
			if(arr[i]!=0 && arr[i]==arr[i+1])
			{
				brr[k]=arr[i]*2;
				arr[i]=0;
				arr[i+1]=0;
				k++;i++;
			}
			else
			{
				brr[k]=arr[i];
				arr[i]=0;
				k++;
			}
		}
		for(int i=0;i<4;i++)
		{
			board[i+1][j]=brr[i];
			brr[i]=0;
		}
	}
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(board[i][j]!=crr[i-1][j-1])
			{
				return true;
			}
		}
	}
	return false;
}
bool move_down(void)
{
	int k=0;
	int arr[5]={};
	int brr[5]={};
	int crr[4][4]={};
	for(int j=1;j<5;j++)
	{
		k=0;
		for(int i=4;i>0;i--)
		{
			crr[i-1][j-1]=board[i][j];
			if(board[i][j]!=0)
			{
				arr[k]=board[i][j];
				k++;
			}
		}
		k=0;
		for(int i=0;i<4;i++)
		{
			if(arr[i]!=0 && arr[i]==arr[i+1])
			{
				brr[k]=arr[i]*2;
				arr[i]=0;
				arr[i+1]=0;
				k++;i++;
			}
			else
			{
				brr[k]=arr[i];
				arr[i]=0;
				k++;
			}
		}
		for(int i=0;i<4;i++)
		{
			board[4-i][j]=brr[i];
			brr[i]=0;
		}
	}
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(board[i][j]!=crr[i-1][j-1])
			{
				return true;
			}
		}
	}
	return false;

}
bool move_right(void)
{
	int k=0;
	int arr[5]={};
	int brr[5]={};
	int crr[4][4]={};
	for(int i=1;i<5;i++)
	{
		k=0;
		for(int j=4;j>0;j--)
		{
			crr[i-1][j-1]=board[i][j];
			if(board[i][j]!=0)
			{
				arr[k]=board[i][j];
				k++;
			}
		}
		k=0;
		for(int j=0;j<4;j++)
		{
			if(arr[j]!=0 && arr[j]==arr[j+1])
			{
				brr[k]=arr[j]*2;
				arr[j]=0;
				arr[j+1]=0;
				k++;j++;
			}
			else
			{
				brr[k]=arr[j];
				arr[j]=0;
				k++;
			}
		}
		for(int j=0;j<4;j++)
		{
			board[i][4-j]=brr[j];
			brr[j]=0;
		}
	}	
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(board[i][j]!=crr[i-1][j-1])
			{
				return true;
			}
		}
	}
	return false;
}
bool move_left(void)
{
	int k=0;
	int arr[5]={};
	int brr[5]={};
	int crr[4][4]={};
	for(int i=1;i<5;i++)
	{
		k=0;
		for(int j=1;j<5;j++)
		{
			crr[i-1][j-1]=board[i][j];
			if(board[i][j]!=0)
			{
				arr[k]=board[i][j];
				k++;
			}
		}
		k=0;
		for(int j=0;j<4;j++)
		{
			if(arr[j]!=0 && arr[j]==arr[j+1])
			{
				brr[k]=arr[j]*2;
				arr[j]=0;
				arr[j+1]=0;
				k++;j++;
			}
			else
			{
				brr[k]=arr[j];
				arr[j]=0;
				k++;
			}
		}
		for(int j=0;j<4;j++)
		{
			board[i][j+1]=brr[j];
			brr[j]=0;
		}
	}
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			if(board[i][j]!=crr[i-1][j-1])
			{
				return true;
			}
		}
	}
	return false;

}
// 获取键位函数
int get_key(void)
{
	while(true)
	{
		switch(getch())
		{
			case UP: return 0; 
			case DOWN: return 1; 
			case RIGHT: return 3; 
 			case LEFT: return 2; 
			default : continue ;
		}
	}
}
void get_fang(int n)
{
	if(n==0) b=move_up();
	if(n==1) b=move_down();
	if(n==2) b=move_left();
	if(n==3) b=move_right();
}

bool  gameover(void)
{
	for(int i=1;i<5;i++)
		{
			for(int j=1;j<5;j++)
			{
				if(0==board[i][j])
				{
					return false;
				}
				if(board[i][j]==board[i-1][j] || board[i][j]==board[i+1][j] || board[i][j]==board[i][j-1] || board[i][j]==board[i][j+1])
				{
					return false;
				}
			}
		}
		return true;
}
int main()
{
//初始化棋盘
	get_rand();
	
	while(true)
	{		
		get_rand();//获取随机数
		usleep(300000);
		show_board();
		get_fang(get_key());//获取键位移动计
		show_board();	
		if(gameover())//判断是否结束游戏
		{
			show_board();
			printf("你输了，游戏结束！\n");
			break;
		}
	}
}









