#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int i;
struct node *next; } node1;

void reverselinkedlist(node1 *head){
if(head->next==NULL)
printf("%d->",head->i);
else{
reverselinkedlist(head->next);
printf("%d->",head->i);
}}

int main(){
char hh;
do{
char ch;
node1 *head=NULL,*tail=NULL;
do{
printf("Program to reverse a linked list (Iterative and Recursive)\n\t\tby Chander Jindal\n\t\t06514802719");
printf("\nCreating linked list...");
printf("\nEnter an integer:- ");
if(head==NULL){
head = malloc(sizeof(node1));
scanf("%d",&head->i);
head->next=NULL;
tail = head; }
else{
node1 *n1 = malloc(sizeof(node1));
scanf("%d",&n1->i);
n1->next=NULL;
tail->next=n1;
tail=n1; }
printf("Linked list is:- ");
node1 *n2=head;
printf(" ");
while(n2!=NULL){
printf("%d->",n2->i);
n2 = n2->next; }
printf("NULL");
printf("\nDo you want to enter more elements in the list (y/n) ? ");
fflush(stdin);
scanf("%c",&ch);
} while(ch=='y'||ch=='Y');
char ch1;
do{
int choice;
system("cls");
printf("Entered Linked List is:- ");
node1 *n2=head;
printf(" ");
while(n2!=NULL){
printf("%d->",n2->i);
n2 = n2->next; }
printf("NULL");
printf("\n1. Reverse a linked list iteratively");
printf("\n2. Reverse a linked list recursively");
printf("\nEnter your choice - ");
scanf("%d",&choice);
switch(choice){
case 1: printf(" ");
node1 *n2 = head;
node1 *c,*chead=NULL;
while(n2!=NULL){
c = malloc(sizeof(node1));
c->i = n2->i;
if(chead==NULL){
c->next = NULL;
chead = c; }
else{
c->next = chead;
chead = c;}
n2 = n2->next; }
node1 *x = chead;
printf("\nReversed linked list is : ");
while(x!=NULL){
printf("%d->",x->i);
x=x->next; }
printf("NULL"); break;
case 2:printf("\nReversed linked list is : ");
reverselinkedlist(head);
printf("NULL"); break;
default:printf("\nWrong choice"); break; }
printf("\nDo you want to reverse linked list again using a different choice (y/n)? ");
fflush(stdin);
scanf("%c",&ch1);
} while((ch1=='Y')||(ch1=='y'));
printf("\nDo you want to run program again (y/n)? ");
fflush(stdin);
scanf("%c",&hh);
} while((hh=='y')||(hh=='Y'));
return 0;
}
