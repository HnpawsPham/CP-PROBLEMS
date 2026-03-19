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

ll sol(){
    int n;
    cin>>n;
    vector<pii> a;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        if(x < i + 1)
            a.push_back({x, i + 1}); 
    }
    sort(a.begin(), a.end());

    ll cnt = 0;
    n = a.size();

    for(const pii& x : a){
        int l = 0, r = n - 1, mid, pos = n; 
        while(l <= r){
            mid = (l + r) / 2;
            if(a[mid].fi > x.se){
                r = mid - 1;
                pos = mid;
            }
            else l = mid + 1;
        }
        cnt += n - pos;
    }
    return cnt;
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