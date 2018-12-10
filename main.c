#include"interface.h"
#include"common.h"
void xsglxt(void)
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
			case 53:return ;;break;//5.退出

		}
	}
}


int main()
{
	FILE* fpp1=fopen("admin.dat","r");
	fseek(fpp1,0,SEEK_END);
	long j=ftell(fpp1);
	rewind(fpp1);
	adm_count=j/56;
	for(int i=0;i<=adm_count;i++)
	{
		fread(&admin[i],56,1,fpp1);
	}
	FILE* fap1=fopen("student.dat","r");
	fseek(fap1,0,SEEK_END);
	long j1=ftell(fap1);
	rewind(fap1);
	stu_count=j1/64;
	for(int i=0;i<=stu_count;i++)
	{
		fread(&student[i],64,1,fap1);
	}

	FILE* fwp1=fopen("teacher.dat","r");
	fseek(fwp1,0,SEEK_END);
	long j2=ftell(fwp1);
	rewind(fwp1);
	teacher_count=j2/60;
	for(int i=0;i<=teacher_count;i++)
	{
		fread(&teacher[i],60,1,fwp1);
	}


	xsglxt();
	FILE* fap=fopen("student.dat","w");
	for(int i=0;i<stu_count;i++)
	{
		fwrite(&student[i],sizeof(student[0]),1,fap);
	}
	FILE* fwp=fopen("teacher.dat","w");
	for(int i=0;i<teacher_count;i++)
	{
		fwrite(&teacher[i],sizeof(teacher[0]),1,fwp);
	}
	FILE* fpp=fopen("admin.dat","w");
	for(int i=0;i<adm_count;i++)
	{
		fwrite(&admin[i],sizeof(admin[0]),1,fpp);
	}
}
