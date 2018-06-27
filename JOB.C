#include<stdio.h>
#include<conio.h>
int profit[50],deadline[50],select[50];
void job(int n,int max)
{
	int i,j,temp,total=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(profit[j]<=profit[j+1])
			{
				temp=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=temp;

				temp=deadline[j];
				deadline[j]=deadline[j+1];
				deadline[j+1]=temp;

			}
		}
	}//sorting end
	for(i=0;i<n;i++)
	{
		if(deadline[i]<=max)
		{
			for(j=deadline[i];j>=1;j--)
			{
				if(select[j]!=1)
				{
					select[j]=1;
					total+=profit[i];
					break;
				}

			}
		}
	}
	printf("\nTotal profit :=%d",total);
}
void main()
{
	int i,n,max=0;
	clrscr();
	printf("\tEnter no of jobs :=");
	scanf("%d",&n);
	printf("\nEnter profit and deadline :=");
	for(i=0;i<n;i++)
	{
		printf("\np[%d]:=",i);
		scanf("%d",&profit[i]);
		printf("d[%d]:=",i);
		scanf("%d",&deadline[i]);
		select[i]=0;
		if(deadline[i]>=max)
			max=deadline[i];
	}
	job(n,max);
	getch();
}