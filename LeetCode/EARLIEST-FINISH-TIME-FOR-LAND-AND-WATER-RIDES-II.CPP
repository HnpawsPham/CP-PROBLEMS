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

const int oo = 3e5 + 5;
int sol(const vi& st1, const vi& t1, const vi& st2, const vi& t2){
    int cost1 = oo, n = st1.size();
    for(int i = 0; i < n; i++)
        cost1 = min(cost1, st1[i] + t1[i]);

    int cost2 = oo, m = st2.size();
    for(int i = 0; i < m; i++)
        cost2 = min(cost2, max(st2[i], cost1) + t2[i]);
    return cost2;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vi landst(n), landt(n), waterst(m), watert(m);
    for(int i = 0; i < n; i++) cin>>landst[i];
    for(int i = 0; i < n ; i++) cin>>landt[i];
    for(int i = 0; i < m; i++) cin>>waterst[i];
    for(int i = 0; i < m; i++) cin>>watert[i];

    cout<<min(sol(landst, landt, waterst, watert), sol(waterst, watert, landst, landt));
    return 0;
}

// 2 1
// 2 8
// 4 1
// 6
// 3