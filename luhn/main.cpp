#include <iostream>
#include "luhn.h"
using namespace std;

int main()
{
    char number[100];

    cout << "Luhn Checksum Validator" << endl;

    while (true)
    {
        cout << "\nEnter a 16-digit number (or q to exit): ";

        if (!cin.getline(number, 100))
        {
            if (cin.eof())
                break;

            cin.clear();

            char extra;
            while (cin.get(extra) && extra != '\n')
            {
            }

            cout << "Invalid input. Enter exactly 16 digits." << endl;
            continue;
        }

        if ((number[0] == 'q' || number[0] == 'Q')
            && number[1] == '\0')
        {
            break;
        }

        if (!validInput(number))
        {
            cout << "Invalid input. Enter exactly 16 digits." << endl;
        }
        else
        {
            if (checkLuhn(number))
            {
                cout << "Luhn checksum PASSED!" << endl;
            }
            else
            {
                cout << "Luhn checksum FAILED!" << endl;
            }
        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}
