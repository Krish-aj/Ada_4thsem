#include<stdio.h>
#define max 20

int maximum(int a,int b);
void ks(int n,int m,int w[max],int p[max]);

void main()
{
	int n,m,i,w[max],p[max];
	printf("Enter no. of objects\n");
	scanf("%d",&n);
	printf("Enter ks capacity\n");
	scanf("%d",&m);
	printf("Enter the weights and profits of objects\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d%d",&w[i],&p[i]);

	}
	ks(n,m,w,p);

}

void ks(int n,int m,int w[max],int p[max])
{
	int i,j,v[max][max];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
				v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=maximum(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("The Matrix is\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%d\t",v[i][j]);
		}
		printf("\n");
	}
	printf("The optimal sol is %d\n",v[n][m] );
}

int maximum(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

