#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getch.h>
#include<unistd.h>

void teacher_interface_son(void);
struct Teacher //教师
{
	int number;
	char name[20];
	char sex;
	int  year;
	int  work_year;
	char code[20];
	char state;
	
};

struct Student //学生
{
	int  number;
	char name[20];
	char sex;//'2'女 '1'男
	int  year;
	int  math;
	int  English;
	int  chinese;
	char code[20];
	char state; //'0'正常 '1'冻结 '2'删除
};
	int stu_count = 0;
	struct Teacher teacher[500];//教师结构体
	struct Student student[500];//学生结构体
int _find_num( int key)//寻找学号
{
	for(int i=0 ;i<stu_count;i++)
	{
		if(student[i].number==key && student[i].state!= '2')
		{
			return i;
		}
	}
	return -1;
}
char *_find_name(char* name,char* key)//寻找姓名
{
	int count=0;
	for(int i=0;i<stu_count;i++)
	{
		if(0==strcmp(student[i].name,name) && student[i].state!='2')
		{
			key[count]=i+'0';
			count++;
		}
	}
	return key;
}
void _show_stu(int key,int b)//显示信息
{
	system("clear");
	printf("学号：%4d ",student[key].number);
	printf("性别：%3s ",'1'==student[key].sex?"男":"女");
	printf("姓名：%4s ",student[key].name);
	if(b==1)
	{
	printf("语文：%4d ",student[key].chinese);
	printf("数学：%4d ",student[key].math);
	printf("英语：%4d ",student[key].English);
	}
	printf("\n");
	sleep(1);
}
void add_stu(void)//增加学生(可能需要修改)
{
	system("clear");
	printf("----------增加学生---------\n");
	stu_count++;
	int num=100000;int sex=0;
	student[stu_count-1].number=num+stu_count;

	printf("请输入姓名：\n");
	gets(student[stu_count-1].name);

	while(1)
	{	
		printf("请输入性别1.男 2.女\n");
		sex=getch();
		if(sex==49||sex==50)
		{
			printf("%s\n",sex==49?"男":"女");
			student[stu_count-1].sex=sex;
			break;
		}
		else
		printf("性别输入错误！\n");
	}
	student[stu_count-1].state='0';
	printf("请输入出生年份：\n");
	scanf("%d",&student[stu_count-1].year);
	puts("添加成功！");
	sleep(1);	
}
void del_stu(void)//删除学生
{
	system("clear");
	int key=0;int num=0;int yes;
	printf("----------删除学生---------\n");
	printf("请输入需删除学生的学号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			_show_stu(num,0);
			printf("是否继续删除？y/n\n");
			yes=getch();
			if(yes==121 || yes==89)
			{	
				student[num].state='2';
				puts("删除成功！\n");
				break;
			}
			else
			{
				printf("输入学号：\n");
			}
		}	
	}
	sleep(2);
}
void modify_stu(void)//修改学生信息
{
	system("clear");
	int key=0;int num=0;char name[20];int year=0;
	printf("----------修改信息---------\n");
	printf("请输入需修改学生的学号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			printf("输入修改的姓名：\n");
			strcpy(student[num].name,gets(name));
			
			printf("输入入学年份：\n");
			scanf("%d",&year);
			student[num].year=year;
			printf("修改成功！\n");
			break;
		}
	}
	sleep(2);
}
void reset_code(void)//重置密码
{
	system("clear");
	int key=0;int num=0;
	printf("----------重置密码----------\n");
	printf("请输入需要重置密码学生的学号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			strcpy(student[num].code,"000000");
			printf("修改成功！\n");
			break;
		}
	}	
	sleep(2);
}
void unlock_account(void)//解锁账号
{
	system("clear");
	int key=0;
	printf("----------解锁账号----------\n");
	while(1)
	{	
		printf("请输入需要解锁账号的学生的学号:\n");
		scanf("%d",&key);
		getchar();
		for(int i=0 ;i<stu_count;i++)
		{
			if(student[i].number==key && student[i].state == '1')
			{
				student[i].state= '0';
				printf("解锁成功！\n");
				sleep(2);
				return;
			}
		}
	}
	
}
void find_name_stu(void)//按姓名查找
{
	system("clear");
	char key[100] ;char name[20];int num=0;
	printf("----------按姓名查找----------\n");
	while(1)
	{
		printf("请输入需要查找人姓名：\n");
		gets(name);
		_find_name(name,key);
		num=strlen(key);
		for(int i=0;i<num;i++)
		{
			printf("学号：%4d ",student[key[i]-'0'].number);
			printf("性别：%3s ",'1'==student[key[i]-'0'].sex?"男":"女");
			printf("姓名：%4s \n",student[key[i]-'0'].name);
		}
		printf("是否结束查找？y/n\n");
		num=getch();
		if(num==121 ||num==89)
			break;
	}
}
void show_01_stu(void)//显示在校学生
{
	system("clear");
	char key[500];
	printf("----------显示在校学生---------\n");
	while(1)
	{
		int num=0;
		for(int i=0;i<stu_count;i++)
		{
			if(student[i].state!='2')
			{
				key[num]=i+'0';
				num++;
			}
		}
		for(int i=0;i<num;i++)
		{
			printf("学号：%4d ",student[key[i]-'0'].number);
			printf("性别：%3s ",'1'==student[key[i]-'0'].sex?"男":"女");
			printf("姓名：%4s \n",student[key[i]-'0'].name);
		}
		printf("任意键结束显示！\n");
			getch();
			break;	
	}
}
void show_2_stu(void)//显示离校学生
{
	system("clear");
	char key[500];int num=0;
	printf("----------显示离校学生---------\n");
	while(1)
	{
		for(int i=0;i<stu_count;i++)
		{
			if(student[i].state=='2')
			{
				key[num]=i+'0';
				num++;
			}
		}
		for(int i=0;i<num;i++)
		{
			printf("学号：%4d ",student[key[i]-'0'].number);
			printf("性别：%3s ",'1'==student[key[i]-'0'].sex?"男":"女");
			printf("姓名：%4s \n",student[key[i]-'0'].name);
		}
		printf("任意键结束显示\n");
			getch();
			break;
	}
}
void student_information_management(void)//学生信息管理
{
	while(1)
	{
		system("clear");
		printf("-------------学生信息管理--------------\n");
		puts("1.添加学生");
		puts("2.删除学生");
		puts("3.修改学生基本信息");
		puts("4.重置学生密码");
		puts("5.解锁学生账号");
		puts("6.根据姓名查询学生基本信息");
		puts("7.显示所有在读学生");
		puts("8.显示所有退学学生");
		puts("9.返回上层");
		switch(getch())
			{
				case 49: add_stu();break;
				case 50: del_stu();break;
				case 51: modify_stu();break;
				case 52: reset_code();break;
				case 53: unlock_account();break;
				case 54: find_name_stu();break;
				case 55: show_01_stu();break;
				case 56: show_2_stu();break;
				case 57: return;
			}
	}
}
void add_score(void)
{
	system("clear");
	int key=0;int num=0;int yes=0;
	while(1)
	{
		system("clear");
		puts("----------成绩录入----------");
		printf("请输入需录入成绩学生的学号\n");
	
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			_show_stu(num,1);
			puts("请输入语文成绩：");
			scanf("%d",&student[num].chinese);
			puts("请输入数学成绩: ");
			scanf("%d",&student[num].math);
			puts("请输入英语成绩：");
			scanf("%d",&student[num].English);
			getchar();
			puts("是否继续输入？y/n");
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}	
	}
	sleep(2);
}
void modify_score(void)
{
	system("clear");
	int key=0;int num=0;int yes=0;
	while(1)
	{
		system("clear");
		puts("----------成绩修改----------");
		puts("请输入需录入成绩学生的学号");
	
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			_show_stu(num,1);
			puts("请输入语文成绩：");
			scanf("%d",&student[num].chinese);
			puts("请输入数学成绩: ");
			scanf("%d",&student[num].math);
			puts("请输入英语成绩：");
			scanf("%d",&student[num].English);
			getchar();
			puts("是否继续修改？y/n");
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }
		}
	}
}
void find_name_num_score(void)
{
	int key=0;
	while(1)
	{	
		int num=0;
		system("clear");
		puts("----------成绩查询----------");
		puts("请输入需要查询学生的学号:");
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
			printf("该学生学号不存在！请重新输入：\n");
		else
		{
			_show_stu(num,1);
			puts("任意键结束显示！");
			getch();
			break;
		}
	}
}

