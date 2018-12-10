#ifndef COMMON_H
#define COMMON_H
#include<stdio.h>
#include<getch.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
void clear_stdin(void);//清屏函数
char* get_str(char* str,size_t size);//输入函数
void anykey_continue(void);//任意键跳出函数 
void password_input(char* str);//密码输入
void show_msg(char* msg,int sec,int color);//延迟显示
//int load_data(const char* path,void* ptr,size_t node_size);//从文件中读取数据
//int save_data(const char* path,const void* ptr,size_t node_size);//保存数据到文件中
int password_rule(char *str);
int password_rule(char *str)
{
	int x=strlen(str);
	if(x<6 || x>10)
	return 0;
	for(int i=0;str[i];i++)
	{
		if(str[i]<'0' || str[i]>'9')
		return 0;
	}
	return 1;
}
struct Admin
{
	int number;//工号
	char name[20];//姓名
	char code[20];//密码
	int year;//出生年
	int work_year;//参加工作的那年
	char sex;//性别
	char state;//0正常 1 冻结 2 离职

};
struct Teacher
{
	int number;//工号
	char name[20];//姓名
	char sex;//性别
	int year;//出生年
	int work_year;//入职年
	char code[20];//密码
	char state;//0正常 1 冻结 2 退学	
};
struct Student
{
	char code[20];//密码
	char name[20];//姓名
	int number;//学号
	int year;//出生年
	int math;//数学成绩
	int English;//英语成绩
	int chinese;//语文成绩
	char sex;//性别
	char state;//0正常 1 冻结 2 离职
};
struct Score
{
	int num ;//学号
	int math ;//数学成绩
	int English;//英语成绩
	int chinese;// 语文成绩
};
struct Score score[500];
struct Student student[500];
struct Teacher teacher[50];
struct Admin admin[10];
int stu_count=0;
int teacher_count=0;
int adm_count=0;
void anykey_continue(void)
{
	puts("按任意键返回......");
	getch();
}
void password_input(char* str);
void clear_stdin(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
}
char* get_str(char* str,size_t size)
{
	if(NULL == str) return str;
	clear_stdin();
	fgets(str,size,stdin);
	if(size-1 == strlen(str))
	{
		if('\n'==str[size-2])
			str[size-2]= '\0';
		else
			clear_stdin();
	}
	else
		str[strlen(str)-1]='\0';
}
void password_input(char* str)
{
	for(int i=0;i<20;i++)
	{
		str[i]=getch();
		if(i>0&&127 == str[i])
		{
			i-=2;
			printf("\b \b");
			continue;
		}
		if(127 == str[i])
		{
			i--;
			continue;
		}
		if('\n'==str[i])
		{
			str[i]='\0';
			break;
		}
		putchar('*');
		
	}
}
void show_msg(char* msg,int sec,int color)
{
	if(0==color)
	printf("\n\033[01;31m%s\n\033[00m\n",msg);
	if(1==color)
	printf("\n\033[01;32m%s\n\033[00m\n",msg);
	if(2==color)
	printf("\n\033[01;33m%s\n\033[00m\n",msg);
	sleep(sec);
}
/*int load_data(const char* path,void* ptr,size_t node_size)
{
	if(NULL == path || NULL == ptr) return PRNIL;
	FILE* frp = fopen(path,"r");
	if(NULL == frp) return ERROR;
	size_t cnt =0,num=0;
	while((cnt = fread(ptr+num*node_size,node_size,1,frp)))
	 num+=cnt;
	fclose(frp);
	return num;
}
int save_data(const char* path,const void* ptr,size_t node_size)
{
	if(NULL == path || NULL==ptr) return PRNIL;
	FILE* fwp=fopen(path,"w");
	if(NULL == fwp) return ERROR;
	size_t cnt =fwrite(ptr,node_size,num,fwp);
	fclose(fwp);
	return cnt;
}*/
#endif
