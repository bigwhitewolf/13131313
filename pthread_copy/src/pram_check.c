#include<pthread_copy.h>

int pram_check(int argc,const char* sfile,int pronum)
{
	if(argc <3)
	{
		printf("ERROR:缺少必要参数,请重试!\n");
		exit(0);
	}
	if((access(sfile,F_OK))!=0)
	{
		printf("ERROR:源文件不正确或不存在!\n");
		exit(0);
	}
	if(pronum <= 0 || pronum >100)
	{
		printf("ERROR:线程数量不允许小于0并大于100!\n");
		exit(0);
			
	}
	return 0;
}
