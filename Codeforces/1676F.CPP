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

void sol(){
    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 0; i < n ;i ++) cin>>a[i];  
    sort(a, a + n);
    a[n] = -1e9 - 5;

    int prev = a[0], l = -1, r = -1;
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] == a[i - 1]) cnt++;
        else{
            if(cnt >= k){
                if(l == -1 || a[i - 1] - prev > r - l){
                    r = a[i - 1];
                    l = prev;
                }
                if(a[i] != a[i - 1] + 1)
                    prev = a[i];
            }
            else prev = a[i];
            cnt = 1;
        }
    }

    if(l != -1 && r != -1) cout<<l<<" "<<r;
    else cout<<-1;
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
        sol();
        cout<<el;
    }
    return 0;
}