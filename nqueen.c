//N Queen's problem
#include<stdio.h>
#define TRUE 1
#define FALSE 0
// To check for vertical and diagonal attack
int place(int x[],int k){
	int i;
	for(i=1;i<k;i++){
		if((x[i]==x[k]) || (i-x[i]==k-x[k]) || (i+x[i]==k+x[k])){
			return FALSE;
		}
	}
	return TRUE;
}
//To display the solution
void display(int n,int x[]){
	int i,j;
	char c[10][10];
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			c[i][j]='X';
		}
	}
	for(i=1;i<=n;i++)
		c[i][x[i]]='Q';
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%c\t",c[i][j]);
		}
		printf("\n");
	}
}
//Places all n queens using backtracking
void n_queens(int n){
	int x[10],count=0,k=1;
	x[k]=0;
	while(k!=0){
		x[k]=x[k]+1;
		while((x[k]<=n) && (!place(x,k)))
			x[k]=x[k]+1;
		if(x[k]<=n){
			if(k==n){
				count++;
				printf("Solution %d is\n",count);
				display(n,x);
			}
			else{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
}
void main(){
	int n;
	printf("Enter value of n\n");
	scanf("%d",&n);
	n_queens(n);
}
