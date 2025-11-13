#include <stdio.h>

struct process {
  int pid;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  int rem_bt;
  
};

int main(){
  int n;
  int tq;
  
  printf("Enter the number of processes\n");
  scanf("%d" , &n);
  
  struct process p[n];
  for(int i = 0 ; i < n ; i++){
    p[i].pid = i+1;
    printf("enter the arrival time: ");
    scanf( "%d" , &p[i].at);
    printf("enter the burst time: ");
    scanf( "%d" , &p[i].bt);
    p[i].rem_bt = p[i].bt;
  }
  
  printf("Enter the Time quant");
  scanf("%d" , &tq);
  
  int time=0 ;
  int completed=0;
  int isCompleted[n];
  int visited[n];
  int queue[1000];
  int front = 0;
  int rear = 0;
  
  for(int i = 0 ; i < n ; i++){
    isCompleted[i]=0;
    visited[i]=0;
  }
  int first = 0;
  for(int i = 1 ; i < n ; i++){
    if(p[i].at < p[first].at){
      first = i;
    }
  }
  
  queue[rear++]=first;
  visited[first]=1;
  time = p[first].at;
  
  while(completed < n){
    
    if(front == rear){
      int mini = 99999;
      int ind = -1;
      
      for(int i = 0 ; i < n ; i++){
        if(p[i].at <= time && isCompleted[i]==0 && visited[i]==0 ) {

            ind = i;
        }
      }
      
      if(ind != -1){
        queue[rear++]=ind;
        time = p[ind].at;
        visited[ind]=1;
      }
      else{
        time++;
      }
      continue;
    }
    
    int ind = queue[front++];
    if(p[ind].rem_bt > tq){
      time += tq;
      p[ind].rem_bt -= tq;
    }
    else{
      time += p[ind].rem_bt;
      p[ind].rem_bt = 0;
      
      p[ind].ct = time;
      p[ind].tat = time - p[ind].at;
      p[ind].wt = p[ind].tat-p[ind].bt;
      
      isCompleted[ind] = 1;
      completed++;
    }
    
    for(int i = 0 ; i < n ; i++){
      if(p[i].at <= time && visited[i] == 0 && isCompleted[i]==0){
        queue[rear++]=i;
        visited[i]=1;
      }
      
    }
    
    if(p[ind].rem_bt > 0){
      queue[rear++]=ind;
    }
  }
  
  printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
  for(int i = 0 ; i < n ; i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n" , p[i].pid , p[i].at, p[i].bt , p[i].ct , p[i].tat , p[i].wt);
    
  }
  return 0;
}
