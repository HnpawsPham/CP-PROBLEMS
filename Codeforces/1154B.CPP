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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int lim = *max_element(a, a + n), res = 105;
    for(int k = 0; k <= lim; k++){
        int prev = -1;
        for(int i = 0; i < n && prev == -1; i++)
            if(a[i] != k) prev = abs(a[i] - k);
        
        if(prev == -1) return cout<<0, 0;
        
        bool ok = 1;
        for(int i = 0; i < n && ok; i++){
            if(a[i] != k && a[i] + prev != k && a[i] - prev != k)
                ok = 0;
        }
        if(ok) res = min(res, prev);
    }
    cout<<(res == 105 ? -1 : res);
    return 0;
}