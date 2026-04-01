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
    int n, m, x;
    cin>>n>>m;
    int cnt[101] = {0};
    for(int i = 0; i < n; i++){
        cin>>x;
        cnt[x]++;
    }

    for(int i = 0; i < m; i++){
        cin>>x;
        cnt[x]++;
    }
    
    int res = 0;
    for(int i = 0; i <= 100; i++)
        if(cnt[i] > 1) res++;
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