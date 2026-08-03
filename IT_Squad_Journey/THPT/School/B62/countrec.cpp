#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "countrec"

int n;

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    map<int, vi> mpx;
    map<pii, ll> cnt;
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        mpx[x].push_back(y);
    }

    ll res = 0;
    for(const auto& [x, v] : mpx){
        int m = v.size();

        for(int i = 0; i < m - 1; i++)
            for(int j = i + 1; j < m; j++){
                pii cur = {min(v[i], v[j]), max(v[i], v[j])};
                res += cnt[cur];
                cnt[cur]++;
            }
    }
    cout<<res;
    return 0;
}