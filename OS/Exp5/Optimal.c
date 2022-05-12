#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TotalPages 4
#define PageType 10
#define PageNumber 50
#define PrintSize 9

struct Table{
    int Pages;
    int MyPages[TotalPages];
    int AllPages[PageNumber];
    int faults;
};

void Generator(struct Table* MyTable);
void Printer(struct Table MyTable);
void testprinter(struct Table MyTable);
void TotalFaults(struct Table* MyTable);
void Process(struct Table* MyTable);

int main(){
struct Table MyTable;
Generator(&MyTable);
//testprinter(MyTable);
//Printer(MyTable);
//TotalFaults(&MyTable);
Printer(MyTable);
Process(&MyTable);
//Printer(MyTable);
return 0;
}

void Generator(struct Table* MyTable){
    srand(time(0));
    
    MyTable->Pages = rand()%PageNumber;
    for(int i=0;i<MyTable->Pages;i++)
        MyTable->AllPages[i] = rand()%PageType;
    for(int i=0;i<TotalPages;i++)
        MyTable->MyPages[i] = -1;
    MyTable->faults = 0;
/*Pages Have been placed*/

//These are not necessary
/*
    for(int i=0;i< ((MyTable->Pages > TotalPages) ? TotalPages : MyTable->Pages) ;i++)
        MyTable->MyPages[i] = MyTable->AllPages[i];
    
    MyTable->faults = (MyTable->Pages > TotalPages) ? TotalPages : MyTable->Pages;
    */
return ;
}

void testprinter(struct Table MyTable){
    printf("%d\n",MyTable.Pages);
    for(int i=0;i<MyTable.Pages;i++)
    printf("%d " , MyTable.AllPages[i]);

}

void Printer(struct Table MyTable){
    int temp = MyTable.Pages/PrintSize;
    printf("This Set has a total of %d Pages.\n",MyTable.Pages);
    for(int i=0;i<((PrintSize > MyTable.Pages) ? MyTable.Pages : PrintSize);i++){
        for(int j=0;j<=temp;j++){
            int idx = j*PrintSize + i;
            if(idx < MyTable.Pages)
            printf(" %d) -> %d  |",idx+1,MyTable.AllPages[idx]);
        }
        printf("\n");
    }
    printf("\nThe given set has Faults = %d.",MyTable.faults);
    printf("\n----------------------------------------------\n");
}


void TotalFaults(struct Table* MyTable){
    for(int i = 0 ; i < MyTable->Pages ;i++){
        int CurrentIdx = -1;

            for(int j=0;j<TotalPages;j++){
                if(MyTable->AllPages[i] == MyTable->MyPages[j]){
                    CurrentIdx = j;
                    break;
                }
            }
            if(CurrentIdx == -1){
                int MaxDist = 1,idx = 0;
                for(int j=0;j<TotalPages;j++){
                    int CurrDist = MyTable->Pages - i;
                    for(int k = i+1;k<MyTable->Pages;k++){
                        if(MyTable->AllPages[k] == MyTable->MyPages[j]){
                            CurrDist = k-i;
                            break;
                        }
                    }
                    if( CurrDist > MaxDist ){
                        MaxDist = CurrDist;
                        idx = j;
                        }
                }
                MyTable->faults += 1;
                MyTable->MyPages[idx] = MyTable->AllPages[i];
            }
    }
}

void Process(struct Table* MyTable){
    for(int i = 0 ; i < MyTable->Pages ;i++){
        int CurrentIdx = -1;

            for(int j=0;j<TotalPages;j++){
                if(MyTable->AllPages[i] == MyTable->MyPages[j]){
                    CurrentIdx = j;
                    break;
                }
            }
            if(CurrentIdx == -1){
                int MaxDist = 1,idx = 0;
                for(int j=0;j<TotalPages;j++){
                    int CurrDist = MyTable->Pages - i;
                    for(int k = i+1;k<MyTable->Pages;k++){
                        if(MyTable->AllPages[k] == MyTable->MyPages[j]){
                            CurrDist = k-i;
                            break;
                        }
                    }
                    if( CurrDist > MaxDist ){
                        MaxDist = CurrDist;
                        idx = j;
                        }
                }
                MyTable->faults += 1;
                MyTable->MyPages[idx] = MyTable->AllPages[i];
            }
        
        printf("For the #%dth Iteration the Pages are - ",i+1);
        for(int j = 0;j<TotalPages;j++)
            printf("%d ",MyTable->MyPages[j]);
        if(CurrentIdx == -1){
            printf(" <-Fault");
        }
        printf("\n");
    }    
    printf("\nThe Total Faults in this set using Optimal Approach is %d.\n",MyTable->faults);
    printf("__________________________________________________\n");
}