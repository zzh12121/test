#include<stdio.h>
#include<getch.h>
#include<stdlib.h>
void student_interface_son(void);
void interface(void);
void student_interface(void);
void teacher_interface(void);
void administratorsr_interface(void);
void super_administrators_interface(void);
void teacher_interface_son(void);
void interface(void)
{
	system("clear");
	puts("1.学生入口");
	puts("2.教师入口");
	puts("3.管理员入口");
	puts("4.超级管理员入口");
	puts("5.退出");
}
void student_interface(void)
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
}
void student_interface_son(void)
{
	system("clear");
	printf("学号：\n");
	printf("性别：\n");
	printf("姓名：\n");
	printf("语文成绩：\n");
	printf("数学成绩：\n");
	printf("英语成绩：\n");
	printf("平均分：\n");
	printf("总分：\n");
	printf("1、查看单科成绩排名：\n");
	printf("2、总分成绩排名：\n");
	printf("3、修改登入密码：\n");
	printf("4、返回主菜单：\n");
	switch(getch())
			{
				case 49:printf("查看单科成绩排名\n");break;//1.学生入口
				case 50:printf("查看总分成绩排名\n");break;//退出
				case 51:printf("修改登入密码\n");break;//退出
				case 52:printf("返回主菜单\n");break;//退出
			}
}
void teacher_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.登入教师界面");
		puts("2.返回主界面");
		switch(getch())
			{
				case 49:teacher_interface_son();break;//1.教师入口
				case 50:return;break;//退出
			}
	}
}
void teacher_interface_son(void)
{
	system("clear");
	printf("工号：\n");
	printf("性别：\n");
	printf("姓名：\n");
	printf("年龄：\n");
	printf("工龄：\n");
	printf("1、学生信息管理：\n");
	printf("2、学生成绩管理：\n");
	printf("3、修改登入密码：\n");
	printf("4、返回主菜单：\n");
	switch(getch())
			{
				case 49:printf("学生信息管理\n");break;
				case 50:printf("学生成绩管理\n");break;
				case 51:printf("修改登入密码\n");break;
				case 52:printf("返回主菜单\n");break;
			}
}
void administratorsr_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.登入管理员界面");
		puts("2.返回主界面");
		switch(getch())
			{
				case 49:;break;//1.管理员入口
				case 50:return;break;//退出
			}
	}
}
void super_administrators_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.登入超级管理员界面");
		puts("2.返回主界面");
		switch(getch())
			{
				case 49:;break;//1.超级管理员入口
				case 50:return;break;//退出
			}
	}
}
int main()
{
	while(1)
	{
		interface();//显示初始界面
		switch(getch())
		{
			case 49:student_interface();break;//1.学生入口
			case 50:teacher_interface();break;//2.教师入口
			case 51:administratorsr_interface();break;//3.管理员入口
			case 52:super_administrators_interface();break;//4.超级管理员入口
			case 53:return 0;break;//5.退出

		}
	}
}

