/**
 * Dat je sakup prirodnihg brojeva (sortiran).
 * Odrediti najmanji prirodan broj koji nije zbir nekih elemenata tog skupa.
 * Svaki element skupa moze samo jednom ucestvovati u zbiru.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void najmanji_koji_nije_zbir(const vector<int> &niz)
{
    int zbir = 0;
    for (int i = 0; i < niz.size(); i++)
    {
        if (niz[i] > (zbir + 1))
            break;

        zbir += niz[i];
    }

    cout << "Najmanji broj koji nije zbir nekih elemenata: "
         << zbir + 1 << '\n';
}

int main()
{
    vector<int> test = {1, 2, 4, 7, 15, 32, 35, 48};
    vector<int> test2 = {1, 2, 3, 5, 14, 20, 27};

    najmanji_koji_nije_zbir(test);
    najmanji_koji_nije_zbir(test2);

    return 0;
}
