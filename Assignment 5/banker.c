#include<stdio.h>

#include<stdlib.h>
#include<sys/syscall.h>
#include<pthread.h>
#include<semaphore.h>
void main()
{
int 
allocated[20][20],max[20][20],available[20]={0},need[20][20],total[20];
int finish[20]={0};
int cntProcess,cntRes,process,res,flag,execflag,executed;

printf("Enter no. of processes: ");

scanf("%d",&process);
printf("\nEnter no. of resources: ");

scanf("%d",&res);
printf("Enter the maximum instances of each resource:\n");
for (cntRes=0;cntRes<res;cntRes++)
{
printf("\n\tNo. of instances of resource #%d: ",cntRes);

scanf("%d",&total[cntRes]);
}
printf("\nEnter the maximum requriment of each process:\n");
for(cntProcess=0;cntProcess<process;cntProcess++)
{
printf("\nProcess #%d:\n",cntProcess);
for(cntRes=0;cntRes<res;cntRes++)
{
printf("\n\tRequirment for resource #%d; ",cntRes);

scanf("%d",&max[cntProcess][cntRes]);
}
}
printf("\nEnter the current allocation for each process: \n");
for(cntProcess=0;cntProcess<process;cntProcess++)
{
printf("\nProcess #%d:\n",cntProcess);
for(cntRes=0;cntRes<res;cntRes++)
{
printf("\n\tAllocation for resoucre #%d: ",cntRes);

scanf("%d",&allocated[cntProcess][cntRes]);
}
}
/*calculate available instances of each resource*/
for(cntRes=0;cntRes<res;cntRes++)
{//Sum of allocated instances
for(cntProcess=0;cntProcess<process;cntProcess++)
{
available[cntRes]+=allocated[cntProcess][cntRes];
}
//subtract from totalno. of instances
available[cntRes]=total[cntRes]-available[cntRes];
}
printf("\nThe available instances of each resource are:\n");
for(cntRes=0;cntRes<res;cntRes++)
{
printf("\nResource #%d: %d",cntRes,available[cntRes]);
}
/*calculate the need matrix*/
for(cntProcess=0;cntProcess<process;cntProcess++)
{
for(cntRes=0;cntRes<res;cntRes++)
{
need[cntProcess][cntRes]=max[cntProcess][cntRes]-allocated[cntProcess]
[cntRes];
}
}
printf("\n\nThe NEED matrix is:\n\n");
for(cntProcess=0;cntProcess<process;cntProcess++)
{
for(cntRes=0;cntRes<res;cntRes++)
{
printf("\t%d",need[cntProcess][cntRes]);
}
printf("\n\n");
}

printf("\nThe processes are executed in the foll. sequence:\n\n");
executed=0; //init no. of processes executed
do
{
for(cntProcess=0,execflag=0;cntProcess<process;cntProcess++)
{
flag=0; //Reset flag
if(finish[cntProcess]!=0)
continue;
else
{
for(cntRes=0;cntRes<res;cntRes++)
{
if(need[cntProcess][cntRes]>available[cntRes])
{
//check for unallowed condition
flag=1;
break;
}
}
if(flag==0)
{
printf("\tP%d",cntProcess);
finish[cntProcess]=1;
for(cntRes=0;cntRes<res;cntRes++)
{
available[cntRes]+=allocated[cntProcess][cntRes];
}
execflag=1;
executed++;
}
}
}
if(execflag==0)
{//Loop has executed for all processes, but none executed!
printf("\n\nThe system is in an UNSAFE state!");
break;
}
}
while(executed<process);

}

