/**
 * Dat je sakup prirodnihg brojeva (sortiran).
 * Odrediti najmanji prirodan broj koji nije zbir nekih elemenata tog skupa.
 * Svaki element skupa moze samo jednom ucestvovati u zbiru.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// najmanji broj koji nije zbir elemenata skupa
// 1, 2, 3, 5, 14, 20, 27

// 6 => 1 + 2 + 3 (moze)
// 19 => 2 + 3 + 14 (moze)

// npr, ako su obradjeni 1, 2, 3
// razmatramo koje brojeve je moguce dobiti
// uvek mozemo da dobijemo 0 i zbir svih
// 0    ...     6

// sta dobijamo kada redom obradjujemo brojeve:
// 0                   [0-0]
// 0, 1                [0-1]  1
// 0, 1, 2, 3          [0-3]  2
// 0, 1, 2, 3, 4, 5, 6 [0-6]  3
// ...                 [0-11] 5
// ...                 [0-11] [14-25] (razbija se interval)
// zato sto su brojevi sortirani,
// sigurno ni ostali ne mogu da naprave zbir da daje 12

// pomocu prvih k elemenata niza mogu se dobiti svi zbirovi iz intervala
// [0, a0 + a1 + ... + ak-1]

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
