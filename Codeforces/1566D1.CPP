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

int tc = 1;

bool comp(const pii& a, const pii& b){
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

int sol(){
    int n, x;
    cin>>n>>n;
    pii a[n];
    for(int i = 0; i < n; i++){
        cin>>x;
        a[i] = {x, i};
    }
    sort(a, a + n, comp);

    int b[n];
    for(int i = 0; i < n; i++)
        b[a[i].se] = i;

    int res = 0;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(b[i] > b[j]) res++;
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}