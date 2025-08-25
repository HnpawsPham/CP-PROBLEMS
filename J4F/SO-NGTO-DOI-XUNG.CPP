#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e7 + 5;
bitset<maxn> nprime;

void sieve(){
    for(int i = 2; i <= sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i) 
                nprime[j] = 1;
    return;
}

bool check(int x){
    int rx = 0;
    while(x > 0){
        rx = rx * 10 + (x % 10);
        x /= 10;
    }
    return !nprime[rx];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    sieve();

    for(int i = 2; i <= n; i++)
        if(!nprime[i]) if(check(i)) cout<<i<<" ";
    return 0;
}