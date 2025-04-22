#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid,int high){
    int i,j,k,b[300000];
    i=k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=high){
        b[k++]=a[j++];
    }
    for(i=low;i<=high;i++){
        a[i]=b[i];
    }
}

void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(){
    int a[300000],i,j,n,ch;
    float t_taken;
    clock_t start,end;
    
    printf("enter the number of elements: ");
    scanf("%d",&n);
    
    
    while(1){
        printf("enter the choice: \n");
        printf("1. best case\n2. worst case\n3. average case\n4.break\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1: printf("best case: \n");
                    for(i=0;i<n;i++){
                        a[i]=i;
                    }
                    start=clock();
                    mergesort(a,0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the best case time is %f seconds\n",t_taken);
                    break;
                    
            case 2:printf("worst case: \n");
                    for(i=0;i<n;i++){
                        a[i]=n-i;
                    }
                    start=clock();
                    mergesort(a,0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the worst case time is %f seconds \n",t_taken);
                    break;
            
            case 3:printf("average case: \n");
                    for(i=0;i<n;i++){
                        a[i]=rand();
                    }
                    start=clock();
                    mergesort(a,0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the average case time is %f seconds\n",t_taken);
                    break;
                    
            case 4:exit(1);
                    
        }
    }
    return 0;
}    
    
    
