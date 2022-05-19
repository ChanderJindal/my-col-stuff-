#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 5
#define AL 10;
#define MN 20;
//Banker

struct ProcessDetails{
int n,m;
int Allocated[N][M];
int MaxNeed[N][M];
int CurrNeed[N][M];
int CurrAvailable[M];
int isDone[N];
int Sequence[N];
int TotalDone;
};

void Generator(struct ProcessDetails* MySet){
    srand(time(0));
    int temp = rand()%N;
    MySet->n = 10;//(temp > 0) ? temp : 1 ;
    temp = rand()%M;
    MySet->m = 4;//(temp > 0) ? temp : 1 ;
    MySet->TotalDone = 0;
    for(int i =0;i<MySet->n;i++){
        MySet->isDone[i] = 0;
        for(int j =0;j<MySet->m;j++){
            MySet->Allocated[i][j] = rand()%AL;
            int temp = rand()%MN;
            MySet->MaxNeed[i][j] = (temp > MySet->Allocated[i][j]) ? temp : MySet->Allocated[i][j];
        }
    }
    for(int i=0;i<MySet->m;i++)
    MySet->CurrAvailable[i] = rand()%MN;
return;
}

void CalculateSequence(struct ProcessDetails* MySet){
    for(int i =0;i<MySet->n;i++)
        for(int j =0;j<MySet->m;j++)
            MySet->CurrNeed[i][j] = MySet->MaxNeed[i][j] - MySet->Allocated[i][j];
        
    int processes_done = 1;
    while (processes_done != 0){
        processes_done = 0;
        for(int i =0;i<MySet->n;i++){
            if(MySet->isDone[i] == 1)
            continue;
            int flag = 0;
            for(int j =0;j<MySet->m;j++){
               if(MySet->CurrNeed[i][j] > MySet->CurrAvailable[j]){
                   flag = 1;
                   break;
               }
            }
            if(flag == 0){
                MySet->isDone[i] = 1;
                MySet->Sequence[MySet->TotalDone] = i+1;
                MySet->TotalDone += 1;
                processes_done += 1;
                for(int j =0;j<MySet->m;j++){
                    MySet->CurrAvailable[j] += MySet->CurrNeed[i][j];
                    MySet->CurrNeed[i][j] = 0;
                }
            }
        }    
    }
return; 
}
void PrinterInitial(struct ProcessDetails MySet ){
    printf("For Banker's Algorithm\n");

    printf("Total number of processes = %d\nTotal types of resources = %d\n",MySet.n,MySet.m);
    printf("The initial ammount of resources are :- \nS.No.\t");

    for(int i=0;i<MySet.m;i++)
    printf("%d\t",i+1);

    printf("\nRes.\t");

    for(int i=0;i<MySet.m;i++)
        printf("%d\t",MySet.CurrAvailable[i]);

    printf("\n");


    printf("\nCurrently allocated resources are as follows:-\nS.No.    ");
    for(int i=0;i<MySet.m;i++)
        printf("#%d\t",i+1);
    for(int i=0;i<MySet.n;i++){
        printf("\n%d\t",i+1);
        for(int j=0;j<MySet.m;j++)
            printf("%d\t",MySet.Allocated[i][j]);
    }


    printf("\nMax needed resources are as follows:-\nS.No.    ");

    for(int i=0;i<MySet.m;i++)
        printf("#%d\t",i+1);

    for(int i=0;i<MySet.n;i++){
        printf("\n%d\t",i+1);
        for(int j=0;j<MySet.m;j++)
            printf("%d\t",MySet.MaxNeed[i][j]);
    }
    /*
int n,m;
int Allocated[N][M];
int MaxNeed[N][M];
int CurrNeed[N][M];
int CurrAvailable[M];
int Sequence[N];
int TotalDone;
    */
}

void PrinterFinal(struct ProcessDetails MySet){
    printf("\n\nAfter Calculating\nTotal processes completed = %d.\nThey are as follows\n",MySet.TotalDone);
    for(int i=0;i<MySet.TotalDone-1;i++){
        printf("%d -> ",MySet.Sequence[i]);
    }
    if(MySet.TotalDone>0){
    printf("%d\n",MySet.Sequence[MySet.TotalDone-1]);
    }else{
        printf("Sorry None could be performed.");
    }
}
int main(){
    struct ProcessDetails MySet;
    Generator(&MySet);
    PrinterInitial(MySet);
    CalculateSequence(&MySet);
    PrinterFinal(MySet);

return 0;
}