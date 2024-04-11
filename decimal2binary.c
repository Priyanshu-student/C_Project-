#include <stdio.h>

int findSize(int integer_part)
{
    int count = 0;
    
    while(integer_part > 0)
    {
        integer_part = integer_part / 2;
        count ++;
    }

    return count;
}

void conversion(double decimal_num, int precision)
{
    int integerPart;
    double decimalPart;
    integerPart = (int)decimal_num;
    decimalPart = decimal_num - integerPart;

    int arraySize;
    arraySize = findSize(integerPart);
    int array[arraySize];

    for(int i = 0; i < arraySize; i++)
    {
        array[i] = integerPart % 2;
        integerPart = integerPart / 2;
    }
    for(int i = arraySize-1; i >= 0; i--)
    {
        printf("%d",array[i]);
    }

    printf(".");

    for(int j = 0; j < precision; j++)
    {
        decimalPart = decimalPart * 2;    
        printf("%d",(int)decimalPart);
        decimalPart = decimalPart - (int)decimalPart;
    }
}

int main()
{
    double decimal_num;
    int precision = 8;
    printf("Enter the number: ");
    scanf("%lf",&decimal_num);

    conversion(decimal_num, precision);
    return 0;
}