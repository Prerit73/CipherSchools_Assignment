#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Entered elements are ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete a;
}