#include <stdio.h>
void printsub(int sub[],int subsize){
    
    for(int i=0;i<subsize;i++){
        printf("%d ",sub[i]);
    }
    printf("\n");
}

void findsub(int arr[],int n, int index,int sub[],int subsize,int sum,int target){
    if(sum==target){
        printsub(sub,subsize);
        return;
    }
    if(sum>target || index==n){
        return;
    }
    sub[subsize]=arr[index];
    findsub(arr,n,index+1,sub,subsize+1,arr[index]+sum,target);
    findsub(arr,n,index+1,sub,subsize,sum,target);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=10;
    int sub[100];
    findsub(arr,n,0,sub,0,0,target);
    return 0;
}
