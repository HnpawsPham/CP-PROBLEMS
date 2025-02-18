#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 3 * (int)1e6 + 5;
bool nprime[maxn];

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++){
        if(!nprime[i])
            for(int j = i + i; j <= maxn; j+=i) nprime[j] = 1;
    }
    return;
}

int count(int p){
    return max(max(0, min(n, (p - 2)/2) - max(1, (p - n) /2)), 0);
}

int main(){
    freopen(".\\txt\\BIEU-THUC-NT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sieve();
    int cnt = 0;

    for(int i = 3; i < maxn; i++)
        if(!nprime[i]) cnt+= count(i);
    
    cout<<cnt;

    return 0;
}