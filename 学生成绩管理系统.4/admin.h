#ifndef ADMIN_H
#define ADMIN_H
#include"common.h"
void admin_interface_son(int i);
int _find_teacher_num( int key);//寻找老师工号
char *_find_teacher_name(char* name,char* key);//寻找教师姓名
void _show_teacher(int key,int b);//显示教师信息
void add_teacher(void);//增加教师(可能需要修改)
void del_teacher(void);//删除教师
void modify_teacher(void);//修改教师信息
void reset_teacher_code(void);//重置教师密码
void unlock_teacher_account(void);//解锁教师账号
void find_teacher_name(void);//按姓名查找教师
void show_01_teacher(void);//显示在职教师
void show_2_teacher(void);//显示离职教师
void teacher_information_management(void);//教师信息管理
void change_adm_password(int i);
int _find_teacher_num( int key)//寻找老师工号
{
	for(int i=0 ;i<teacher_count;i++)
	{
		if(teacher[i].number==key && teacher[i].state != '2')
		{
			return i;
		}
	}
	return -1;
}
char *_find_teacher_name(char* name,char* key)//寻找教师姓名
{
	int count=0;
	for(int i=0;i < teacher_count;i++)
	{
		if(0==strcmp(teacher[i].name,name) && (teacher[i].state=='0'|| teacher[i].state=='1'))
		{
			key[count]=i+'0';
			count++;
		}
	}
	key[count]='\0';
	return key;
}
void _show_teacher(int key,int b)//显示教师信息
{
	system("clear");
	printf("工号：%4d ",teacher[key].number);
	printf("性别：%3s ",'1'==teacher[key].sex?"男":"女");
	printf("姓名：%4s \n",teacher[key].name);
	sleep(1);
}
void add_teacher(void)//增加教师(可能需要修改)
{
	system("clear");
	printf("----------增加教师---------\n");
	teacher_count++;
	int num=200000,sex=0;
	teacher[teacher_count-1].state='0';
	strcpy(teacher[teacher_count-1].code,"123456");
	teacher[teacher_count-1].number=num+teacher_count;

	printf("请输入姓名：\n");
	gets(teacher[teacher_count-1].name);
	while(1)
	{	
		printf("请输入性别1.男 2.女\n");
		sex=getch();
		if(sex==49||sex==50)
		{
			printf("%s\n",sex==49?"男":"女");
			teacher[teacher_count-1].sex=sex;
			break;
		}
		else
		show_msg("性别输入错误！",1,2);
	}
	printf("请输入出生年份：\n");
	scanf("%d",&teacher[teacher_count-1].year);
	printf("请输入参加工作的年份：\n");
	scanf("%d",&teacher[teacher_count-1].work_year);
	show_msg("添加成功！",1,1);
		
}
void del_teacher(void)//删除教师
{
	system("clear");
	int key=0;int num=0;int yes;
	printf("----------删除教师---------\n");
	printf("请输入需删除教师的工号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_teacher_num(key);
		if(-1==num)
		{
			show_msg("该教师工号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}
		else
		{
			_show_teacher(num,0);
			show_msg("是否继续删除？y/n",1,2);
			yes=getch();
			if(yes==121 || yes==89)
			{	
				teacher[num].state='2';
				show_msg("删除成功！",1,1);
				break;
			}
			else
			{
				printf("输入工号：\n");
			}
		}	
	}
	sleep(1);
}
void modify_teacher(void)//修改教师信息
{
	system("clear");
	int key=0;int num=0;char name[20];int year=0;int yes=0;
	printf("----------修改信息---------\n");
	printf("请输入需修改教师的工号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_teacher_num(key);
		if(-1==num)
		{
			show_msg("该教师工号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}
		else
		{
			printf("输入修改的姓名：\n");
			strcpy(teacher[num].name,gets(name));
			
			printf("输入入职年份：\n");
			scanf("%d",&year);
			teacher[num].year=year;
			show_msg("修改成功！",1,1);
			break;
		}
	}
	sleep(1);
}
void reset_teacher_code(void)//重置教师密码
{
	system("clear");
	int key=0;int num=0;int yes=0;
	printf("----------重置密码----------\n");
	printf("请输入需要重置密码教师的工号\n");
	while(1)
	{
		scanf("%d",&key);
		getchar();
		num=_find_teacher_num(key);
		if(-1==num)
		{
			show_msg("该教师工号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}
		else
		{
			strcpy(teacher[num].code,"123456");
			show_msg("修改成功！",1,1);
			break;
		}
	}	
	sleep(1);
}
void unlock_teacher_account(void)//解锁教师账号
{
	system("clear");
	int key=0;
	printf("----------解锁账号----------\n");
	while(1)
	{	
		printf("请输入需要解锁账号的教师的工号:\n");
		scanf("%d",&key);
		getchar();
		for(int i=0 ;i<teacher_count;i++)
		{
			if(teacher[i].number==key && teacher[i].state == '1')
			{
				teacher[i].state= '0';
				show_msg("解锁成功！",1,1);
				anykey_continue();
				return;
			}
		}
		show_msg("查无此人",1,0);
		return;
	}
}
void find_teacher_name(void)//按姓名查找教师
{
	system("clear");
	char key[100]={};char name[20];int num=0;
	printf("----------按姓名查找----------\n");
	while(1)
	{
		printf("请输入需要查找人姓名：\n");
		gets(name);
		_find_teacher_name(name,key);
		num=strlen(key);
		if(num==0)
		{
			show_msg("查无此人",1,0);
			return;
		}
		for(int i=0;i<num;i++)
		{
			printf("工号：%4d ",teacher[key[i]-'0'].number);
			printf("姓名：%4s ",teacher[key[i]-'0'].name);
			printf("性别：%3s \n",'1'==teacher[key[i]-'0'].sex?"男":"女");
		}
		show_msg("是否结束查找？y/n",1,2);
		num=getch();
		if(num==121 ||num==89)
		{
			break;
		}
	}

}
void show_01_teacher(void)//显示在职教师
{
	system("clear");
	char key[500];int num=0;
	printf("----------显示在职教师---------\n");
	for(int i=0;i<teacher_count;i++)
	{
		if(teacher[i].state!='2')
		{
			key[num]=i+'0';
			num++;
		}
	}
	key[num]='\0';
	for(int i=0;i<num;i++)
	{
		printf("工号：%4d ",teacher[key[i]-'0'].number);
		printf("姓名：%4s ",teacher[key[i]-'0'].name);
		printf("性别：%3s\n",'1'==teacher[key[i]-'0'].sex?"男":"女");
	}
	show_msg("按任意键继续!",1,2);
	getch();
	
}
void show_2_teacher(void)//显示离职教师
{
	system("clear");
	char key[500];int num=0;
	printf("----------显示离职教师---------\n");
	for(int i=0;i<teacher_count;i++)
	{
		if(teacher[i].state=='2')
		{
			key[num]=i+'0';
			num++;
		}
	}
	key[num]='\0';
	for(int i=0;i<num;i++)
	{
		printf("工号：%4d ",teacher[key[i]-'0'].number);
		printf("姓名：%4s ",teacher[key[i]-'0'].name);
		printf("性别：%3s\n",'1'==teacher[key[i]-'0'].sex?"男":"女");
	}
	show_msg("按任意键继续!",1,2);
	getch();
}
void teacher_information_management(void)//教师信息管理
{
	while(1)
	{
		system("clear");
		printf("-------------教师信息管理--------------\n");
		puts("1.添加教师");
		puts("2.删除教师");
		puts("3.修改教师基本信息");
		puts("4.重置教师密码");
		puts("5.解锁教师账号");
		puts("6.根据姓名查询教师基本信息");
		puts("7.显示所有在职教师");
		puts("8.显示所有离职教师");
		puts("9.返回上层");
		switch(getch())
			{
				case 49: add_teacher();break;
				case 50: del_teacher();break;
				case 51: modify_teacher();break;
				case 52: reset_teacher_code();break;
				case 53: unlock_teacher_account();break;
				case 54: find_teacher_name();break;
				case 55: show_01_teacher();break;
				case 56: show_2_teacher();break;
				case 57: return;
			}
	}
}
void change_adm_password(int i)
{
	while(1)
		{
			printf("请输入新密码：");
			char new_code[20];
			password_input(new_code);
			if(0==password_rule(new_code))
			{
				show_msg("密码格式错误",1,0);
				continue;
			}
			if(0==strcmp(new_code,"123456"))
			{
				show_msg("不能修改为初始密码！",1,0);
				continue;
			}
			strcpy(admin[i].code,new_code);
			show_msg("输入成功!",1,1);
			anykey_continue();
			break;
		}
}
void admin_interface_son(int num)
{
	if(0==strcmp(admin[num].code,"123456"))
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
				show_msg("密码格式错误",1,0);
				continue;
			}
			strcpy(admin[num].code,new_code);
			show_msg("输入成功!",1,1);
			anykey_continue();
			break;
		}
	}
	while(1)
	{
	system("clear");
	printf("--------管理员界面--------\n");
	printf("工号：%d\n",admin[num].number);
	printf("姓名：%s\n",admin[num].name);
	printf("-------------------------\n");
	printf("1、教师信息管理：\n");
	printf("2、修改登入密码：\n");
	printf("3、返回主菜单：\n");
	switch(getch())
			{
				case 49:teacher_information_management();break;
				case 50:printf("修改登入密码\n");change_adm_password(num);;break;
				case 51:printf("返回主菜单\n");return;break;
			}
	}
}

#endif
