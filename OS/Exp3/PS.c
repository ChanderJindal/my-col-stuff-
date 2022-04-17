#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define at 10
#define bt 50
#define p 10
//PS

struct Pro
{
    int BT[N];
    int AT[N];
    int WT[N];
    int NUM[N];
    int TAT[N];
    int Pri[N];
    int P;
    float AWT;
    float ATAT;
};

struct Pro MakeProcess(struct Pro pal){
pal.P = rand()%N;
for (int i =0;i< pal.P;i++){
    pal.AT[i] = rand()%at;
    pal.BT[i] = rand()%bt;
    pal.Pri[i] = rand()%p;
    pal.NUM[i] = i+1;
    pal.WT[i] = 0;
    pal.TAT[i] = pal.BT[i];
}
return pal;
}

void Printer(struct Pro pal){
    printf("There are %d Processes.\n\n",pal.P);
    for(int i=0;i<pal.P;i++){
        printf("The Process# %d with Priority %d which arrived at %d with a Bust Time of %d had a waiting time of %d and Turn Around Time of %d.\n",pal.NUM[i],pal.Pri[i],pal.AT[i],pal.BT[i],pal.WT[i],pal.TAT[i]);
    }
    printf("\nThe Average Waiting Time is %f and Average Turn Around Time is %f.\n",pal.AWT,pal.ATAT);
}

int TotalTime(struct Pro pal){
    int TimeTaken = 0;
    for(int i =0;i<pal.P;i++)
        TimeTaken += pal.AT[i] + pal.BT[i];
return TimeTaken;
}

struct Pro CalcWaiting(struct Pro pal){

    int TimeTaken = TotalTime(pal);
    printf("%d\n",TimeTaken);
    for(int i =0;i<TimeTaken;i++){
       // printf("Total Processes = %d\n",pal.P);

        int Priority = 0,idx = -1;

        for(int j=0;j< pal.P ;j++){

            if(pal.AT[j] <= i && pal.BT[j] != 0){
                //It has arrived, it's yet to be complete
                if(pal.Pri[j] > Priority){
                    // if higher priority
                    Priority = pal.Pri[j], idx = j;
                }else if(pal.Pri[j] == Priority){
                    //if same check based on AT
                    if (idx == -1 || pal.AT[j] < pal.AT[idx]){
                        // 1st one OR Arrived earlier
                        idx = j;
                    }
                }
            }

        }

        for(int j =0;j<pal.P;j++){
            if(pal.BT[j] > 0 && pal.AT[j] <= i){
            //it is to be processed, it has arrived
                pal.WT[j]++;
            }
        }
        //smallest one
        if(idx != -1 && pal.BT[idx] > 0){
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

void run(){
struct Pro pal;
pal = MakeProcess(pal);
Printer(pal);
pal = CalcWaiting(pal);
Printer(pal);

}

int main(){
srand(time(0));
run();
return 0;
}

void Swapper(struct Pro *pal, int i , int  j){
    int temp;
    temp = pal->BT[i];
    pal->BT[i] = pal->BT[j];
    pal->BT[j] = temp;

    temp = pal->AT[i];
    pal->AT[i] = pal->AT[j];
    pal->AT[j] = temp;   

    temp = pal->WT[i];
    pal->WT[i] = pal->WT[j];
    pal->WT[j] = temp; 
    
    temp = pal->NUM[i];
    pal->NUM[i] = pal->NUM[j];
    pal->NUM[j] = temp;

    temp = pal->TAT[i];
    pal->TAT[i] = pal->TAT[j];
    pal->TAT[j] = temp;
    
    temp = pal->Pri[i];
    pal->Pri[i] = pal->Pri[j];
    pal->Pri[j] = temp;

}