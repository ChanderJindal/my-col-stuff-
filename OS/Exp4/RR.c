#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define at 10
#define bt 50
#define RR 2

//PS

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

void MakeProcess(struct Pro* pal){
pal->P = rand()%N;
for (int i =0;i< pal->P;i++){
    pal->AT[i] = rand()%at;
    pal->BT[i] = rand()%bt;
    pal->NUM[i] = i+1;
    pal->WT[i] = 0;
    pal->TAT[i] = pal->BT[i];
}
return ;
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
}

void Printer(struct Pro pal){
    printf("There are %d Processes.\n\n",pal.P);
    for(int i=0;i<pal.P;i++){
        printf("The Process# %d which arrived at %d with a Bust Time of %d had a waiting time of %d and Turn Around Time of %d.\n",pal.NUM[i],pal.AT[i],pal.BT[i],pal.WT[i],pal.TAT[i]);
    }
    printf("\nThe Average Waiting Time is %f and Average Turn Around Time is %f.\n",pal.AWT,pal.ATAT);
}

void ATSorter(struct Pro *pal){
    for(int i = 0;i< pal->P;i++){
        for(int j=i+1;j<pal->P;j++){
            if(pal->AT[i] > pal->AT[j])
            Swapper(pal,i,j);
        }
    }
}

int TotalTime(struct Pro pal){
    int TimeTaken = 0;
    for(int i =0;i<pal.P;i++)
        TimeTaken += pal.AT[i] + pal.BT[i];
return TimeTaken;
}

void CalcWaiting(struct Pro* pal){
    ATSorter(pal);
    int TimeTaken = TotalTime(*pal);
    //printf("%d\n",TimeTaken);
    for(int i =0;i<TimeTaken;i++){
       // printf("Total Processes = %d\n",pal.P);

        int Priority = 0,idx = -1;

        for(int j=0;j< pal->P ;j++){

            if( pal->AT[j] <= i /*It hass arrived*/ && pal->BT[j] > 0 /*Yet to be complete*/ ){
                int RanFor = (RR > pal->BT[j]) ? pal->BT[j] : RR;
                //time the jth process can run for
                while(RanFor --> 0){
                // to keep record of every sec. for WT mainly
                for(int k =0;k<pal->P;k++){
                    // for all the P Processes 
                    if(pal->AT[k] <= i && pal->BT[k] > 0){
                        // if they have arrived && can be executed
                    pal->WT[k]++;
                    }
                }
                pal->BT[j]--; // jth process is executed for that ith sec
                pal->WT[j]--;
                i++; // ith sec passes
                }

            }
        }
    }
    pal->AWT = 0;
    pal->ATAT = 0;

    for(int i =0;i<pal->P;i++){
        pal->BT[i] = pal->TAT[i];
        pal->TAT[i] += pal->WT[i];
        pal->ATAT += pal->TAT[i];
        pal->AWT += pal->WT[i];
    }
    pal->AWT /= pal->P;
    pal->ATAT /= pal->P;
return;
}

void run(){
struct Pro pal;
MakeProcess(&pal);
CalcWaiting(&pal);
Printer(pal);

}

int main(){
srand(time(0));
run();
return 0;
}
