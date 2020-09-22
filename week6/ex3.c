#include <stdio.h>
int main(){
    int p[10],at[10],bt[10],temp[10];
    int n,quantum,count = 0;
    printf("Number of processes: ");
    scanf("%d",&n);
    for (int i =0;i<n;i++){
        p[i]=i+1;
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        temp[i] = bt[i];
    }
    int tat[n], wt[n],ct[n];
    printf("Time quantum: ");
    scanf("%d",&quantum);
    int x = n;
    double allWT = 0, allTAT = 0;
    for (int t = 0, i = 0;x!=0;){
        if (temp[i]<=quantum && temp[i]>0){
            t = t+temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0){
            temp[i] = temp[i] - quantum;
            t = t + quantum;
        }
        if (temp[i] == 0 && count == 1){
            x--;
            wt[i] = t - at[i] - bt[i];
            tat[i] = t - at[i];
            ct[i] = t;
            allWT = allWT + wt[i];
            allTAT = allTAT + tat[i];
            count = 0;
        }
        if (i == n-1){
            i = 0;
        } else if (at[i+1] <=t){
            i++;
        } else {
            i = 0;
        }
    }
    double avgWT = allWT / n;
    double avgTAT = allTAT / n;
    printf("Process     BT      AT      WT      TAT      CT\n");
    for (int i = 0; i < n; i++){
        printf("%d",p[i]);
        printf("           %d",bt[i]);
        printf("       %d",at[i]);
        printf("       %d",wt[i]);
        printf("       %d",tat[i]);
        printf("        %d\n",ct[i]);
    }
    printf("Average WT: %lf\n", avgWT);
    printf("Average TAT: %lf", avgTAT);
    
    return 0;
}
/*
INPUT
Number of processes: 3
p1: at = 0 bt = 5
p2: at = 3 bt = 9
p3: at = 6 bt = 6
quantum = 1
OUTPUT
Process     BT      AT      WT      TAT      CT
1           5       0       3       8        8
2           9       3       8       17        20
3           6       6       6       12        18
Average WT: 5.666667
Average TAT: 12.333333
*/
