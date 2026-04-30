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

bool comp(const pii& a, const pii& b){
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se < b.se;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int b[n];
    for(int i = 0; i < n; i++) cin>>b[i];

    pii a[n];
    for(int i = 1; i < n; i++){
        a[i].se = b[i];
        a[i].fi = b[i - 1];
        if(a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
    }
    sort(a, a + n, comp);

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++){
            if(a[i].fi > a[j].fi && a[i].fi < a[j].se && a[i].se > a[j].se) 
                return cout<<"yes", 0;
        }
    cout<<"no";
    return 0;
}