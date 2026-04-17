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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1];
    for(int i = 1; i <= n; i++)
        cin>>a[i];

    vi v;
    while(m--){
        int l, r, x;
        cin>>l>>r>>x;

        int cnt = 0;
        for(int i = l; i <= r; i++)
            if(a[i] < a[x]) cnt++;
        
        if(cnt == x - l) cout<<"Yes"<<el;
        else cout<<"No"<<el;
    }
    return 0;
}