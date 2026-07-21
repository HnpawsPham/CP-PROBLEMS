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
#define taskname "DCD"

int x;

namespace sub1{
    const int maxn = 44725;

    void sol(){
        ll lim = 2 * x;
        for(int n = sqrt(lim); n > 2; n--){
            if(lim % n) continue;

            int m = lim / n;
            for(int d = m; d > 0; d--){
                int u1 = m - d * (n - 1); 
                if(u1 <= 0 || (u1 & 1)) continue;

                u1 /= 2;
                for(int i = 0; i < n; i++)
                    cout<<u1 + d * i<<" ";
                return;
            }
        }
        
        cout<<-1;
        return;
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

    cin>>x;
    sub1::sol();

    return 0;
}