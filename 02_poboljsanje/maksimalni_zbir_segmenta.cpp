/**
 * Napisati program koji odredjuje najveci zbir nekog segmenta datog niza.
 * Primer [2, 3, -2, -4, -8, 5, -1, 4, 2, -6]
 *                           -   -  -  -
 * izlaz: 10 (crticama je obelezen segment koji daje najveci zbir)
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int maks_zbir(const vector<int> &niz)
{
    int n = niz.size();
    int maks = 0;
    for (int i = 0; i < n; i++)
    {
        int zbir = 0;
        for (int j = i; j < n; j++)
        {
            zbir += niz[j];
            // optimizacija: cim zbir postane negativan,
            // taj segment ne moze da da maks zbir
            if (zbir < 0)
                break;

            /* umesto sto svaki put racunamo zbir za segment,
               mozemo inkrementalno da ga sracunamo
            int zbir = 0;
            for (int k = i; k <= j; k++)
                zbir += niz[k];
            */
            if (zbir > maks)
                maks = zbir;
        }
    }

    return maks;
}

int maks_zbir_odsecanje(const vector<int> &niz)
{
    int n = niz.size();
    int maks = 0;
    for (int i = 0; i < n; i++)
    {
        int zbir = 0;
        int j;
        for (j = i; j < n; j++)
        {
            zbir += niz[j];
            // optimizacija: cim zbir postane negativan,
            // taj segment ne moze da da maks zbir
            if (zbir < 0)
                break;

            if (zbir > maks)
                maks = zbir;
        }
        // dodatna optimizacija odsecanja: i za pozitivne
        i = j;
    }

    return maks;
}

int main()
{
    int n;
    cin >> n;

    vector<int> test(n);
    for (int i = 0; i < n; i++)
        cin >> test[i];

    int maks = maks_zbir_odsecanje(test);

    cout << maks << '\n';

    return 0;
}
