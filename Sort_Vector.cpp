#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool User_Def(int item1, int item2);
int main()
{
    vector<int> v = {9, 5, 6, 2, 7, 1};
    cout << "Before sorting: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });

    sort(v.begin(), v.end());
    cout << endl << "After sorting: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    sort(v.begin(), v.end(), greater<int>());
    cout << endl << "After re-sorting: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    sort(v.begin(), v.end(), User_Def);
    cout << endl << "After re-sorting by user defined: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    system("pause");
    return 0;
}
bool User_Def(int item1, int item2)
{
    return item1 > item2;
}
