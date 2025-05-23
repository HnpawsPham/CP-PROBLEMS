#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int q, l, r;
const int maxn = 5e6 + 5, maxnum = 55;
bool nprime[maxnum] = {0};
int p[maxn];

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxnum); i++)
        if(!nprime[i])
            for(int j = i + i; j < maxnum; j+=i)
                nprime[j] = 1;
    
    return;
}

bool check(int x){
    int sum = 0;
    ll mul = 1;

    while(x > 0){
        int d = x % 10;
        sum += d;
        mul *= (ll)d;
        x /= 10;
    }

    if(nprime[sum]) return 0;
    string s = to_string(mul);
    int len = s.length();

    for(int i = 0; i < len / 2; i++)
        if(s[i] != s[len - i - 1]) return 0;
    
    return 1;
}

int main(){
    freopen("ABSOLUTECINEMA.INP", "r", stdin);
    freopen("ABSOLUTECINEMA.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    sieve();
    p[0] = 0;

    for(int i = 1; i < maxn; i++){
        p[i] = p[i - 1] + check(i);
    }

    while(q--){
        cin>>l>>r;
        cout<<p[r] - p[l - 1]<<el;
    }

    return 0;
}