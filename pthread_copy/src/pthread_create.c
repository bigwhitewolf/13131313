#include<pthread_copy.h>

typedef struct
{
	const char* sfile;
	const char* dfile;
	int blocksize;
	int pos;
}T;

void *jobs(void * arg)
{	

	T* tt = (T*)arg;
	char str_blocksize[50];
	char str_pos[50];
	bzero(str_blocksize,sizeof(str_blocksize));
	bzero(str_pos,sizeof(str_pos));
	sprintf(str_blocksize,"%d",tt->blocksize);
	sprintf(str_pos,"%d",tt->pos);
	printf("Copy Child Pthread Tid 0x%x Copy_Pos %d Copy_size %d\n",(unsigned int)pthread_self(),tt->pos,tt->blocksize);
	copy(tt->sfile,tt->dfile,tt->blocksize,tt->pos);
	
	free(tt);
	tt = NULL;
	return 0;
}

void thread_create(const char* sfile,const char* dfile,int blocksize,int pronum)
{
	int flags;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	//设置分离态
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_t tid;
	int err;
	for(flags=0;flags<pronum;flags++)
	{
		T* text = (T*)malloc(sizeof(T));
		text->sfile = sfile;
		text->dfile = dfile;
		text->blocksize = blocksize;
		text->pos = flags*blocksize;
		if((err=pthread_create(&tid,&attr,jobs,(void *)text))>0)
		{
			printf("thread create error:%s\n",strerror(err));
			exit(0);
		}		
	}
	
	pthread_attr_destroy(&attr);
 	return ;
}
