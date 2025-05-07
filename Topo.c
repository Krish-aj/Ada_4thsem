#include<stdio.h>

void indig(int n,int a[20][20],int iodr[10])
{
	int sum,i,j;
	
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i][j];
		}
		iodr[j]=sum;
	}
}

void topo(int n,int a[20][20])
{
	int iodr[20],u,t[20],s[20],top=-1,v,i,k=0;
	indig(n,a,iodr);
	for(i=0;i<n;i++)
	{
		if(iodr[i]==0)
		{
			s[++top]=i;
		}
	}
	while(top!=-1)
	{
		u=s[top--];
		t[k++]=u;
		for(v=0;v<n;v++)
		{	
			if(a[u][v]==1)
			{
				iodr[v]--;
				if(iodr[v]==0)
					s[++top]=v;
			}
		}
	}
	printf("The topo oder is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",++t[i]);
	}
	printf("\n");
}

void main()
{
	int n,a[20][20],i,j;
	printf("Enter no of vertices\n");
	scanf("%d",&n);
	printf("Enter AM\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("Enter %d,%d \t:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Mat entrd is\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	topo(n,a);
	
	
}
