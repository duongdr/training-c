//Write a program in C++ to calculate the series (1) + (1+2) + (1+2+3) + (1+2+3+4) + ... + (1+2+3+4+...+n).

#include <iostream>

using namespace std;

int main9()
{
    int num, sum = 0;
    cout << "Input the value for nth term: ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int isum = 0;
        for (int j = 1; j <= i; j++)
        {
            isum += j;
            if (j != i)
            {
                cout << j << "+";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << " = " << isum << endl;
        sum += isum;
    }
    cout << "The sum of the above series is: " << sum << endl;

    system("pause");
    return 0;
}