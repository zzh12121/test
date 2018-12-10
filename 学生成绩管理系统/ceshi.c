#include"common.h"
int main()
{
	FILE* fap=fopen("admin.dat","r");
	fseek(fap,0,SEEK_END);
	long i=ftell(fap);
	printf("%ld\n",i);
}
