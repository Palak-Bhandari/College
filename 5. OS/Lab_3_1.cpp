#include<stdio.h>
#include<unistd.h>
int main()
{
	int id;
	printf("Hello world!\n");
	id = fork();
	if(id>0)
	{
		/*Parent Process*/
		printf("This ia a parent section[process id:%d].\n",getpid());
	}
	else if(id==0)
	{
		printf("Fork Created [process id:%d].\n",getpid());
		printf("Fork parent process id: %d.\n",getpid());
	}
	else
	{
		/*Fork creation failed*/
		printf("Fork creation failed");	
	}
}
