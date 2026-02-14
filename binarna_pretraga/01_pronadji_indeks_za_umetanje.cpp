/**
 * Dat je sortiran niz koji ima jedinstvene vrednosti, kao i ciljna vrednost.
 * Ako je cilj u nizu, vrati njegov indeks, inace vrati indeks za umetanje.
 * Indeks za umetanje bi bio onaj indeks na kome bi se nasla ciljna vrednost 
 * a da se ne narusi sortiranost niza.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int pronadji_indeks_umetanja(const vector<int> &niz, int cilj)
{
    if (niz.empty()) return 0;

    int l = 0, d = niz.size() - 1;

    while (l <= d)
    {
        int s = l + (d - l) / 2;

        if (niz[s] == cilj) return s;

        if (niz[s] > cilj) d = s - 1;
        else l = s + 1;
    }

    return l;
}

int main()
{
    vector<int> test = {1, 2, 4, 5, 7, 8, 9};
    cout << "Test kada ciljna vrednost postoji\n";
    cout << "  indeks: " << pronadji_indeks_umetanja(test, 4) << '\n';

    cout << "Test kada ciljna vrednost ne postoji u nizu\n";
    cout << "  indeks (za umetanje): " << pronadji_indeks_umetanja(test, 6) << '\n';

    return 0;
}
