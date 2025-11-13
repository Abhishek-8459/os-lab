#include <stdio.h>

int main() {
  int n ;
  int m ;
  
  printf("Enter the no. of process: ");
  scanf("%d" , &n);
  printf("Enter the no. of resources: ");
  scanf("%d" , &m);
  
  int allocation[n][m];
  int max[n][m];
  int need[n][m];
  int avaiable[m];
  
  int finished[n]; // 1 if finished else 0
  
  for(int i = 0 ; i < n ; i++){
    finished[i]=0;
  }
  
  printf("Enter the allocation matrix\n");
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%d" , &allocation[i][j]);
    }
  }
  
  printf("Enter the max matrix\n");
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      scanf("%d" , &max[i][j]);
    }
  }
  
  printf("Enter the available resources");
 for(int i = 0 ; i < m ; i++){
  scanf("%d" , &avaiable[i]);
 }
 
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < m ; j++){
      need[i][j]=max[i][j]-allocation[i][j];
    }
  }
  
  int sequence[n];
  int count = 0;
  
  while(count<n){
  
    int found = 0;
    
    for(int i = 0 ; i < n ; i++){
    
      int canAllocate = 1;
      
      if(finished[i] == 0){
        
        for(int j = 0 ; j < m ; j++){
          if(need[i][j] > avaiable[j]){
            canAllocate = 0;
            break;
          }
        }
         
        if(canAllocate == 1){
          for(int j = 0 ; j < m ; j++){
            avaiable[j] += allocation[i][j];
            
          }
          sequence[count]=i;
          count++;
          finished[i] =1;
          found = 1;
        }
        
      }
    }
    
    if(found == 0){
      printf("*** Unsafe Sequence ***");
      return 0;
    }
    
  }
  
  printf("The Safe Sequence is: ");
  for(int i = 0 ; i < n ; i++){
    printf("P%d" , sequence[i]);
    if(i != n-1) printf(" --> ");
  }
  return 0;
}
