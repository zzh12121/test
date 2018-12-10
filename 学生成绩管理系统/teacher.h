#ifndef TEACHER_H
#define TEACHER_H
#include "common.h"
#define SUM_SEC 365*24*3600
int _find_num( int key);//寻找学号
char *_find_name(char* name,char* key);//寻找姓名
void _show_stu(int key,int b);//显示信息
void add_stu_more(void);//导入学生
void add_stu(void);//增加学生(可能需要修改)
void del_stu(void);//删除学生
void modify_stu(void);//修改学生信息
void reset_code(void);//重置密码
void unlock_account(void);//解锁账号
void find_name_stu(void);//按姓名查找
void show_01_stu(void);//显示在校学生
void show_2_stu(void);//显示离校学生
void add_score_more(void);//导入分数
void add_score(void);//添加分数
void modify_score(void);//修改分数
void sort_score(void);//按成绩排序
void find_name_num_score(void);//按学号查分数
void teacher_interface_son(int i);//教师界面
void student_achievement_management(void);//学生成绩管理
void student_information_management(void);//学生信息管理
void change_tea_password(int i);
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
		if(0==strcmp(student[i].name,name) && (student[i].state=='0'|| student[i].state=='1'))
		{
			key[count]=i+'0';
			count++;
		}
	}
	key[count]='\0';
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
void add_stu_more(void)//导入学生
{

	system("clear");
	puts("---------导入学生---------");
	FILE* fp=fopen("add_stu.txt","r");
	if(NULL==fp)
	{
		perror("fopen");
		return ;
	}	
	while(1)
	{
		int num=100000;
		stu_count++;
		fscanf(fp,"%s %d %c",student[stu_count-1].name,&student[stu_count-1].year,&student[stu_count-1].sex);
		if(feof(fp)==1)
		{
			stu_count--;
			break;
		}
		student[stu_count-1].number=num+stu_count;
		strcpy(student[stu_count-1].code,"123456");
		student[stu_count-1].state='0';
	}	
	fclose(fp);
		show_msg("添加成功！按任意键返回！",1,1);
		getch();
}
void add_stu(void)//增加学生
{
	system("clear");
	printf("----------增加学生---------\n");
	stu_count++;
	int num=100000;int sex=0;
	student[stu_count-1].number=num+stu_count;
	strcpy(student[stu_count-1].code,"123456");
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
		show_msg("性别输入错误！",1,0);
	}
	student[stu_count-1].state='0';
	printf("请输入出生年份：\n");
	scanf("%d",&student[stu_count-1].year);
	show_msg("添加成功！",1,1);
	sleep(1);	
}
void del_stu(void)//删除学生
{
	system("clear");
	int key=0;int num=0;int yes=0;
	printf("----------删除学生---------\n");
	printf("请输入需删除学生的学号\n");
	while(1)
	{
		scanf("%d",&key);
		printf("k=%d\n",key);
		getchar();
		num=_find_num(key);
		if(-1==num)
		{
			show_msg("该学生学号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);	
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}	
		else
		{
			_show_stu(num,0);
			show_msg("是否继续删除？y/n",1,2);
			yes=getch();
			if(yes==121 || yes==89)
			{	
				student[num].state='2';
				show_msg("删除成功！",1,1);
				break;
			}
			else
			{
				printf("输入学号：\n");
			}
		}	
	}
	sleep(1);
}
void modify_stu(void)//修改学生信息
{
	system("clear");
	int key=0;int num=0;char name[20];int year=0;
	printf("----------修改信息---------\n");
	printf("请输入需修改学生的学号\n");
		scanf("%d",&key);
		getchar();
		num=_find_num(key);
		if(-1==num)
		show_msg("该学生学号不存在！",1,0);
		else
		{
			printf("输入修改的姓名：\n");
			strcpy(student[num].name,gets(name));
			printf("输入出生年份：\n");
			scanf("%d",&year);
			student[num].year=year;
			show_msg("修改成功！",1,1);		
		}
	sleep(1);
}
void reset_code(void)//重置密码
{
	system("clear");
	int key=0;int num=0;
	printf("----------重置密码----------\n");
	printf("请输入需要重置密码学生的学号\n");
	scanf("%d",&key);
	getchar();
	num=_find_num(key);
	if(-1==num)
		show_msg("该学生学号不存在！",1,0);
	else
	{
		strcpy(student[num].code,"123456");
		show_msg("修改成功！",1,1);
	}
	sleep(1);
}
void unlock_account(void)//解锁账号
{
	system("clear");
	int key=0;
	printf("----------解锁账号----------\n");
	printf("请输入需要解锁账号的学生的学号:\n");
	scanf("%d",&key);
	getchar();
	for(int i=0 ;i<stu_count;i++)
	{
		if(student[i].number==key && student[i].state == '1')
		{
			student[i].state= '0';
			show_msg("解锁成功！",1,1);
			sleep(1);
			return;
		}
	}	
	show_msg("该账号不存在或未被锁定!",1,0);	
	show_msg("任意键结束显示",1,2);
	getch();
	
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
		if(0==num)
		{
			show_msg("查无此人!",1,0);
			anykey_continue();
			break;
		}
		for(int i=0;i<num;i++)
		{
			printf("学号：%4d ",student[key[i]-'0'].number);
			printf("性别：%3s ",'1'==student[key[i]-'0'].sex?"男":"女");
			printf("姓名：%4s \n",student[key[i]-'0'].name);
		}
		show_msg("是否结束查找？y/n",1,2);
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
	show_msg("任意键结束显示！",1,2);
	getch();
}
void show_2_stu(void)//显示离校学生
{
	system("clear");
	char key[500];int num=0;
	printf("----------显示离校学生---------\n");
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
	show_msg("任意键结束显示",1,2);
	getch();
}
void student_information_management(void)//学生信息管理
{
	while(1)
	{
		system("clear");
		printf("-------------学生信息管理--------------\n");
		puts("0.批量导入学生");
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
				case 48: add_stu_more();break;
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
void add_score_more(void)
{
	system("clear");
	puts("---------导入学生成绩---------");
	FILE* fp=fopen("add_score.txt","r");
	int n=0;
	if(NULL==fp)
	{
		perror("fopen");
		return ;
	}	
	while(1)
	{
		fscanf(fp,"%d%d%d%d",&score[n].num,&score[n].chinese,&score[n].math,&score[n].English);
		if(feof(fp)==1)
		{
			break;
		}
		n++;
	}	
	fclose(fp);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<stu_count;j++)
		{
			if(score[i].num==student[j].number)
			{
				student[j].chinese=score[i].chinese;
				student[j].math=score[i].math;
				student[j].English=score[i].English;
			}
		}
	}
		show_msg("添加成功！按任意键返回！",1,1);
		getch();
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
		{
			show_msg("该学生学号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
			
		}
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
			show_msg("是否继续输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}	
	}
	sleep(1);
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
		{
			show_msg("该学生学号不存在！",1,0);
			show_msg("是否重新输入？y/n",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}		
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
			show_msg("是否继续修改？y/n",1,2);
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
	int key=0,yes;
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
		{
			show_msg("该学生学号不存在！",1,0);
			show_msg("是否重新输入？y/n,",1,2);
			yes=getch();
			if(121==yes || 89==yes)
			{	continue; }
			else
			{   break;    }	
		}
		else
		{
			_show_stu(num,1);
			show_msg("任意键结束显示！",1,2);
			getch();
			break;
		}
	}
}
void sort_score(void)
{
	system("clear");
	int count_c[500]={},count_m[500]={},count_e[500]={},count[500]={};
	for(int i=0;i<stu_count;i++)
	{
		if(student[i].state!='2')
		{
			for(int j=0;j<stu_count;j++)
			{
				if(student[j].state!='2')
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
	for(int i=0;i<stu_count;i++)
	{
		
		if(student[i].state!='2')
		{
			printf("%6d\t",student[i].number);
			printf("%s\t",student[i].name);
			printf("%6d（%3d）\t",count_c[i]+1,student[i].chinese);
			printf("%10d（%3d）\t",count_m[i]+1,student[i].math);
			printf("%6d（%3d）\t",count_e[i]+1,student[i].English);
			printf("%7d（%3d）\n",count[i]+1,student[i].chinese+student[i].math+student[i].English);
		}
	}
	show_msg("任意键结束显示！",1,2);
	getch();	

}
void student_achievement_management(void)//学生成绩管理
{
	while(1)
	{
		system("clear");
		printf("------------学生成绩管理---------------\n");
		puts("1.单个录入成绩");
	    puts("2.值导入成绩");
	    puts("3.修改学生成绩");
	    puts("4.根据学号或姓名查找成绩");
	    puts("5.按各科分数或部分排序");
	    puts("6.返回上层");
	    switch(getch())
	    {
			case 49: add_score();break;//单个录入成绩
			case 50: add_score_more();break;//指导入
			case 51: modify_score();break;//修改学生成绩 
	 		case 52: find_name_num_score();break;//根据学号或姓名查询学生成绩 
			case 53: sort_score();break;//按各科分数和部分排序
			case 54: return;//返回上层
		}
	}	
}
void change_tea_password(int i)
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
			strcpy(teacher[i].code,new_code);
			puts("输入成功");
			anykey_continue();
			break;
		}
}
void teacher_interface_son(int i)
{
	if(0==strcmp(teacher[i].code,"123456"))
	{
		system("clear");
		while(1)
		{
			show_msg("第一次登入请修改密码，密码不能为初始值",1,2);
			printf("请输入新密码：");
			char new_code[20];
			password_input(new_code);
			if(0==password_rule(new_code))
			{
				show_msg("密码格式错误",1,2);
				continue;
			}
			strcpy(teacher[i].code,new_code);
			show_msg("输入成功",1,1);
			anykey_continue();
			break;
		}
	}
	while(1)
	{
	system("clear");
	printf("--------教师界面--------\n");
	printf("工号：%d\n",teacher[i].number);
	printf("性别：%s\n",teacher[i].sex=='1'?"男":"女");
	printf("姓名：%s\n",teacher[i].name);
	printf("年龄：%ld\n",(time(NULL)/(SUM_SEC))+1970-teacher[i].year);
	printf("工龄：%ld\n",(time(NULL)/(SUM_SEC))+1970-teacher[i].work_year);
	printf("1、学生信息管理：\n");
	printf("2、学生成绩管理：\n");
	printf("3、修改登入密码：\n");
	printf("4、返回主菜单：\n");
	switch(getch())
			{
				case 49:student_information_management();break;
				case 50:student_achievement_management();break;
				case 51:printf("修改登入密码\n");change_tea_password(i);;break;
				case 52:printf("返回主菜单\n");return;break;
			}
	}
}
#endif
