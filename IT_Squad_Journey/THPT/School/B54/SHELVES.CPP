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
#define taskname "SHELVES"

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
    ll a[n + 15] = {0}, b[m + 15] = {0};
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= m; i++){
        cin>>b[i];
        b[i] += b[i - 1];
    }

    vi resa, resb;
    int i = 1, j = 1;
    ll h = 0;
    while(i <= n && j <= m){
        while(i <= n && a[i - 1] < h) i++;
        while(j <= m && b[j - 1] < h) j++;

        if(i > n || j > m) break;

        if(a[i] < b[j]){
            resa.push_back(i);
            h = a[i++];
        }
        else{
            resb.push_back(j);
            h = b[j++];
        }
    }

    while(i <= n){
        if(a[i - 1] >= h)
            resa.push_back(i);
        i++;
    }
    while(j <= m){
        if(b[j - 1] >= h) 
            resb.push_back(j);
        j++;
    }

    cout<<resa.size()<<" "<<resb.size()<<el;
    for(int x : resa) cout<<x<<" ";
    cout<<el;
    for(int x : resb) cout<<x<<" ";
    return 0;
}

// 5 5
// 1 2 3 4 5
// 6 4 3 2 1