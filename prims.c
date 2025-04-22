// Program to find the Minimum Cost Spanning Tree for a Given Graph using the Prim's Algorithm
#include<stdio.h>
void main()
{
int i,j,n;
int ne=1,a,b,u,v;
int mincost=0;
int cost[10][10];
int visited[10]={0};
int min;

printf("Enter the no. of vertices in the graph\n");
scanf("%d",&n);

for(i=1;i<=n;i++)
 {
	for(j=1;j<=n;j++)
	 {
		printf("Enter the edge %d,%d\n",i,j);
	  scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		cost[i][j]=999;
	 }
 }
printf("The matrix entered is \n");
for(i=1;i<=n;i++)
 {
	for(j=1;j<=n;j++)
	 {
	 printf("%d\t",cost[i][j]);
	 }
	printf("\n");
 }											//Mat end

visited[1]=1;
while(ne<n)
	{
	for(i=1,min=999;i<=n;i++)

		for(j=1;j<=n;j++)
		{	if(cost[i][j]<min)
			{	if(visited[i]!=0)
				{	min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
			if(visited[u]==0||visited[v]==0)
			{printf("Edge %d(%d,%d) cost %d\n",ne++,a,b,min);
			 visited[b]=1;
			 mincost+=min;
			}
		cost[b][a]=cost[a][b]=999;
	
	}
printf("The total cost of the MCST is = %d \n",mincost);
}
				
























 

