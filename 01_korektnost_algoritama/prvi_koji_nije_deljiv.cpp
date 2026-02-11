/**
 * Razmotrimo brojeve: 210, 2310, 390, 30, 510, 66, 6, 138, 46, 106, 59, 17, 23.
 * Prvih pet brojeva je deljivo sa 10. Prvih deset brojeva je parno, posle su neparni.
 * Prvih osam brojeva je deljivo sa 6, posle nijedan nije deljiv sa 6.
 * Za uneti delilac, odredi koliko brojeva je deljivo njime.
 * Smatra se da vazi pravilnost monotonosti.
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::swap;
using std::vector;

int prvi_koji_nije_deljiv(const vector<long long> &a, long long k)
{
    int n = a.size();
    int l = 0, d = n - 1;

    while (l <= d)
    {
        int s = l + (d - l) / 2;
        if (a[s] % k == 0)
            l = s + 1;
        else
            d = d - 1;
    }

    return l;
}

int main()
{
    vector<long long> test = {210, 2310, 390, 30, 510, 66, 6, 138, 46, 106, 59, 17, 23};
    int indeks = prvi_koji_nije_deljiv(test, 10);
    cout << "prvi koji nije deljiv sa 10: " << test[indeks]
         << ", na indeksu: " << indeks << '\n';

    indeks = prvi_koji_nije_deljiv(test, 6);
    cout << "prvi koji nije deljiv sa 6: " << test[indeks]
         << ", na indeksu: " << indeks << '\n';

    indeks = prvi_koji_nije_deljiv(test, 2);
    cout << "prvi koji nije deljiv sa 2: " << test[indeks]
         << ", na indeksu: " << indeks << '\n';

    indeks = prvi_koji_nije_deljiv(test, 210);
    cout << "prvi koji nije deljiv sa 210: " << test[indeks]
         << ", na indeksu: " << indeks << '\n';

    return 0;
}