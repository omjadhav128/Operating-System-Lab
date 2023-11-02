#include<stdio.h>

void main()
{
	printf("Enter how many numbers: ");
	int no,i,temp;
    scanf("%d",&no);

    int arr[no];
      printf("\nEnter %d numbers ",no);
	for(i=0;i<no;i++)
	{
	scanf("%d",&arr[i]);
	}
    int j,k;
    for(j=0;j<no;j++)
    {
        for(k=0;k<no-j-1;k++)
        {
            if(arr[k]>arr[k+1])



            {
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
    }

    printf("\nSorted Array: Ascending\n");
    for(i=0;i<no;i++)
    {
        printf("%d ",arr[i]);


    }
 for(j=0;j<no;j++)
    {
        for(k=0;k<no-j-1;k++)
        {
            if(arr[k]<arr[k+1])
            {
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
    }
printf("\nSorted Array: Descending\n");
    for(i=0;i<no;i++)
    {
        printf("%d ",arr[i]);
    }
printf("\n");
}
