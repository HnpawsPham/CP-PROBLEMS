#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, total = 0, res = -1;
const int maxn = 22;
const int maxp = 2e6 + 5;
int a[maxn];
bitset<maxp> nprime;

void sieve(){
    nprime[1] = nprime[0] = 0;

    for(int i = 2; i < sqrt(maxp); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j += i)
                nprime[j] = 1;
    return;
}

void sol(int i, int sum){
    if(i == n){
        int d = 2 * sum - total;

        if(d > 1 && !nprime[d] && d > res)
            res = d;
        return;
    }

    sol(i + 1, sum + a[i]);
    sol(i + 1, sum);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        total += a[i];
    }
    sieve();
    sol(0, 0);
    cout<<res;
    return 0;
}