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

int main(){
struct Table MyTable;
Generator(&MyTable);
//testprinter(MyTable);
Printer(MyTable);
return 0;
}

void Generator(struct Table* MyTable){
    srand(time(0));
    
    MyTable->Pages = rand()%PageNumber;
    for(int i=0;i<MyTable->Pages;i++)
        MyTable->AllPages[i] = rand()%PageType;
/**/
    for(int i=0;i< ((MyTable->Pages > TotalPages) ? TotalPages : MyTable->Pages) ;i++)
        MyTable->MyPages[i] = MyTable->AllPages[i];
    
    MyTable->faults = (MyTable->Pages > TotalPages) ? TotalPages : MyTable->Pages;
    /**/
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
    for(int i=0;i<PrintSize;i++){
        for(int j=0;j<=temp;j++){
            int idx = j*PrintSize + i;
            if(idx < MyTable.Pages)
            printf(" %d) -> %d  |",idx+1,MyTable.AllPages[idx]);
        }
        printf("\n");
    }
    printf("\nThe given set has Faults = %d.",MyTable.faults);
}

