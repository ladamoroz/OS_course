#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int n, m;
    FILE* rf;
    FILE* wf;
    rf = fopen("input.txt", "r");
    wf = fopen("output.txt","w");
    fscanf(rf,"%d",&n); //number of processes
    fscanf(rf,"%d",&m); //type of resources
    int* E = malloc(m*sizeof(int));
    int* A = malloc(m*sizeof(int));
    for (int i = 0; i< m; i++){
        fscanf(rf,"%d", &E[i]);
    }
    for (int i = 0; i < m; i++){
        fscanf(rf, "%d",&A[i]);
    }
    int **R = (int **)malloc(n * sizeof(int *)); //request matrix
    int **C = (int **)malloc(n * sizeof(int *)); //current allocation matrix
    for (int i =0 ; i< n; i++){
        C[i] = (int *)malloc(m * sizeof(int));
        R[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            fscanf(rf, "%d",&C[i][j]);
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            fscanf(rf,"%d",&R[i][j]);
        }
    }
    int* work = malloc(m*sizeof(int));
    bool* finish = malloc(n*sizeof(bool));
    for (int i = 0; i < m; i++){
        work[i] = A[i];
    }
    
    for (int i = 0; i < n;i++){
        int count = 0;
        for (int j = 0; j < m; j++){
            if (C[i][j] == 0){
                count++;
            }
        }
        if (count == m){
            finish[i] = true;
        }
    }
    
    int i = 0;
    bool flag = true;
    while(i<n && flag){
        bool pflag = true;
        for (int j = 0;j<m; j++){
            if (R[i][j] > work[j]){
                pflag = false;
                break;
            }
        }
        if (finish[i] == false && pflag){
            finish[i] = true;
            for (int j = 0 ; j < m; j++){
                work[j] = work[j]+C[i][j];
            }
            i++;
        } else {
            flag = false;
        }
    }
    int count = 0;
    for (int k = 0; k < n; k++){
        if (!finish[k]){
            count++;
        }
    }
    if (count == 0){
        fprintf(wf,"No deadlock");
    } else {
        fprintf(wf,"Number of processes at deadlock: %d", count);
    }
    return 0;
}
