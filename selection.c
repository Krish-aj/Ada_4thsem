//selection sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ss(int n, int a[]){
    int min,i,j,temp;
    for(i=0; i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
                
            }
            
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main(){
    int a[300000],n,i,j,ch;
    float t_taken;
    clock_t start, end;
    
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
                    ss(n,a);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the best case time is %f seconds",t_taken);
                    break;
                    
            case 2:printf("worst case: \n");
                    for(i=0;i<n;i++){
                        a[i]=n-i;
                    }
                    start=clock();
                    ss(n,a);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the worst case time is %f seconds ",t_taken);
                    break;
            
            case 3:printf("average case: \n");
                    for(i=0;i<n;i++){
                        a[i]=rand();
                    }
                    start=clock();
                    ss(n,a);
                    end=clock();
                    t_taken=(float)(end-start)/CLOCKS_PER_SEC;
                    printf("the average case time is %f seconds",t_taken);
                    break;
                    
            case 4:exit(1);
                    
        }
    }
    return 0;
}
