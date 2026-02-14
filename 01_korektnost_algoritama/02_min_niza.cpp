#include <iostream>

using std::cout;
using std::endl;
using std::min;

int min_niza_i(int a[], int n)
{
    int min_niza = a[0];
    for (int i = 1; i < n; i++)
        min_niza = min(min_niza, a[i]);

    return min_niza;
}

int min_niza_r(int a[], int n)
{
    if (n == 1)
        return a[0];

    int min_niza = min_niza_r(a, n - 1);
    return min(min_niza, a[n - 1]);
}

int main()
{
    int a[] = {3, 5, 4, 1, 6, 2, 7};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Minimum (iterativno): " << min_niza_i(a, n) << endl;
    cout << "Minimum (rekurzivno): " << min_niza_r(a, n) << endl;
}