#include <stdio.h>

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

void floyd(int n,int a[10][10]){
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main(){
    int i,j,a[10][10],n;
    
    printf("enter the no of vertex: ");
    scanf("%d",&n);
    
    printf("enter am\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    floyd(n,a);
    
    printf("shortest path matrix\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d \t",a[i][j]);
        }
    }
}
