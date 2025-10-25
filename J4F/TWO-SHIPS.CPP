#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define mask(i, j) ((i >> j) & 1)

int n;
const int maxn = 10;
const int oo = 1e5 + 5;
pii a[maxn];

int d(pii x, pii y){
    return abs(x.fi - y.fi) + abs(x.se - y.se); 
}

int calc(pii st, vi v){
    if(v.empty()) return 0;
    sort(v.begin(), v.end());
    int res = oo;

    do{
        int sum = 0, m = 0;
        pii cur = st;
        for(int i : v){
            sum += m * d(a[i], cur);
            m++;
            cur = a[i];
        }
        sum += m * d(cur, st);
        res = min(res, sum);
    } 
    while(next_permutation(v.begin(), v.end()));
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii s, t;
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    cin>>s.fi>>s.se>>t.fi>>t.se;

    int res = oo;
    for(int i = 0; i < (1 << n); i++){
        vi g1, g2;

        for(int j = 0; j < n; j++){
            if(mask(i, j)) g1.push_back(j);
            else g2.push_back(j);
        }
        res = min(res, calc(s, g1) + calc(t, g2));
    }
    cout<<res;
    return 0;
}

// 3
// 1 1
// 2 2
// 3 3
// 0 0
// 4 4