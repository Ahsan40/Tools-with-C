#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char bin[5];
} binary;

typedef struct
{
    char bin[6];
} final_result;

binary bcd_coding(int, int[]);
final_result binary_addition(char[], char[]);
final_result binary_addition_addSix(char[], char[], int *);

int main()
{
    int coding[4] = {8, 4, 2, 1};
    char addent[10] = "";
    char augent[10] = "";
    int input1[10];
    int input2[10];
    int carry = 0;
    int counter;
    char string_input[11] = "";
    // Initializing with 0000 to avoid potential wrong ouput
    binary result1[10] = {"0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000"};
    binary result2[10] = {"0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000"};
    // final_result null =  {"00000"};
    final_result result[6] = {"00000"};
    char addSix[6] = {"00110"};
    printf(" Addent: ");
    scanf("%s", &addent);
    printf(" Augent: ");
    scanf("%s", &augent);
    counter = strlen(addent);
    // Converting String into int
    for (int i = 0; i < counter; i++)
    {
        input1[i] = addent[i] - '0';
        input2[i] = augent[i] - '0';
    }
    // Converting BCD
    for (int i = 0; i < counter; i++)
    {
        result1[i] = bcd_coding(input1[i], coding);
        result2[i] = bcd_coding(input2[i], coding);
    }
    // Printing Output
    printf(" Converted: \n\n");
    for (int i = counter - 1; i >= 0; i--)
    {
        printf("# %d + %d\n", input1[i], input2[i]);
        printf("  Carry: %d\n", carry);
        result1[i] = bcd_coding(input1[i], coding);
        printf("  %s\n", result1[i].bin);
        result2[i] = bcd_coding(input2[i], coding);
        printf("  %s\n", result2[i].bin);
        printf("--------\n");
        // performing binary addition
        result[i] = binary_addition(result1[i].bin, result2[i].bin);
        if (input1[i] + input2[i] > 9)
        {
            printf(" %s\n", result[i].bin);
            printf("  0110\n");
            printf("--------\n");
            result[i] = binary_addition_addSix(result[i].bin, addSix, &carry);
        }
        printf(" %s\n", result[i].bin);
        printf("\n\n");
    }

    return 0;
}

binary bcd_coding(int number, int coding[])
{
    int flag = 0;
    char result[5] = "0000";
    binary storage;
    // a b c d
    for (int i = 0; i < 4; i++)
    {
        if (coding[i] == number)
        {
            result[i] = '1';
            flag = 1;
            break;
        }
    }
    // ab ac ad bc bd cd
    for (int i = 0; i < 4; i++)
    {
        if (flag == 1)
            break;
        for (int j = 0; j < 4; j++)
        {
            if (coding[i] + coding[j] == number)
            {
                result[i] = '1';
                result[j] = '1';
                flag = 1;
                break;
            }
        }
    }
    // abc abd acd acb bcd
    for (int i = 0; i < 4; i++)
    {
        if (flag == 1)
            break;
        for (int j = 0; j < 4; j++)
        {
            if (flag == 1)
                break;
            for (int k = 0; k < 4; k++)
            {
                if (coding[i] + coding[j] + coding[k] == number)
                {
                    result[i] = '1';
                    result[j] = '1';
                    result[k] = '1';
                    flag = 1;
                    break;
                }
            }
        }
    }
    // abcd
    if (flag == 0)
    {
        result[0] = '1';
        result[1] = '1';
        result[2] = '1';
        result[3] = '1';
    }
    sprintf(storage.bin, "%s", result);
    return storage;
}

final_result binary_addition(char addent[], char augent[])
{
    int carry = 0;
    final_result result = {"00000"};
    // Calculating bin addition
    for (int j = 3; j >= 0; j--)
    {
        if (addent[j] == '1' && augent[j] == '1')
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '1';
                carry = 1;
            }
            else
            {
                result.bin[j + 1] = '0';
                carry = 1;
            }
        }
        else if ((addent[j] == '1' && augent[j] == '0') || (addent[j] == '0' && augent[j] == '1'))
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '0';
                carry = 1;
            }
            else
            {
                result.bin[j + 1] = '1';
                carry = 0;
            }
        }
        else
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '1';
                carry = 0;
            }
            else
            {
                result.bin[j + 1] = '0';
                carry = 0;
            }
        }
    }
    if (carry == 1)
        result.bin[0] = '1';
    else
        result.bin[0] = 32;
    return result;
}

final_result binary_addition_addSix(char addent[], char augent[], int *original_carry)
{
    int carry = *original_carry;
    int size = strlen(addent) - 1;
    final_result result = {"00000"};
    // Calculating bin addition
    for (int j = size; j >= 0; j--)
    {
        if (addent[j] == '1' && augent[j] == '1')
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '1';
                carry = 1;
            }
            else
            {
                result.bin[j + 1] = '0';
                carry = 1;
            }
        }
        else if ((addent[j] == '1' && augent[j] == '0') || (addent[j] == '0' && augent[j] == '1'))
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '0';
                carry = 1;
            }
            else
            {
                result.bin[j + 1] = '1';
                carry = 0;
            }
        }
        else
        {
            if (carry == 1)
            {
                result.bin[j + 1] = '1';
                carry = 0;
            }
            else
            {
                result.bin[j + 1] = '0';
                carry = 0;
            }
        }
    }
    if (result.bin[0] == '1')
    {
        result.bin[0] = 32;
        carry = 1;
    }
    *original_carry = carry;
    return result;
}

