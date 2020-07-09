#include <iostream>
using namespace std;

bool checkLeapYear(int year)
{
    return ((year % 4 && year % 100 != 0) || year % 400 == 0) ? true : false;
}
int main()
{
    while (true)
    {
    startAgain:
        cout << "Input month?" << endl;
        int month;
        cin >> month;
        if (month < 1 || month > 12)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            switch (month)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                cout << "Has 30 days!" << endl;
                break;
            case 2:
            {
                cout << "Input year?";
                int year;
                cin >> year;
                if (year < 1900 || year > 9999)
                {
                    cout << "Invalid" << endl;
                }
                else
                {
                    if (checkLeapYear(year))
                    {
                        cout << "Has 29 days" << endl;
                    }
                    else
                    {
                        cout << "Has 28 days" << endl;
                    }
                }
            }

            default:
                cout << "Has 31 days" << endl;
                break;
            }
        }
        string option;
        cout << "Do you want to continue?(Y/N): ";
        cin >> option;
        if (option == "Y")
        {
            goto startAgain;
        }
        else
        {
            break;
        }
    }

    system("pause");
    return 0;
}