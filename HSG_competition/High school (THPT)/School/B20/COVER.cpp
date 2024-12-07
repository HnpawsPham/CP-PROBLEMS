#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

struct de{
    ll l, r;
    de(ll l1, ll r1) : l(l1), r(r1) {};
};

int n, q;
const int maxn = 200005;
vector<de> a;

int main(){
    freopen(".\\txt\\COVER.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        ll l, r;
        cin>>l>>r;
        a.push_back(de(l, r));
    }
    cin>>q;

    while(q--){
        ll l, r;
        cin>>l>>r;
    }

    return 0;
}