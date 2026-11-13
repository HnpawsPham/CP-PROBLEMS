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
//#define taskname ""

ll dis(pii a, pii b){
    return 1LL * (a.fi - b.fi) * 1LL * (a.fi - b.fi) + 1LL * (a.se - b.se) * 1LL * (a.se - b.se);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, f0, d;
    cin>>n>>f0>>d;
    pii a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].fi>>a[i].se;

    bool f1[n];
    memset(f1, 0, sizeof f1);

    int cntf1 = 0, cntf2 = 0;
    for(int i = 0; i < n; i++)
        if(i != f0 - 1 && dis(a[f0 - 1], a[i]) < 1LL * d * d){
            f1[i] = 1;
            cntf1++;
        }

    for(int i = 0; i < n; i++){
        if(i == f0 - 1 || f1[i]) continue;
        for(int j = 0; j < n; j++)
            if(f1[j] && dis(a[i], a[j]) < 1LL * d * d){
                cntf2++;
                break;
            }
    }
    cout<<cntf1<<" "<<cntf2;
    return 0;
}