#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void print_array(int *arr , int size){
  
  for(int i = 0 ; i < size ; i++){
    printf("%d " , arr[i]);
  }
  printf("\n");
  
}

void sort(int *arr , int size){
  
  for(int i = 0 ; i < size ; i++){
    for(int j = 0; j< size - i - 1 ; j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}

int main(){
  int size;
  printf("enter the size of the array: ");
  scanf("%d" , &size);
  printf("Enter the elements\n");
  int arr[size];
  for(int i = 0 ; i < size ; i++){
    scanf("%d" , &arr[i]);
  }
  
  sort(arr,size);
  
  printf("[Main Program] Sorted array\n");
  print_array(arr,size);
  
  pid_t pid = fork();
  
  if(pid < 0){
    perror("Failed");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0){
    printf("[Child Process] executing the execve method....\n");
    
    char *args[size+2];
    args[0] = "./child";
    for(int i = 1 ; i <= size ; i++){
      char *num = malloc(10);
      sprintf(num , "%d" , arr[i-1]);
      args[i] = num;
    }
    args[size+1]=NULL;
    execve("./child" , args , NULL);
    perror("execve Failed");
    exit(EXIT_FAILURE);
  }
  else{
    printf("Parent process exited.....");
    wait(NULL);
    exit(0);
  }
  return 0;
  
}



