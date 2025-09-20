#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n, m;
const int maxn = 1e6 + 5;
int spf[maxn];

void sieve(){
    spf[1] = 1;
    for(int i = 2; i < maxn; i++)
        if(!spf[i])
            for(int j = i; j < maxn; j+=i)
                if(!spf[j]) spf[j] = i;
    return;
}

string sol(){
    int n, m;
    cin>>n>>m;

    if(n > 1 && spf[n] <= m) return "no";
    return "yes";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    sieve();
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}