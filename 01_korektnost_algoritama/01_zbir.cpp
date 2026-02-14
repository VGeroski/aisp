#include <iostream>

using std::cout;
using std::endl;

int zbir_i(int a[], int n)
{
    int zbir = 0;
    for (int i = 0; i < n; i++)
        zbir += a[i];

    return zbir;
}

int zbir_r(int a[], int n)
{
    if (n == 0)
        return 0;

    return zbir_r(a, n - 1) + a[n - 1];
}

int main()
{
    int a[] = {1, 2, 5, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Zbir (iterativno): " << zbir_i(a, n) << endl;
    cout << "Zbir (rekurzivno): " << zbir_r(a, n) << endl;
}