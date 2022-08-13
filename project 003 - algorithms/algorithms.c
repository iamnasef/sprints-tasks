#include <stdio.h>
#include <string.h>
// applying binary search
int search(int scope[], int left,int right,int number_to_search_for){
    int length=right+1;
    sort(scope,length);
    //if we didn't reach the end
    if(right>=left){
        int middle = left + (right-left)/2;
        // if we find the element we want
        if(scope[middle]==number_to_search_for)
            return middle;
        // if the element is int the left half
        if(scope[middle]>number_to_search_for)
            return search(scope,left,middle-1,number_to_search_for);
        // if the element is int the right half
        return search(scope,middle+1,right,number_to_search_for);

    }
    
    return -1;
    
}
// swap function for bubble sort
void swap (int* value1, int* value2){
    int tmp = *value1;
    *value1=*value2;
    *value2=tmp;
}
//sorting via bubble sort

void sort(int scope[], int length){
    for(int i=0;i<length-1;i++){
        for(int j=0;j<length-i-1;j++){
            if(scope[j]>scope[j+1]){
                swap(&scope[j],&scope[j+1]);
            }
        }
    }
    
}
int main()
{
    int length, number_to_search_for;
    printf("Please enter the number of elements you want to search:");
    scanf("%d",&length);
    int scope [length];
    for(int i=0;i<length;i++){
        printf("Enter a single number :");
        scanf("%d",&scope[i]);
    }
    
    printf("Please enter the number you want to search for:");
    scanf("%d",&number_to_search_for);
    int index= search(scope,0,length-1,number_to_search_for);
    if(index==-1){
        printf("the element is not found");
    }else{
       printf("the element is found at index %d",index); 
    }
    
}
