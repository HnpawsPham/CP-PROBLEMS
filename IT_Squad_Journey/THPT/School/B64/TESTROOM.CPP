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
#define taskname "TESTROOM"

int n, k;
const ll oo = 1e14 + 5;
const int maxn = 1e4 + 5;
int a[maxn];

namespace sub1{
    void sol(){
        int m = *max_element(a, a + n);
        ll res = oo;
        
        for(int i = 0; i < (1 << m); i++){
            if(__builtin_popcount(i) != k) continue;

            vi b;
            for(int j = 0; j < m; j++)
                if(1 & (i >> j)) 
                    b.push_back(j + 1);

            ll sum = 0;
            for(int i = 0; i < n; i++){
                ll minn = oo;
                for(const int& x : b)
                    minn = min(minn, 1LL * abs(a[i] - x));
                sum += minn;
            }
            res = min(res, sum);
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
    
    cin>>n>>k;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];

    sub1::sol();
    return 0;
}