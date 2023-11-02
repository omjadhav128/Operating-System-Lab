#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int pid;
	pid = fork();
	if(pid==0)
	{
		//orphan State
		printf("\n Before Orphan");
		printf("\nChild process. Child id is %d \n",getpid());
		printf("\nChild process. Parent id is %d\n",getppid());
		printf("\n");
		sleep(5);
		printf("\n After Orpann");
		printf("\nChild process id is %d \n",getpid());
		printf("\nChild Process. Parent id is %d",getppid());
	}
	else
	{
		printf("\nParent process. Parent id is %d \n",getpid());
		printf("\nParent process. Parent's Parent id is %d \n",getppid());
	}
}
