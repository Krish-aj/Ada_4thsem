/*program to construct minimum cost spanning tree using kruskal's algorithm*/

#include<stdio.h>
#define max 20
void kruskal(int n,int cost[max][max]);
int find(int v,int forest[max]);
void merge(int i,int j,int forest[max]);

void main()
{
	int n,i,j,cost[max][max];
	printf("enter the number of vertices");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	printf("the cam is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	kruskal(n,cost);
}

void kruskal(int n,int cost[max][max])
{
	int i,j,u,v,k,min,sum,edge_index,count,forest[max],span_tree[max][max];
	for(i=0;i<n;i++)
	{
		forest[i]=i;
	}
	sum=0;
	edge_index=0;
	count=0;
	while(count<n-1)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]!=0 && cost[i][j]<=min)
				{
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
		if(min==999)break;
		i=find(u,forest);
		j=find(v,forest);
		if(i!=j)
		{
			span_tree[edge_index][0]=u;
			span_tree[edge_index++][1]=v;
			sum=sum+min;
			count++;
			merge(i,j,forest);
		}
		cost[u][v]=cost[v][u]=999;
		if(count==n-1)
		{
			printf("the cost of mcst is %d\n",sum);
			for(k=0;k<n-1;k++)
			{
			printf("Edge:(%d---%d)\n",++span_tree[k][0],++span_tree[k][1]);
			}
		}
	}
}

int find(int v,int forest[max])
{
	while(forest[v]!=v)
		v=forest[v];
	return v;
}

void merge(int i,int j,int forest[max])
{
	if(i<j)
		forest[j]=i;
	else
		forest[i]=j;
}
