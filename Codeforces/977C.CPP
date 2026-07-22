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

int n, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    a[n] = -1;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    // for(int x : a) cout<<x<<" ";
    // cout<<el;

    if(k == 0) 
        return cout<<(a[0] > 1 ? 1 : -1), 0;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt++;

        if(a[i] != a[i + 1]){
            if(cnt == k) return cout<<a[i], 0;
            if(cnt > k) return cout<<-1, 0;
        }
    }
    return 0;
}