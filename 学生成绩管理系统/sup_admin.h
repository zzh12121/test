#ifndef SUP_ADMIN_H
#define SUP_ADMIN_H
#include"common.h"
void adm_add(void);//添加或删除管理员函数
int adm_sec_num(int num);//通过工号查找编号
void super_administrators_interface_son(void);//界面函数
int adm_sec_num(int num)
{
	for(int i=0;i<adm_count;i++)
	{
		if(admin[i].state!='2' && num == admin[i].number)
		return i;
	}
	return -1;
}
void replace_adm(void)
{
	puts("输入要重置密码的管理员的工号:");
	int num=0;
	scanf("%d",&num);
	getchar();
	int index=adm_sec_num(num);
	if(-1==index)
	{
		show_msg("查无此管理员",1,0);
		anykey_continue();
	}
	else
	{
		strcpy(admin[index].code,"123456");
		show_msg("重置密码成功",1,1);
		anykey_continue();
	}
	
}
void unlock_adm(void)
{
	puts("输入要解锁的管理员的工号:");
	int num=0;
	scanf("%d",&num);
	getchar();
	int index=adm_sec_num(num);
	if(-1==index)
	{
		show_msg("查无此管理员",1,0);
		anykey_continue();
	}
	else
	{
		admin[index].state='0';
		show_msg("解锁成功",1,1);
		anykey_continue();
	}
}
void list_adm(void)
{
	system("clear");
	for(int i=0;i<adm_count;i++)
	{
		if(admin[i].state=='2')
		continue;
		else
		printf("姓名：%s 工号：%d\n",admin[i].name,admin[i].number);
	}
	anykey_continue();
	
}
void super_administrators_interface_son(void)
{
	while(1)
	{
		system("clear");
		puts("1.添加或删除管理员");
		puts("2.重置管理员密码");
		puts("3.解锁管理员账号");
		puts("4.显示所有管理员");
		puts("5.返回上级菜单");
		switch(getch())
		{
			case 49:adm_add();;break;
			case 50:replace_adm();;break;
			case 51:unlock_adm();;break;
			case 52:list_adm();;break;
			case 53:return;		
		}
	}
}
void adm_add(void)
{
	system("clear");
	puts("1.添加管理员");
	puts("2.删除管理员");
	puts("3.返回上级菜单");
	while(1)
	{
		int num=0;
		switch(getch())
			{
				case 49:
						system("clear");
						printf("----------增加管理员---------\n");
						adm_count++;
						int num=300000,sex=0;
						admin[adm_count-1].state='0';
						strcpy(admin[adm_count-1].code,"123456");
						admin[adm_count-1].number=num+adm_count;

						printf("请输入姓名：\n");
						gets(admin[adm_count-1].name);
						while(1)
						{	
							printf("请输入性别1.男 2.女\n");
							sex=getch();
							if(sex==49||sex==50)
							{
								printf("%s\n",sex==49?"男":"女");
								admin[adm_count-1].sex=sex;
								break;
							}
							else
							show_msg("性别输入错误！",1,0);
						}
						printf("请输入出生年份：\n");
						scanf("%d",&admin[adm_count-1].year);
						show_msg("添加成功！",1,1);
						sleep(1);	
				return;
						;break;
				case 50:
				puts("请输入要删除的管理员的工号：");
				scanf("%d",&num);
				getchar();
				int index=adm_sec_num(num);
				if(-1==index)
				{
					show_msg("查无此管理员!",1,0);
					anykey_continue();
					return;
				}
				else
				{
					admin[index].state='2';
					show_msg("删除成功!",1,1);
					anykey_continue();
					return;
				}
						;break;	
				case 51:return;break;
			}
	}
};
#endif




























