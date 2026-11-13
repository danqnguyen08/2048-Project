#include "luhn.h"

bool validInput(const char number[])
{
    int length = 0;

    for (int i = 0; number[i] != '\0'; i++)
    {
        if (number[i] < '0' || number[i] > '9')
            return false;

        length++;
    }

    if (length != 16)
        return false;

    return true;
}

bool checkLuhn(const char number[])
{
    int sum = 0;
    bool doubleDigit = false;

    for (int i = 15; i >= 0; i--)
    {
        int digit = number[i] - '0';

        if (doubleDigit)
        {
            digit = digit * 2;

            if (digit > 9)
                digit = digit - 9;
        }

        sum = sum + digit;

        doubleDigit = !doubleDigit;
    }
    
    if (sum % 10 == 0)
        return true;
    else
        return false;
}
