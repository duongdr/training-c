// Write a program in C++ to check whether a number is prime or not.
#include <iostream>

using namespace std;

int main5()
{
    int n;
    cout << "Input a number to check prime or not: ";
    cin >> n;
    int count = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << "The entered number is a prime number." << endl;
    }
    else
    {
        cout << "The entered number is a not prime number." << endl;
    }

    system("pause");
    return 0;
}