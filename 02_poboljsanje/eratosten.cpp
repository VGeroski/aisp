/**
 * Napisati program koji odredjuje broj prostih brojeva u intervalu [a, b]
 * i njihov zbir (ako zbir ima vise od 6 cifara, ispisati ostatak pri deljenju sa 1000000).
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

// funkcija koja popunjava logicki niz podacima
// o prostim brojevima iz intervala [0, n]
void eratosten(vector<bool> &prost, int n)
{
    prost.resize(n + 1, true);
    // 0 i 1 nisu prosti
    prost[0] = prost[1] = false;

    // brojevi ciji se umnosci precrtavaju
    for (int i = 2; i * i <= n; i++)
    {
        // oni koju su vec precrtani, njih necemo ponovo da precrtavamo
        if (prost[i])
        {
            for (int j = i * i; j <= n; j += i)
                prost[j] = false;
        }
    }
}

// funkcija odredjuje broj i zbir po modulu 1000000 prostih brojeva iz
// intervala [a, b]
void prosti_u_intevalu(int a, int b, int &broj, int &zbir)
{
    // odredjujemo proste brojeve u intervalu [0, b]
    vector<bool> prost;
    eratosten(prost, b);
    // analiziramo jedan po jedan broj u intervalu
    zbir = 0;
    broj = 0;
    for (int i = a; i <= b; i++)
    {
        if (prost[i])
        {
            cout << "prost broj: " << i << '\n';
            zbir = (zbir + i) % 1000000;
            broj++;
        }
    }
}

int main()
{
    int br = 0;
    int zb = 0;
    prosti_u_intevalu(0, 100, br, zb);

    cout << "broj: " << br << ", zbir: " << zb << '\n';

    return 0;
}