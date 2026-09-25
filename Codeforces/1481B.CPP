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

int sol(){
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    if(k > 10000) return -1;

    int pos = -1;
    for(int i = 0; i < k; i++){
        bool ok = 0;
        for(int j = 1; j < n && !ok; j++){
            if(a[j - 1] < a[j]){
                pos = j;
                a[j - 1]++;
                ok = 1;
            }
        }
        if(!ok) return -1;
    }
    return pos;
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