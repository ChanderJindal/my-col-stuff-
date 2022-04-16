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
    int TAT[N];
    int P;
    float AWT;
    float ATAT;
};

struct Pro MakeProcess(struct Pro pal,int flag){
pal.P =rand()%N;
for (int i =0;i< pal.P;i++){
    if(flag != 0){
    pal.AT[i] = rand()%at;
    }else{
    pal.AT[i] = 0;
    }
    pal.BT[i] = rand()%bt;
    pal.NUM[i] = i+1;
    pal.WT[i] = 0;
    pal.TAT[i] = pal.BT[i];
}
return pal;
}

int TotalTime(struct Pro pal){
int TotalBT = 0;
for(int i =0;i<pal.P;i++)
    TotalBT += pal.BT[i] + pal.AT[i];

return TotalBT;
}


struct Pro CalcWaiting(struct Pro pal){
    int TimeTaken = TotalTime(pal);
   // printf("%d\n",TimeTaken);
    for(int i = 0;i< TimeTaken;i++){
        int idx = -1, val = bt;
        for(int j = 0 ; j < pal.P;j++){
            if( pal.AT[j] <= i && pal.BT[j] > 0 && pal.BT[j] <= val){
            //It has arrived, it is to be processed, it is smallest one
                val = pal.BT[j] , idx = j;
            }
        }
        for(int j =0;j<pal.P;j++){
            if(pal.BT[j] > 0 && pal.AT[j] <= i){
            //it is to be processed, it has arrived
                pal.WT[j]++;
            }
        }
        //smallest one
        if(idx != -1){
            pal.BT[idx]--;
            pal.WT[idx]--;
        }
    }
    pal.AWT = 0;
    pal.ATAT = 0;
    for(int i =0;i<pal.P;i++){
        pal.BT[i] = pal.TAT[i];
        pal.TAT[i] += pal.WT[i];
        pal.ATAT += pal.TAT[i];
        pal.AWT += pal.WT[i];
    }
    pal.AWT /= pal.P;
    pal.ATAT /= pal.P;


return pal;
}

void print(struct Pro pal){
    printf("\nHello! I am Chander Jindal.\n\n\n");
    printf("Total number of processes made are %d.\n\n",pal.P);
    for(int i =0;i<pal.P;i++)
        printf("The Process# %d which Arived at %d with a Bust Time of %d.\nIt had a Waiting Time of %d and a Turn Around Time of %d.\n\n",pal.NUM[i],pal.AT[i],pal.BT[i],pal.WT[i],pal.TAT[i]);
    printf("\n##########################################\n");
    printf("The Average Waiting Time is %f and Average Turn Around Time is %f.\n",pal.AWT,pal.ATAT);
}

void run(){
    struct Pro pal;// = (struct Pro*) malloc(sizeof(struct  Pro));
    pal = MakeProcess(pal,1);
    pal = CalcWaiting(pal);
    //pal = Sorter(pal);
    print(pal);
}

int main(){
    srand(time(0));
    run();
return 0;
}