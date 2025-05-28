//PROGRAM to find SHORTEST DISTANCE SHORTEST PATH from a given source to all the vertices in
//a weighted,directed graph using DIJKSTRA'S ALGORITHM

#include<stdio.h>
#define max 20

void dijkstra();
void main()
{
	int i,j,n,src,cost[max][max];
	
	printf("Enter the no. of vertices in the graph\n");
	scanf("%d",&n);
	
	printf("Enter the cost adjacency matrix\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}

	printf("\n");
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	dijkstra(n,cost,src);
}

void dijkstra(int n,int cam[max][max],int src)
{
	int i,j,min,u,v;
	int d[max],visited[max];
	
	for(i=0;i<n;i++)
	{	d[i]=cam[src][i];
		visited[i]=0;
	}
	visited[src]=1;
	
	for(i=0;i<n;i++)
	{
		min=999;
		u=-1;
		
		for(j=0;j<n;j++)
		{
			if(visited[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		visited[u]=1;
		for(v=0;v<n;v++)
		{
			if(visited[v]==0 && d[u]+cam[u][v]<d[v])
			{	
				d[v]=d[u]+cam[u][v];
			}
		}
	}
	printf("The shortest dist path from src to various vertices is\n");
	for(v=0;v<n;v++)
	{	
		if(d[v]==999)
		printf("Vertex %d of the graph is unreachable from source\n",v);
		else
		printf("Shortest path value from Source=%d to Vertex=%d is =%d\n",src,v,d[v]);
	}
		
}
