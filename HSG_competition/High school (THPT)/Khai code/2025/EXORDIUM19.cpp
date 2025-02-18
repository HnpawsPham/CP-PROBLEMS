#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 5 * (int)1e6 + 5;
bool nprime[maxn];

void sieve(){
    nprime[1] = nprime[0] = 1;
    
    for(int i = 2; i * i < maxn; i++){
        if(!nprime[i])
        for(int j = i * i; j < maxn; j+=i) nprime[j] = 1;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sieve();
    for(int i = 0; i <= n; i++) if(!nprime[i]) cout<<i<<" ";

    return 0;
}