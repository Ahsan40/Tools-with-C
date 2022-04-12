#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int len;
    char string[100];
    gets(string);
    len = strlen(string);

    char last_express;
    double last_num;
    int last_flag = 0;

    int i = 0;
    while (string[i] != '\0')
    {
        if (isdigit(string[i]))
        {
            if (last_flag == 1)
            {
                last_num = calculate(last_num, strtod(string[i]), last_express);
            }
        }
    }

    return 0;
}

double calculate(double a, double b, char expression)
{
    double result;
    switch (expression)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '/':
        result = a / b;
        break;
    case '*':
        result = a * b;
        break;
    case '^':
        result = pow(a, b);
        break;
    }
    return result;
}

void right_shift(char str[], char a, char b, char expression)
{
    
}