#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    double result;
    double credit;
} CGPA;

void mainOpt(CGPA *, char[], char[], char[], char[]);
void invalidInput();
void mainMenu();
void Input(char[], char[], CGPA *, int);
int inputValidation(char[]);
void removeSpaces(char[]);
double calculateGPA(CGPA *);

void main()
{
    CGPA gpa[20] = {0};
    char inpMsg1[15] = "";
    char inpMsg2[15] = "";
    char inpMsg3[25] = "";
    char opt[5] = "";
    char ch;
MAINMENU:
    system("cls");
    mainMenu();
INPUT:
    ch = getch();
    tolower(ch);
    if (ch == '1')
    {
        // For GPA Calculator
        strcpy(inpMsg1, "Result (SUB");
        strcpy(inpMsg2, "Credit (SUB");
        strcpy(inpMsg3, "Add More Subject? (Y/N)");
        strcpy(opt, "GPA");
        mainOpt(gpa, inpMsg1, inpMsg2, inpMsg3, opt);
        goto MAINMENU;
    }
    else if (ch == '2')
    {
        // For CGPA Calculator
        strcpy(inpMsg1, "Result (SEM");
        strcpy(inpMsg2, "Credit (SEM");
        strcpy(inpMsg3, "Add More Semester? (Y/N)");
        strcpy(opt, "CGPA");
        mainOpt(gpa, inpMsg1, inpMsg2, inpMsg3, opt);
        goto MAINMENU;
    }
    else if (ch == 'x')
    {
        exit(0);
    }
    else
    {
        invalidInput();
        goto INPUT;
    }
}

void mainOpt(CGPA *gpa, char inpMsg1[], char inpMsg2[], char inpMsg3[], char opt[])
{
    CGPA empty[20] = {0};
    double totalGPA = 0;
    char ch, c;
START:
    memcpy(gpa, empty, sizeof(gpa)); // Clearing Data inside gpa
    for (int i = 0; i < 20; i++)
    {
    INPUT:
        // Taking input using custom function
        Input(inpMsg1, inpMsg2, &gpa[i], i + 1);
        if (gpa[i].credit <= 0 || gpa[i].result <= 0)
        {
            invalidInput();
            goto INPUT;
        }
    ANSWER:
        if (i != 0)
        {
            printf("\n %s", inpMsg3);
            ch = getch();
            tolower(ch);
            if (ch == 'y')
                i = i;
            else if (ch == 'n')
                break;
            else
            {
                invalidInput();
                goto ANSWER;
            }
        }
    }
    totalGPA = calculateGPA(gpa);
    printf("\n\n Your %s is %.2lf\n", opt, totalGPA);
LastOPT:
    printf("\n\n [C] Continue   [M] Main Menu   [X] Exit\n\n");
    ch = getch();
    tolower(ch);
    if (ch == 'm')
    {
        /* nothing */
    }
    else if (ch == 'c')
    {
        goto START;
    }
    else if (ch == 'x')
    {
        exit(0);
    }
    else
    {
        invalidInput();
        goto LastOPT;
    }
}

//
// Functional Functions
//

// Taking Input using pointer
void Input(char x[], char y[], CGPA *Input, int i)
{
    CGPA res;
    double p1, p2;
    char c;
INPUT:
    printf("\n %s-%d): ", x, i);
    scanf("%lf", &p1);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf(" %s-%d): ", y, i);
    scanf("%lf", &p2);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    res.result = p1;
    res.credit = p2;
    *Input = res;
}

double calculateGPA(CGPA *x)
{
    int i = 0;
    double credit = 0, gpa = 0;
    while (x[i].credit != 0)
    {
        credit += x[i].credit;
        gpa += (x[i].credit * x[i].result);
        i++;
    }
    gpa = gpa / credit;
    return gpa;
}

//
// Decorational Functions
//

// Min Menu
void mainMenu()
{
    printf("\n1. GPA Calculator\n");
    printf("2. CGPA Calculator\n");
    printf("X. Exit\n");
}

// Wrong Input Message
void invalidInput()
{
    printf("\n\n INVALID INPUT!\n\n");
}