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
#define taskname "BAPBENH"

int n, m;
const int maxn = 1e4 + 5;
int a[maxn], b[maxn];

namespace sub1{
    void sol(){ //1 > ; 0 <
        int res = 0;

        for(int i = 0; i < (1 << n); i++){
            vi v;
            for(int j = 0; j < n; j++)
                if((i>> j) & 1) v.push_back(a[j]);

            int sz = v.size();
            if(sz < 3) continue;

            int pos = 0;
            bool ok = 1;
            for(const int& x : v){
                while(pos < m && b[pos] != x) pos++;
                if(pos == m){
                    ok = 0;
                    break;
                }
            }
            if(!ok) continue;

            bool gud = 1;
            for(int j = 1; j < sz - 1; j++)
                if((v[j] - v[j - 1]) * (v[j] - v[j + 1]) <= 0){
                    gud = 0;
                    break;
                }

            if(gud) res = max(res, sz);
        }
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sub1::sol();
    return 0;
}