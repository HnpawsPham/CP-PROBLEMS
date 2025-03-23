#include <iostream>
#include <cmath>
using namespace std;
#define el "\n"

int l, r;
const int maxn = 2e5 + 5;
bool nprime[maxn];

void sieve(){
    nprime[1] = 1;
    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r;
    sieve();

    for(int i = l; i <= r; i++)
        if(!nprime[i]) cout<<i<<el;

    return 0;
}