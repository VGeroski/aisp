/**
 * Napisati program koji ucitava niz celih brojeva i dodatno dva broja (A i B).
 * Transformitsati niz tako da elementi budu podeljeni u tri dela
 * u zavisnosti od vrednosti A i B. U prvom delu su manji od A,
 * u drugom veci ili jednaki od A i manji ili jednaki vrednosti B,
 * a u trecem su svi elementi veci od B.
 * Nije bitno u kom redosledu su elementi unutar delova.
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

void ispisi_niz(const vector<int> &niz)
{
    for (int x : niz)
        cout << x << " ";
    cout << '\n';
}

void trobojka(vector<int> &niz, int A, int B)
{
    // odrzavamo <<<<=====????>>>>
    //               l    i   d
    int i = 0, l = 0;
    int d = niz.size();

    while (i < d)
    {
        // prvi deo niza (-inf, A)
        if (niz[i] < A)
        {
            swap(niz[i], niz[l]);
            i++;
            l++;
        }
        // drugi deo niza [A, B]
        else if (niz[i] <= B)
        {
            i++;
        }
        // treci deo niza (B, inf)
        else
        {
            d--;
            swap(niz[i], niz[d]);
        }
    }
}

int main()
{
    int n, A, B;

    cout << "Unesite broj elemenata: ";
    cin >> n;

    vector<int> niz(n);
    cout << "Unesite elemente niza: ";
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    cout << "Unesite A i B vrednosti: ";
    cin >> A;
    cin >> B;

    ispisi_niz(niz);

    trobojka(niz, A, B);

    cout << "Niz nakon premestanja elemenata: \n";
    ispisi_niz(niz);

    return 0;
}