void all_ranking(void)
{
	system("clear");
	int count_c[500]={},count_m[500]={},count_e[500]={},count[500]={};
	for(int i=0;i<500;i++)
	{
		if(student[i].state=='0')
		{
			for(int j=0;j<500;j++)
			{
				if(student[j].state=='0')
				{
					if(student[j].chinese > student[i].chinese)
					count_c[i]++;
					if(student[j].math > student[i].math)
					count_m[i]++;
					if(student[j].English > student[i].English)
					count_e[i]++;
					if(student[j].chinese+student[j].math+student[j].English > student[i].chinese+student[i].math+student[i].English )
					count[i]++;
				}
			}
		}
	}
	printf(" 学号    姓名	语文排名(语文分数)  数学排名(数学分数)  英语排名(英语分数)  总排名(总分)\n");
	for(int i=0;i<500;i++)
	{
		
		if(student[i].state=='0')
		{
			printf("%6d\t",student[i].number);
			printf("%s\t",student[i].name);
			printf("%6d（%3d）\t",count_c[i]+1,student[i].chinese);
			printf("%10d（%3d）\t",count_m[i]+1,student[i].math);
			printf("%6d（%3d）\t",count_e[i]+1,student[i].English);
			printf("%7d（%3d）\n",count[i]+1,student[i].chinese+student[i].math+student[i].English);
		}
	}
	printf("任意键结束显示！\n");
	getch();	
}


