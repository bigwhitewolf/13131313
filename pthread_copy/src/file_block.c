#include<pthread_copy.h>

int file_block(const char * sfile,int pronum)
{
	/*打开文件获取大小*/
	int fd = open(sfile,O_RDONLY);
	int fsize = lseek(fd,0,SEEK_END);

	/*计算任务量*/
	if(fsize % pronum == 0)
	{
		return fsize / pronum;	
	}
	else
	{
		return fsize / pronum +1;	
	}
}
