#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid,i;
	pid = fork();
	if(pid==0)
	{
		printf("\nChild process. Child id is %d \n",getpid());
		printf("\nChild process. parent id is %d \n",getppid());	
	}
	else
	{
		//zombie state
		system("ps -el | grep Z");
		i=wait(0);
		printf("\n pid of child terminated process is %d\n",i);

printf("\nParent process. Parent id is: %d\n",getpid());
printf("\nParent process. Parent's process id is %d\n",getppid());
	sleep(10);		
	
	}
}