void student_achievement_management(void)//学生成绩管理
{
	while(1)
	{
		system("clear");
		printf("------------学生成绩管理---------------\n");
	//录入学生成绩
	//单个录入或指导入 
	//修改学生成绩 
	//根据学号或姓名查询学生成绩 
	//按各科分数和部分排序
	//返回上层
		puts("1.单个录入成绩");
	    puts("2.值导入");
	    puts("3.修改学生成绩");
	    puts("4.根据学号或姓名查找成绩");
	    puts("5.按各科分数或部分排序");
	    puts("6.返回上层");
	    switch(getch())
	    {
			case 49: add_score();break;
			case 50: printf("值导入");break;
			case 51: modify_score();break;
	 		case 52: find_name_num_score();break;
			case 53: all_ranking();break;
			case 54: return;
		}
	}	
}
void teacher_interface_son(void)
{
	teacher[0].number=100000;//
	strcpy(teacher[0].name,"苍");
	teacher[0].sex='0';
	teacher[0].year=1970;
	teacher[0].work_year=2000;
	teacher[0].code[20]='1';
	teacher[0].state='0';//教师测试变量
	while(1)
	{
	system("clear");
	printf("工号：%d\n",teacher[0].number);
	printf("性别：%c\n",teacher[0].sex);
	printf("姓名：%s\n",teacher[0].name);
	printf("年龄：%d\n",teacher[0].year);
	printf("工龄：%d\n",teacher[0].work_year);
	printf("1、学生信息管理：\n");
	printf("2、学生成绩管理：\n");
	printf("3、修改登入密码：\n");
	printf("4、返回主菜单：\n");
	switch(getch())
			{
				case 49:student_information_management();break;
				case 50:student_achievement_management();break;
				case 51:printf("修改登入密码\n");break;
				case 52:printf("返回主菜单\n");return;break;
			}
	}
}
int main()
//void teacher_interface(void)
{
	while(1)
	{
		system("clear");
		puts("1.登入教师界面");
		puts("2.返回主界面");
		switch(getch())
			{
				case 49:teacher_interface_son();break;//1.教师入口
				case 50:break;//退出//合并时这里需要修改
			}
	}
}

