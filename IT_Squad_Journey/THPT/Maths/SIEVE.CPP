#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 1e6 + 5;
bitset<maxn> nprime;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j += i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    for(int i = 2; i <= 50; i++)
        if(!nprime[i]) cout<<i<<" ";

    return 0;
}