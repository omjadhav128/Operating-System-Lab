#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int data[50],r,f;
}Q;
int delqueue(Q*);
void  enqueue(Q*,int);
void tat_and_wt(int at[],int bt[],int toc[],int n)
{
	int tat[10],wt[10],i;
	float x,y;
	for(i=1;i<=n;i++)
	{
		tat[i]=toc[i]-at[i];
		wt[i]=tat[i]-bt[i];
		x+=tat[i];
		y+=wt[i];
	}
	printf("\nProcess info\n");
	printf("\nProcess\t  Arrival Time\t Burst Time\t Turn around time\t Waiting time\n");
	i=1;
	while(i<=n)
	{
		printf("P%d\t  %d\t\t %d\t\t %d\t\t\t %d\n",i,at[i],bt[i],tat[i],wt[i]);
		i++;
	}
	//Calculating the average TAT and WT
	printf("\nAverage Turnaround Time :%.2f",x/n);
	printf("\nAverage Waiting Time    :%.2f\n",y/n);
}
int main()
{
	int p[10],n,at[10],bt[10],i=1,j,k=1,l;
	int op,tag=0,sum,temp,x,y,quantum,rr[20],trr[10],ack[10];
	int fcfs[10],sjfnp[10],sjfp[20],srt[20],tbt[20],toc[10];
	Q s;
	do
	{
		printf("\nMaIN MENU( Process Scheduling )");
		printf("\n1. Get Data");
		printf("\n2. View Data");
		printf("\n3. FCFS");
		printf("\n4. SJF( NP )");
		printf("\n5. SJF( P )");
		printf("\n6. Round Robin");
		printf("\n0. Exit\nEnter the choice :: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	tag=1;
				printf("\nEnter total no. of processes : ");
				scanf("%d",&n);
				if(n<=0)
				{
					printf("\n\tINVALID INPUT\n");
					break;
				}
				printf("\nEnter the Specified Time for following processes");
				bt[0]=at[0]=0;
				tbt[0]=0;
				i=1;
				while(i<=n)
				{
					printf("\nP%d",i);
					while(1)
					{
						printf("\tarrival Time : ");
						scanf("%d",&at[i]);
						if(at[i]<0)
						{
							printf("\nEnter again-\n");
							continue;
						}
						else break;
					}
					while(1)
					{
						printf("\tburst Time   : ");
						scanf("%d",&bt[i]);
						if(bt[i]<0)
						{
							printf("\nEnter again-\n");
							continue;
						}
						else break;
					}
					i++;
				}break;
			case 2:	if(!tag)
				{
					printf("\nPlzzzzzzzzz get Data first\n");
					break;
				}
				printf("\nProcess info\n");
				printf("\nProcess\t  arrival Time\t burst Time\n");
				i=1;
				while(i<=n)
				{
					printf("P%d\t  %d\t\t %d\n",i,at[i],bt[i]);
					i++;
				}break;

			case 3:	if(!tag)		//for FCFS process
				{
					printf("\nPlzzzzzzzzz get Data first\n");
					break;
				}
				for(i=0;i<=10;i++)		//initialise FCFS array
					fcfs[i]=i;
				for(i=1;i<n;i++)
					for(j=i+1;j<=n;j++)
					{
						if(at[fcfs[i]]>at[fcfs[j]])//check for arrival time
						{
							//swaping process by arrival time	
							temp=fcfs[i];				
							fcfs[i]=fcfs[j];
							fcfs[j]=temp;
						}
					}
				//Printing the scheduled process
				printf("\nThe FCFS scheduling of process is : ");
				for(i=1;i<=n;i++)
					printf("| P%d ",fcfs[i]);
				//Printing time of completion
				printf("|\n\t\t\t\t");
				for(i=0;i<=n;i++)
				{
					sum=0;
					for(j=0;j<=i;j++)
						sum+=bt[fcfs[j]];
					printf(" %4d",sum);
					toc[fcfs[i]]=sum;	//calc. time of completion
				}tat_and_wt(at,bt,toc,n);
				break;
			
			case 4:	if(!tag)		//for SJF non 
				{
					printf("\nPlzzzzzzzzz get Data first\n");
					break;
				}
				for(i=0;i<=10;i++)
					sjfnp[i]=i;
				x=1;
				//Searching for first arrived process
				for(i=1;i<n;i++)
					if(at[x]>at[i])
						x=i;
				k=1;
				sjfnp[k++]=x;
				sjfnp[x]=1;
				x=bt[x];			//burst time of first process
				for(i=2;i<n;i++)
				{
					if( at[sjfnp[i]] <= x )//check whether process arrived or not
					{
						for(j=i+1;j<=n;j++)
							//Find the process of lowest burst time
							if( bt[sjfnp[i]] > bt[sjfnp[j]] )
							{
								temp=sjfnp[i];				
								sjfnp[i]=sjfnp[j];
								sjfnp[j]=temp;
							}k++;
					}
					//Calculate burst time of previous Processes
					x=0;
					for(l=1;l<k;l++)
						x+=bt[sjfnp[l]];
				}
				//Printing the scheduled process
				printf("\nThe SJF(Non-pre-emptive) scheduling of process is : ");
				for(i=1;i<=n;i++)
					printf("| P%d ",sjfnp[i]);
				//Printing time of completion
				printf("|\n\t\t\t\t\t\t");
				for(i=0;i<=n;i++)
				{
					sum=0;
					for(j=0;j<=i;j++)
						sum+=bt[sjfnp[j]];
					printf(" %4d",sum);
					toc[sjfnp[i]]=sum;	//calc. time of completion
				}tat_and_wt(at,bt,toc,n);		
				break;
			case 5:	if(!tag)		//for SJF pre-emptive
				{
					printf("\nPlzzzzzzzzz get Data first\n");
					break;
				}
				for(i=0;i<=20;i++)
				{
					sjfp[i]=i;
					srt[i]=i;
				}
				x=1;
				//Searching for first arrived process
				for(i=1;i<n;i++)
					if(at[x]>at[i])
						x=i;
				k=1;
				sjfp[k]=x;
				sum=0;
				//Calculate total Burst time
				for(i=1;i<=n;i++)
				{
					sum+=bt[i];
					tbt[i]=bt[i];
				}
				//Scheduling
				for(i=1;i<=sum;i++)
				{
					tbt[x]-=1;
					y=x;
					if(tbt[x]==0)		//switching the process if it is over
					{
						for(l=1;l<=n;l++)
							if(tbt[l]!=0)
							{
								x=l;
								break;
							}
					}
					for(j=1;j<=n;j++)//switching process to less burst time process
					{
						if(at[j]<=i && tbt[j]>0)
						{
							if(tbt[j]<tbt[x])
								x=j;
						}
					}
					if(y!=x)
					{
						srt[k++]=i;	//saving time while switching process
						sjfp[k]=x;	//saving the scheduled sequence
					}
				}srt[k]=sum;
				//Printing the scheduled process
				printf("\nThe SJF(Pre-emptive) scheduling of process is :     ");
				for(i=1;i<=k;i++)
					printf("| P%d ",sjfp[i]);
				printf("|\n\t\t\t\t\t\t");
				//Printing the time while scheduling
				for(i=0;i<=k;i++)
					printf("%5d",srt[i]);	
				//Calculate the time of completion		
				for(i=0;i<=n;i++)
					for(j=0;j<=k;j++)
						if(sjfp[j]==i)
							toc[i]=srt[j];
				tat_and_wt(at,bt,toc,n);
				break;
			case 6:if(!tag)		//Round Robin
				{
					printf("\nPlzzzzzzzzz get Data first\n");
					break;
				}
				printf("\nEnter the value of Quantum :: ");
				scanf("%d",&quantum);
				//Printing the scheduled process
				printf("\nThe Round Robin scheduling of process is :  ");
				sum=0;s.f=s.r=-1;
				//Initialising the variables
				for(i=1;i<=n;i++)
				{
					tbt[i]=bt[i];
					trr[i]=i;
					sum+=bt[i];		//calculate total burst time
					ack[i]=0;
				}
				//Sorting the process according to arrival time
				for(i=1;i<n;i++)
				{
					for(j=i+1;j<=n;j++)
					{
						if(at[trr[i]]>at[trr[j]])
						{
							//Swap the processess
							temp=trr[i];
							trr[i]=trr[j];
							trr[j]=temp;
						}
					}
				}
				x=1;
				k=i=0;
				ack[trr[x]]=1;
				srt[k++]=0;
				//Scheduling the process
				while(i<sum)
				{			
					if(quantum < tbt[trr[x]])
					{
						i+=quantum;
						tbt[trr[x]]-=quantum;
						printf("| P%d ",trr[x]);
						rr[k]=trr[x];
						srt[k++]=i;
					}
					else
					{
						i+=tbt[trr[x]];
						tbt[trr[x]]=0;
						printf("| P%d ",trr[x]);
						rr[k]=trr[x];
						srt[k++]=i;
					}
					for(j=1;j<=n;j++)			//Inserting the process in queue first time
					{
						if(i>=at[trr[j]] && ack[trr[j]]!=1)
						{
							ack[trr[j]]=1;
							enqueue(&s,trr[j]);
						}
					}
					if(tbt[trr[x]]!=0)
						enqueue(&s,trr[x]);		
					temp=delqueue(&s);			//removing the process from queue
					for(j=1;j<=n;j++)
					{
						if(temp==trr[j])
						{
						    x=j;
						    break;
						}
					}
				}
				printf("|\n\t\t\t\t\t");
				//Printing the time while scheduling
				for(i=0;i<k;i++)
					printf("%5d",srt[i]);	
				//Calculate the time of completion		
				for(i=1;i<=n;i++)
					for(j=1;j<=k;j++)
						if(rr[j]==i)
							toc[i]=srt[j];
				tat_and_wt(at,bt,toc,n);
				break;							
			case 0:	exit(0);
			default:printf("\nINVaLID INPUT \n");
		}
	}while(op);
	return 0;
}
int delqueue(Q *q)				//Funtion for deletion of element from queue
{
	int p;
	if(q->f!=-1)
	{
		p=q->data[q->f];
		if(q->r==q->f)
			q->r=q->f=-1;
		else
			q->f+=1;
		return(p);
	}
}
void enqueue(Q *q,int p)		//Function for insertig element in queue
{	
	if(q->r==-1)
		q->r=q->f=0;
	else
		q->r+=1;
	q->data[q->r]=p;
}
