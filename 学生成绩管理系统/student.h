#ifndef STUDENT_H
#define STUDENT_H
#include "common.h"
#define SUM_SEC 365*24*3600
void total_ranking(int n);//总成绩排名
void single_ranking(int n);//单科成绩排名
void student_interface_son(int i);//学生界面
void change_stu_password(int i);
void single_ranking(int n)
{
	int count_c=1,count_m=1,count_e=1;//排名默认为1
	for(int i=0;i<500;i++)
	{
		if(student[i].state=='0')
		{
			if(student[i].chinese > student[n].chinese)//有一个成绩比我高，我的排名就加1
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
	int count=1;//排名默认为1
	for(int i=0;i<500;i++)
	{
		if(student[i].state=='0')
		{
			if(student[i].chinese+student[i].math+student[i].English > student[n].chinese+student[n].math+student[n].English )
				count++;			////有一个成绩比我高，我的排名就加1
		}
	}
	printf("总成绩排名：%d\n",count);	
}
void change_stu_password(int i)
{
	while(1)
		{
			printf("请输入新密码：");
			char new_code[20];
			password_input(new_code);
			if(0==password_rule(new_code))
			{
				show_msg("密码格式错误",1,2);
				continue;
			}
			if(0==strcmp(new_code,"123456"))
			{
				show_msg("不能修改为初始密码！",1,2);
				continue;
			}
			strcpy(student[i].code,new_code);
			show_msg("输入成功!",1,1);
			anykey_continue();
			break;
		}
}
void student_interface_son(int i)
{

	if(0==strcmp(student[i].code,"123456"))
	{
		system("clear");
		while(1)
		{
			puts("第一次登入请修改密码，密码不能为初始值");
			printf("请输入新密码：");
			char new_code[20];
			password_input(new_code);
			if(0==password_rule(new_code))
			{
				show_msg("密码格式错误",1,2);
				continue;
			}
			strcpy(student[i].code,new_code);
			show_msg("输入成功!",1,1);
			anykey_continue();
			break;
		}
	}
	while(1)
	{
		system("clear");
		printf("--------学生界面--------\n");
		printf("学号：%d\n",student[i].number);
		printf("姓名：%s\n",student[i].name);
		printf("性别：%s\n",student[i].sex=='1'?"男":"女");
		printf("年龄：%ld\n",(time(NULL)/(SUM_SEC))+1970-student[i].year);
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
			case 49:printf("*查看单科成绩排名*\n");single_ranking(i);anykey_continue();break;//1.学生入口
			case 50:printf("*查看总分成绩排名*\n");total_ranking(i);anykey_continue();break;//退出
			case 51:printf("修改登入密码\n");change_stu_password(i);;break;//退出
			case 52:printf("返回主菜单\n");return ;//退出
		}
	}
}

#endif
	

