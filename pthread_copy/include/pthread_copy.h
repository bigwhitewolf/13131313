#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>
#include<pthread.h>


int pram_check(int argc,const char* sfile,int pronum);

int file_block(const char * sfile,int pronum); // 返回blocksize,表示拷贝大小;

void copy(const char * sfile,const char * dfile,int blocksize,int posi);

void thread_create(const char * sfile,const char * dfile,int blocksize,int pronum);

