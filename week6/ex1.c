#include <stdio.h>
#define SIZE 10

void FCFS(int p[], int n, int bt[], int at[]){
  int wt[n], tat[n];
  int st[n];
  st[0] = 0;
  wt[0] = 0;
  for (int i = 1; i < n ; i++) {
    st[i] = st[i-1] + bt[i-1];
    wt[i] = st[i] - at[i];
    if (wt[i] < 0) {wt[i] = 0;}
  }
  for (int i = 0; i < n ; i++){
    tat[i] = bt[i] + wt[i];
  }
  printf("Process     BT      AT      WT      TAT      CT\n");
  int allWT = 0, allTAT = 0;
  for (int i = 0 ; i < n ; i++){
    allWT = allWT + wt[i];
    allTAT = allTAT + tat[i];
    int ct = tat[i] + at[i];
    printf("%d",p[i]);
    printf("           %d",bt[i]);
    printf("       %d",at[i]);
    printf("       %d",wt[i]);
    printf("       %d",tat[i]);
    printf("        %d\n",ct);
  }
  double avgWT = (double)allWT/(double)n;
  double avgTAT =(double)allTAT/(double)n;
  printf("Average WT: %lf\n",avgWT);
  printf("Average TAT: %lf",avgTAT);
}

int main(void) {
  printf("Number of processors:");
  int n;
  scanf("%d",&n);
  int p[SIZE];
  int at[SIZE];
  int bt[SIZE];
  for (int i = 0; i < n; i++){
    p[i] = i+1;
    scanf("%d",&at[i]);
    scanf("%d",&bt[i]);
  }
  FCFS(p,n,bt,at);
  return 0;
}
/*
 INPUT
 Number of processes: 3
 p1: at = 0 bt = 5
 p2: at = 3 bt = 9
 p3: at = 6 bt = 6
 
 OUTPUT
 Process     BT      AT      WT      TAT      CT
 1           5       0       0       5        5
 2           9       3       2       11        14
 3           6       6       8       14        20
 Average WT: 3.333333
 Average TAT: 10.000000
 */
