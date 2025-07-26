#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;
    cin>>n;

    ll res = 0;
    
    if (n > 0) {
        if (n <= 50) 
            res = (ll)n * 1700;
        else if (n <= 150) 
            res = (ll)50 * 1700 + (ll)(n - 50) * 1950;
        else if (n <= 250) 
            res = (ll)50 * 1700 + (ll)100 * 1950 + (ll)(n - 150) * 2130;
        else if (n <= 400) 
            res = (ll)50 * 1700 + (ll)100 * 1950 + (ll)100 * 2130 + (ll)(n - 250) * 2320;
        else if (n <= 550) 
            res = (ll)50 * 1700 + (ll)100 * 1950 + (ll)100 * 2130 + (ll)150 * 2320 + (ll)(n - 400) * 2520;
        else 
            res = (ll)50 * 1700 + (ll)100 * 1950 + (ll)100 * 2130 + (ll)150 * 2320 + (ll)150 * 2520 + (ll)(n - 550) * 2780;
    }
    res = res * 1.15;
    cout << res;
    return 0;
}