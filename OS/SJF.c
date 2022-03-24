#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define at 10
#define bt 50
//SJF

struct Pro
{
    int BT[N];
    int AT[N];
    int WT[N];
    int NUM[N];
    int P;
    float AW;
};

struct Pro MakeProcess(struct Pro pal,int flag){
pal.P = rand()%N;
for (int i =0;i< pal.P;i++){
    if(flag != 0){
    pal.AT[i] = rand()%at;
    }else{
    pal.AT[i] = 0;
    }
    pal.BT[i] = rand()%bt;
    pal.NUM[i] = i+1;
}
return pal;
}

struct Pro Sorter(struct Pro pal){
    for(int i = 0 ; i< pal.P;i++){
        for(int j=i+1;j<pal.P;j++){
            if(pal.BT[i] > pal.BT[j]){
                int temp = pal.BT[j];
                pal.BT[j] = pal.BT[i];
                pal.BT[i] = temp;
            }
        }
    }
return pal;
};


struct Pro CalcWaiting(struct Pro pal){
    pal.WT[0] = 0;
    pal.AW = pal.AT[0];
    for(int i = 1 ;i < pal.P;i++){
        pal.WT[i] = pal.WT[i-1] + pal.BT[i-1] - pal.AT[i];
        pal.AW += pal.WT[i];
    }
    pal.AW = (pal.AW -  pal.WT[pal.P-1])/pal.P;
return pal;
};

void print(struct Pro pal){
    printf("\nHello! I am Chander Jindal.\n\n\n");
    printf("Total number of processes made are %d.\n\n",pal.P);
    for(int i =0;i<pal.P;i++)
        printf("The Process#%d which Arived at %d had a Waiting Time of %d and Bust Time of %d.\n",i+1,pal.AT[i],pal.WT[i],pal.BT[i]);
    printf("\n##########################################\n");
    printf("The Average Waiting Time is %f.\n",pal.AW);
}

void run(){
    struct Pro pal;// = (struct Pro*) malloc(sizeof(struct  Pro));
    pal = MakeProcess(pal,0);
    pal = CalcWaiting(pal);
    pal = Sorter(pal);
    print(pal);
}

int main(){
    srand(time(0));
    run();
return 0;
}