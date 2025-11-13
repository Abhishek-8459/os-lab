#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void print_array(int *arr , int size){
  
  for(int i = size-1 ; i >= 0 ; i--){
    printf("%d " , arr[i]);
  }
  printf("\n");
  
}
int main(int argc , char *argv[]){
  int arr[argc-1];
  
  for(int i = 1 ; i < argc ; i++){
    arr[i-1] = atoi(argv[i]);
  }
  
  printf("Display in reverse order");
  print_array(arr,argc-1);
  return 0;
  
  
}
