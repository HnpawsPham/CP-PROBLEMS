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

    int n;
    cin>>n; 
    int cnt = 0;
    pii a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].fi>>a[i].se;

    for(int i = 0; i < n; i++){
        bool ok = 1;
        for(int j = 0; j < n && ok; j++)
            if(i != j && a[j].se == a[i].fi) ok = 0; 
        cnt += ok;
    }
    cout<<cnt;
    return 0;
}