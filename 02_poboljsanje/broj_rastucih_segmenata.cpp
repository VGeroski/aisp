/**
 * Dat je niz a celih brojeva, duzine n. Napisati program kojim se odredjuje na koliko nacina
 * mozemo izabrati rastuce segmente u nizu. Rastuci segment cine uzastopni elementi niza
 * a_p < a_{p+1} < ... < a_q; 0 <= p < q < n
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long broj_rastucih_segmenata(const vector<int> &a)
{
    int n = a.size();
    long long brRastucih = 0;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[j - 1])
                brRastucih++;
            // ako smo naisli na element koji je manji od prethodnog
            // svaki sledeci segment nije validan, odmah prelazimo na sledeci levi kraj
            else
                break;

    return brRastucih;
}

long long broj_rastucih_segmenata_v2(const vector<int> &a)
{
    // umesto da prebrojavamo svaki segment, mozemo da nadjemo maksimalni podsegment
    // a onda znamo da se od njega moze dobiti k * (k - 1) / 2 podsegmenata - k je broj elemenata
    int n = a.size();
    long long brRastucih = 0;

    int i = 0;
    while (i < n)
    {
        int j = i + 1;

        // trazimo maksimalni segment
        while (j < n && a[j] > a[j - 1])
            j++;

        // kad nadjemo dodamo broj svih mogucih podsegmenata
        long long k = j - i;
        brRastucih += k * (k - 1) / 2;

        i = j;
    }

    return brRastucih;
}

int main()
{
    int n;
    cin >> n;

    vector<int> niz(n);
    for (int i = 0; i < n; i++)
        cin >> niz[i];

    cout << "Broj rastucih segmenata: " << broj_rastucih_segmenata_v2(niz) << '\n';

    return 0;
}