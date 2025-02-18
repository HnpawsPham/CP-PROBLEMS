#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll m, n;
const ll limit = (int)1e6;

ll donen(ll x){
    int cnt = 0;
    while(x > 2){
        for(int i = 2; i < x; i++){
            if(x % i != 0){
                x = i;
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

void solve(){
    int sum = 0;

    ll en = min(m + limit, n);
    for(ll i = m; i <= en; ++i) sum += donen(i);

    if(n > m + limit){
        sum += n - (m + limit);
    }
    cout<<sum;
    return;
}

int main(){
    freopen(".\\txt\\BAI1.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;

    solve();
    return 0;
}