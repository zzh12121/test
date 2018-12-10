#ifndef INTERFACE_H
#define INTERFACE_H
#include "common.h"
#include "sup_admin.h"
#include "teacher.h"
#include "student.h"
#include "admin.h"
void interface(void);//主菜单函数声明
void student_interface(void);//学生入口
void teacher_interface(void);//教师入口
void administratorsr_interface(void);//管理员入口
void super_administrators_interface(void);//超级管理员入口
int cmp_stu_num(int num);//通过学号查找编号
int cmp_stu_code(int num,char *str);//通过编号对学生密码进行验证
int cmp_tea_num(int num);//通过工号查找编号
int cmp_tea_code(int num,char *str);//通过编号对教师密码进行验证
int cmp_adm_num(int num);//通过工号来查找编号
int cmp_adm_code(int num,char *str);//通过编号对管理员密码进行验证
void student_interface_son(int i);
int cmp_stu_code(int num,char *str)
{
	if(num<0) return 0;
	int i=strcmp(str,student[num].code);
	if(i==0) return 1;
	else return 0;
}
int cmp_stu_num(int num)
{
	for(int i=0;student[i].number;i++)
	{
		if(student[i].number==num)
		return i;
	}
	return -1;
}
int cmp_tea_code(int num,char *str)
{
	if(num<0) return 0;
	int i=strcmp(str,teacher[num].code);
	if(i==0) return 1;
	else return 0;
}
int cmp_tea_num(int num)
{
	for(int i=0;teacher[i].number;i++)
	{
		if(teacher[i].number==num)
		return i;
	}
	return -1;
}
int cmp_adm_code(int num,char *str)
{
	if(num<0) return 0;
	int i=strcmp(str,admin[num].code);
	if(i==0) return 1;
	else return 0;
}
int cmp_adm_num(int num)
{
	for(int i=0;admin[i].number;i++)
	{
		if(admin[i].number==num)
		return i;
	}
	return -1;
}
void interface(void)
{
	system("clear");
	puts("-----指针学生信息管理系统-----");	
	puts("1.学生入口");
	puts("2.教师入口");
	puts("3.管理员入口");
	puts("5.退出");
}
void student_interface(void)
{
	system("clear");
	puts("----------学生登录----------");
	puts("1.登入学生成绩查询系统");
	puts("2.返回主界面");
	int stu_num=0;
	char stu_code[20];
	int index=0;
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("clear");
				puts("-----登入学生成绩查询系统-----");
				puts("1.输入账号密码:");
				puts("2.退出");
				switch(getch())
				{
					case 49:printf("请输入账号：");
							scanf("%d",&stu_num);
							printf("请输入密码：");
							getch();
							password_input(stu_code);
							int i=cmp_stu_num(stu_num);
							if(-1==i)
							{
								show_msg("账号不存在!",1,0);
								continue;
							}
							if(student[i].state=='1')
							{
								show_msg("该账号已经被冻结!",1,0);
								return;
							}
							if(student[i].state=='2')
							{
								show_msg("您已离校！无法登入！",1,0);
								return;
							}
							if(cmp_stu_code(i,stu_code))
							{
								system("clear");
								printf("%s同学，欢迎你!\n",student[i].name);
								sleep(2);
								student_interface_son(i);
								index=0;
							}
							else if(2==index)
							{
								show_msg("你的账号已经被锁定",1,0);
								student[i].state='1';
								anykey_continue();
								return;
							}
							else
							{
								printf("\n\033[01;33m你还剩%d次机会!\n\033[00m\n",2-index);
								index++;
								anykey_continue();
							};
							;break;
					case 50:return;
				}
			}	
			;break;//1.学生入口
		case 50:return;break;//退出
	}

}
void teacher_interface(void)
{
	system("clear");
	puts("----------教师登录----------");
	puts("1.登入教师管理系统");
	puts("2.返回主界面");
	int tea_num=0;
	char tea_code[20];
	int index=0;
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("clear");
				puts("-----登入教师管理系统-----");
				puts("1.输入账号密码:");
				puts("2.退出");
				switch(getch())
				{
					case 49:printf("请输入教师工号：");
							scanf("%d",&tea_num);
							printf("请输入密码：");
							getch();
							password_input(tea_code);
							int i=cmp_tea_num(tea_num);
							if(-1==i)
							{
								show_msg("账号不存在!",1,0);
								continue;
							}
							if(teacher[i].state=='1')
							{
								show_msg("该账号已经被冻结!",1,0);
								return;
							}
							if(cmp_tea_code(i,tea_code))
							{
								system("clear");
								printf("%s老师，欢迎您!\n",teacher[i].name);
								sleep(2);
								teacher_interface_son(i);
								index=0;
							}
							else if(2==index)
							{
								show_msg("你的账号已经被锁定",1,0);
								teacher[i].state='1';
								anykey_continue();
								return;
							}
							else
							{
								printf("\n\033[01;33m你还剩%d次机会!\n\033[00m\n",2-index);
								index++;
								anykey_continue();
							};
							;break;
					case 50:return;
				}
			}	
			;break;
		case 50:return;break;
	}
}
void administratorsr_interface(void)
{
	system("clear");
	puts("----------管理员登录----------");
	puts("1.登入管理员管理系统");
	puts("2.返回主界面");
	int adm_num=0;
	char adm_code[20];
	int index=0;
	switch(getch())
	{
		case 49:
			while(1)
			{
				system("clear");
				puts("-----登入管理员管理系统-----");
				puts("1.输入账号密码:");
				puts("2.退出");
				switch(getch())
				{
					case 49:printf("请输入管理员工号：");
							scanf("%d",&adm_num);
							printf("请输入密码：");
							getch();
							password_input(adm_code);
							int i=cmp_adm_num(adm_num);
							if(-1==i)
							{
								show_msg("账号不存在!",1,0);
								anykey_continue();
								continue;
							}
							if(admin[i].state=='1')
							{
								show_msg("该账号已经被冻结!",1,0);
								anykey_continue();
								return;
							}
							if(cmp_adm_code(i,adm_code))
							{
								system("clear");
								printf("%s管理员，欢迎您!\n",admin[i].name);
								sleep(2);
								admin_interface_son(i);
								index=0;
							}
							else if(2==index)
							{
								show_msg("你的账号已经被锁定",1,0);
								admin[i].state='1';
								anykey_continue();
								return;
							}
							else
							{
								printf("\n\033[01;33m你还剩%d次机会!\n\033[00m\n",2-index);
								index++;
								anykey_continue();
							};
							;break;
					case 50:return;
				}	
			}	
			;break;
		case 50:return;break;
	}
}
void super_administrators_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.请输入指令:");
		puts("2.退出");
		switch(getch())
		{
			case 49:system("clear");
					puts("输入口令:");
					char sup_adm_mima[30]={};
					password_input(sup_adm_mima);
					int index=strcmp(sup_adm_mima,"asdfghjkl123456789");
					if(index==0)
					{
						show_msg("登入成功!!",1,0);
						super_administrators_interface_son();
					}
					else
					{
						anykey_continue();
						return;
					};break;
			case 50:return;
		}
	}
}

#endif
