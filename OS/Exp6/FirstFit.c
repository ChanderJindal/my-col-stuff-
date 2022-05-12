#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Slots 50
#define UpperMemoryLimit 200
#define LowerMemoryLimit 50
#define PrintSize 9

struct Stack{
    int TotalMemorySlots;
    int MemorySlots[Slots];
    int TotalProcesses;
    int ProcessMemory[Slots];
    int ResultCode;

};

void Generator(struct Stack* MyStack);
void Printer(struct Stack MyStack);
void MemoryAllocation(struct Stack* MyStack);

int main(){
struct Stack MyStack;
Generator(&MyStack);
Printer(MyStack);
MemoryAllocation(&MyStack);
Printer(MyStack);
return 0;
}

void Generator(struct Stack* MyStack){
    srand(time(0));

    MyStack->TotalMemorySlots = rand()%Slots;
    for(int i=0;i<MyStack->TotalMemorySlots;i++)
        MyStack->MemorySlots[i] = rand()%UpperMemoryLimit + LowerMemoryLimit;

    MyStack->TotalProcesses = rand()%MyStack->TotalMemorySlots;
    for(int i =0;i<MyStack->TotalProcesses;i++)
        MyStack->ProcessMemory[i] = rand()%LowerMemoryLimit;
    
    MyStack->ResultCode = 0;

return ;
}

void Printer(struct Stack MyStack){

    switch (MyStack.ResultCode){
    case 0: printf("Newly initialized.\n");
        break;
    case -1: printf("Memory allotment is sucessfull!\n"); 
    break;
    default:
    printf("Error at Process #%d.\n",MyStack.ResultCode);
        break;
    }

    int temp = MyStack.TotalMemorySlots/PrintSize;
    printf("The Set contains %d Memory Slots with following Capacity.\n",MyStack.TotalMemorySlots);
        for(int i=0;i<((PrintSize > MyStack.TotalMemorySlots) ? MyStack.TotalMemorySlots : PrintSize);i++){
        for(int j=0;j<=temp;j++){
            int idx = j*PrintSize + i;
            if(idx < MyStack.TotalMemorySlots)
            printf(" %*d) -> %d Unit(s)",5,idx+1,MyStack.MemorySlots[idx]);
        }
        printf("\n");
    }

    printf("_________________________________________________\n");

    temp = MyStack.TotalProcesses/PrintSize;
    printf("The Set contains %d Processes with the following Memory requirements.\n",MyStack.TotalProcesses);

    for(int i=0;i<((PrintSize > MyStack.TotalProcesses) ? MyStack.TotalProcesses : PrintSize);i++){
        for(int j=0;j<=temp;j++){
            int idx = j*PrintSize + i;
            if(idx < MyStack.TotalProcesses)
            printf(" %*d) -> %d Unit(s)",5,idx+1,MyStack.ProcessMemory[idx]);
        }
        printf("\n");
    }

    printf("\n----------------------------------------------\n");
}

void MemoryAllocation(struct Stack* MyStack){
for(int i=0;i<MyStack->TotalProcesses;i++){
    int CurrentRequirement = MyStack->ProcessMemory[i];

        for(int j =0;j<MyStack->TotalMemorySlots;j++){
            if(MyStack->MemorySlots[j] >= CurrentRequirement){
                MyStack->MemorySlots[j] = -1;
                MyStack->ProcessMemory[i] = 0;
                CurrentRequirement = -1;
                break;
            }
        }
    if(CurrentRequirement != -1){
        MyStack->ResultCode = 1+i;
        return;
    }
}
MyStack->ResultCode = -1;
return;
}