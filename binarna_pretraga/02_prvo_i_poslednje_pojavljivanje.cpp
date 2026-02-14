/**
 * Dat je niz celih brojeva. Sortirani su u neopadajucem poretku.
 * Naci indekse prvog i poslednjeg pojavljivanja ciljnog broja.
 *
 * Primer: [1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11]; cilj = 4
 * izlaz: [3, 5]
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int donja_granica_binarne_pretrage(const vector<int> &niz, int cilj)
{
    int l = 0, d = niz.size() - 1;

    // dok se pokazivaci ne sretnu
    while (l < d)
    {
        int sr = l + (d - l) / 2;
        if (niz[sr] > cilj)
            d = sr - 1;
        else if (niz[sr] < cilj)
            l = sr + 1;
        // nasli smo ciljnju vrednost,
        // ali probamo levo da nadjemo prvo pojavljivanje
        else
            d = sr;
    }

    // moramo da proverimo da li uopste ciljna vrednost postoji u nizu
    // samo ako postoji, vracamo levi pokazivac, inace -1
    return (niz[l] == cilj ? l : -1);
}

int gornja_granica_binarne_pretrage(const vector<int> &niz, int cilj)
{
    int l = 0, d = niz.size() - 1;
    while (l < d)
    {
        // bitno je da vezemo srednji el za desni pokazivac
        int sr = l + (d - l) / 2 + 1;
        if (niz[sr] > cilj)
            d = sr - 1;
        else if (niz[sr] < cilj)
            l = sr + 1;
        else
            l = sr;
    }

    // ako cilj ne postoji, l = sr + 1 moze da izbaci pokazivac iz niza
    // zato proveravamo preko desnog
    return (niz[d] == cilj ? d : -1);
}

vector<int> prvo_poslednje_pojavljivanje_broja(const vector<int> &niz, int cilj)
{
    if (niz.empty())
        return {};

    int donja_granica = donja_granica_binarne_pretrage(niz, cilj);
    int gornja_granica = gornja_granica_binarne_pretrage(niz, cilj);

    return {donja_granica, gornja_granica};
}

int main()
{
    vector<int> test = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11};
    int cilj = 4;
    vector<int> indeksi = prvo_poslednje_pojavljivanje_broja(test, cilj);

    cout << "Prvo i poslendnje pojavljivanje broja na indeksima: [";
    cout << indeksi[0] << ", " << indeksi[1] << "]\n";

    return 0;
}