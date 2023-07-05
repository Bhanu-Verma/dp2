#include <stdio.h>
#include <stdlib.h>

int main(){
            /*use of malloc*/
    int *ptr=(int*) malloc(sizeof(int));
    scanf("%d",ptr);
    printf("%d",*ptr);
    free(ptr);
            /*use of calloc*/
    int n;
    scanf("%d",&n);
    int *arr=(int*) calloc(10,sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    free(arr);
    return 0;
}