#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int q;
const int maxc = 1e7;
vector<ll> sum(maxc + 3, 0);
vi res(maxc + 3, -1), nprime(maxc + 3, 0);

void sieve() {
    for (int i = 2; i <= maxc; i++) 
        if (!nprime[i]) 
            for (int j = i; j <= maxc; j += i)
                if (!nprime[j]) nprime[j] = i;
        
    sum[1] = 1;
    for (int i = 2; i <= maxc; i++) {
        int p = nprime[i], x = i, cnt = 0;
        ll mul = 1;
        while (x % p == 0) {
            x /= p;
            cnt++;
            mul *= p;
        }
        sum[i] = sum[x] * ((mul * p - 1) / (p - 1));
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    sieve();

    for(int i = 1; i <= maxc; i++)
        if(sum[i] <= maxc && res[sum[i]] == -1) res[sum[i]] = i;

    while(q--){
        int x;
        cin>>x;
        cout<<res[x]<<el;
    }

    return 0;
}