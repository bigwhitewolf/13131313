#include<pthread_copy.h>

void copy(const char* sfile,const char* dfile,int blocksize,int pos)
{
	
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));
	ssize_t readlen;

	int std = open(sfile,O_RDONLY);
	int dfd = open(dfile,O_RDWR|O_CREAT,0664);


	//修改偏移量
	lseek(std,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);
	
	//拷贝读写
	readlen = read(std,buffer,sizeof(buffer));
	write(dfd,buffer,readlen);
	close(std);
	close(dfd);

	return ;
}
