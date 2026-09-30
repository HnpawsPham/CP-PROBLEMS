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

    int maxx = *max_element(a, a + n);
    int res = 0, cnt = 0;
    for(int i = 0; i < n ;i++)
        if(a[i] == maxx){
            cnt++;
            res = max(res, cnt);
        }
        else cnt = 0;
    cout<<res;
    return 0;
}