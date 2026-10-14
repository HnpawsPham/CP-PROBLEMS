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
    vi a;

    int d = 0;
    for(int i = 0; i < n; i++){
        int t, k;
        cin>>t>>k;
        for(int j = 0; j < k; j++){
            int x;
            cin>>x;
            a.push_back(max(0, x - d));
        }
        d += t;
    }
    sort(a.begin(), a.end());

    int st = 0, sz = min((int)a.size(), m);
    if(sz > 0) 
        st = a[sz - 1];
    cout<<d + st;
    return 0;
}