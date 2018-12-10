#include<stdio.h>
#include<string.h>
#include<getch.h>
#include<stdlib.h>
#include<time.h>
#define SUM_SEC 365*24*3600UL
void total_ranking(int n);
void single_ranking(int n);
struct student//学生数据
{
	int number;
	char name[20];
	char sex;
	int year;
	int math;
	int English;
	int chinese;
	char code[20];
	char state;//'0'正常 '1'冻结 '2'退学
};struct student student[500];
/*void student_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.登入学生界面");
		puts("2.返回主界面");
		switch(getch())
			{
				case 49:student_interface_son();break;//1.学生入口
				case 50:return;break;//退出
			}
	}
}*/

void any_key_continue(void)
{
	printf("\n按任意键继续...");
	getch();
}

void single_ranking(int n)
{
	int count_c=1,count_m=1,count_e=1;
	for(int i=0;i<500;i++)
	{
		if(student[i].state!='2')
		{
			if(student[i].chinese > student[n].chinese)
			count_c++;
			if(student[i].math > student[n].math)
			count_m++;
			if(student[i].English > student[n].English)
			count_e++;
		}
	}
	printf("语文成绩排名：%d\n",count_c);
	printf("数学成绩排名：%d\n",count_m);
	printf("英语成绩排名：%d\n",count_e);
}

void total_ranking(int n)
{
	int count=1;
	for(int i=0;i<500;i++)
	{
		if(student[i].state!='2')
		{
			if(student[i].chinese+student[i].math+student[i].English > student[n].chinese+student[n].math+student[n].English )
				count++;
		}
	}
	printf("总成绩排名：%d\n",count);	
}
//void student_interface_son(void)
int main()
{
	student[0].number=101101;
	student[0].sex='0';
	strcpy(student[0].name,"搞事");
	student[0].year=1997;	
	student[0].chinese=95;
	student[0].math=70;
	student[0].English=88;
	student[0].state='0';

	student[1].number=101102;
	student[1].sex='1';
	strcpy(student[1].name,"真糟糕");
	student[1].chinese=99;
	student[1].math=69;
	student[1].English=88;
	student[1].state='0';

	student[2].number=101103;
	student[2].sex='1';
	strcpy(student[2].name,"不开机");
	student[2].chinese=65;
	student[2].math=23;
	student[2].English=99;
	student[2].state='0';
	int i=0;
	while(1)
	{
		system("clear");
		printf("学号：%d\n",student[i].number);
		printf("姓名：%s\n",student[i].name);
		printf("性别：%s\n",student[i].sex=='0'?"女":"男");
		printf("年龄：%d\n",(time(NULL)/(SUM_SEC))+1970-student[i].year);
		printf("语文成绩：%d\n",student[i].chinese);
		printf("数学成绩：%d\n",student[i].math);
		printf("英语成绩：%d\n",student[i].English);
		printf("平均分：%.2lf\n",(student[i].chinese+student[i].math+student[i].English)/3.0);
		printf("总分：%d\n",student[i].chinese+student[i].math+student[i].English);
		printf("--------------------\n");
		printf("1、查看单科成绩排名：\n");
		printf("2、总分成绩排名：\n");
		printf("3、修改登入密码：\n");
		printf("4、返回主菜单：\n");
		printf("--------------------\n");
		switch(getch())
		{
			case 49:printf("*查看单科成绩排名*\n");single_ranking(i);any_key_continue();break;//1.学生入口
			case 50:printf("*查看总分成绩排名*\n");total_ranking(i);any_key_continue();break;//退出
			case 51:printf("修改登入密码\n");break;//退出
			case 52:printf("返回主菜单\n");return;//退出
		}
	}
}


	

