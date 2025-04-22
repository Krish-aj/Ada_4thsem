#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int a[300000];
int partition(int,int);
void quicksort(int low, int high){
    if(low<high){
        int pivot_index=partition(low,high);
        quicksort(low,pivot_index-1);
        quicksort(pivot_index+1,high);
    }
}

int partition(int low,int high){
    int pivot_element=a[low];
    int i=low+1,j=high;
    
    while(i<=j){
        while(i<=high && a[i]<=pivot_element) i++;
        while(j>=low && a[j]>pivot_element) j--;
        
        if(i<j){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[low]=a[j];
    a[j]=pivot_element;
    return j;
}

int main(){
    int i,j,n,ch;
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
                        a[i]=rand();
                    }
                    start=clock();
                    quicksort(0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the best case time is %f seconds\n",t_taken);
                    break;
                    
            case 2:printf("worst case: \n");
                    for(i=0;i<n;i++){
                        a[i]=i;
                    }
                    start=clock();
                    quicksort(0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the worst case time is %f seconds \n",t_taken);
                    break;
            
            case 3:printf("average case: \n");
                    for(i=0;i<n;i++){
                        a[i]=rand();
                    }
                    start=clock();
                    quicksort(0,n-1);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the average case time is %f seconds\n",t_taken);
                    break;
                    
            case 4:exit(1);
                    
        }
    }
    return 0;
}    
    
    
