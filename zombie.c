#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

  int size = 5;
  int status;
  pid_t pid;

  int arr[] = {5 , 4 , 3 , 2 , 1};
  printf("unsorted array: ");
  print_array(arr , size);
  
  pid = fork();
  
  if(pid < 0){
    perror("Fork Failed");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0){
    printf("\n***In The Child Process*** \n Child id: %d Parent Id: %d\n" , getpid() , getppid() );
    printf("Sorting the array in the child\n");
    printf("The sorted Array is: ");
    sort(arr,size);
    print_array(arr,size);
    printf("Child Process finished (Zombie till the parent collects it from the process table)\n");
    exit(EXIT_SUCCESS);
  }
  else{
    printf("\n***In the parent process***\n Parent id: %d Child id: %d\n " , getpid() , pid);
    printf("Sorting the array in the Parent\n");
    printf("The sorted Array is: ");
    sort(arr,size);
    print_array(arr,size);
    sleep(15);
    waitpid(pid , &status , 0);
    exit(0);
  }
  return 0;
}



