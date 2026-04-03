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

string sol(){
    int n, l, r, x;
    cin>>n>>l>>r;
    bool a[101] = {0};
    int st = 101, en = 0;
    for(int i = 0; i < n; i++){
        cin>>x;
        a[x] = 1;
        st = min(x, st);
        en = max(x, en);
    }

    bool ok = 1;
    for(int i = st + l + 1; i <= 100; i++)
        if(a[i] && i + r < en){
            ok = 0;
            break;
        }
    if(ok) return "YES";

    ok = 1;
    for(int i = st + r + 1; i <= 100; i++)
        if(a[i] && i + l < en){
            ok = 0;
            break; 
        }
    return (ok ? "YES" : "NO");
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