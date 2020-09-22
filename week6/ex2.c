#include <stdio.h>

int main(){
    int p[10],at[10], bt[10], temp[10];
    int smallest, count = 0;
    double allTAT, allWT, end;
    printf("Number of Processes: ");
    int n;
    scanf("%d", &n);
    int tat[n], wt[n],ct[n],rt[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        p[i] = i+1;
        temp[i] = bt[i];
        rt[i] = bt[i];
    }
    rt[9] = 9999;
    for(int time = 0; count != n; time++){
        smallest = 9;
        for(int i = 0; i < n; i++){
            if(at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0){
                smallest = i;
            }
        }
        rt[smallest]--;
        if(rt[smallest] == 0){
            count++;
            end = time + 1;
            wt[smallest] = end-at[smallest]-temp[smallest];
            tat[smallest] = end - at[smallest];
            ct[smallest] = end;
            allWT = allWT + end - at[smallest] - temp[smallest];
            allTAT = allTAT + end - at[smallest];
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

OUTPUT
Process     BT      AT      WT      TAT      CT
1           5       0       0       5        5
2           9       3       8       17        20
3           6       6       0       6        12
Average WT: 2.666667
Average TAT: 9.333333
*/
