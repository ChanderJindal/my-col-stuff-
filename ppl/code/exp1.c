#include <stdio.h>
#include <string.h>
//#include <conio.h>
int main(){
    printf("Implement all major functions of string.h in single C program using switch case to select specific function from user choice (like strlen, strcat, strcpy, strcmp, strrev)\n-\t\tby Chander Jindal\n\t\t06514802719");
    int ch;
    char s1[50], s2[50], c;
    do
    {
        //clrscr();
        printf("\nProgram to implement major functions of string.h");
        printf("\n1. Strlen\n2. Strcat\n3. Strcpy\n4. Strcmp\n5. Strrev");
        printf("\nEnter your choice:- ");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            printf("Enter a string (max length - 50) : ");
            gets(s1);
            printf("Length of string '%s' is %d", s1, strlen(s1));
            break;
        case 2:
            printf("Enter first string (max length - 50) : ");
            gets(s1);
            printf("Enter second string (max length - 50) : ");
            gets(s2);
            printf("After concatenation, Result = %s", strcat(s1, s2));
            break;
        case 3:
            printf("Enter first string (max length - 50) : ");
            gets(s1);
            printf("Enter second string (max length - 50) : ");
            gets(s2);
            printf("After copying second string into first:-");
            strcpy(s1, s2);
            printf("\nFirst String = %s", s1);
            printf("\nSecond String = %s", s2);
            break;
        case 4:
            printf("Enter first string (max length - 50) : ");
            gets(s1);
            printf("Enter second string (max length - 50) : ");
            gets(s2);
            if (strcmp(s1, s2) == 0)
            {
                printf("\nBoth strings are equal");
            }
            else
            {
                printf("\nBoth strings are not equal");
                break;

            }
        case 5:
            printf("Enter a string (max length - 50) : ");
            gets(s1);
            char s[50];
            strcpy(s, s1);
            printf("Reverse of string '%s' is %s", s, strrev(s1));
            break;
        default:
            printf("\n Wrong choice");
            break;
        }
        printf("\nDo you want to continue ? (y/n) : ");
        scanf("%c", &c);
    } while ((c == 'y') || (c == 'Y'));
    return 0;
}
