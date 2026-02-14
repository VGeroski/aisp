/**
 * Napisati program koji isputuje da li je unesti prirodan broj prost.
 */

#include <iostream>

using std::cout;
using std::cin;

// funkcija koja proverava da li je dati broj prost
bool prost(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0)
            // nasli smo delilac broja
            return false;

    return true;
}

bool prost_poboljsan(int n)
{
    // posto se delioca broja uvek nalaze u paru,
    // mozemo da ispitujemo samo da li postoji manji delilac
    // ako on postoji, postoji i veliki delilac - granica je oko sqrt(n)

    if (n == 1)
        return false;
    // dodatna optimizacija, provera parnih i onda proveravamo samo neparne
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    // nakon provere da li je broj paran, proveramo samo delioce od 3
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    int n;
    cin >> n;
    // vreme za 01.in oko 1.3 [s]
    // cout << (prost(n) ? "DA" : "NE") << '\n';
    // vreme za 01.in oko 0.006 [s]
    cout << (prost_poboljsan(n) ? "DA" : "NE") << '\n';

    return 0;
}
