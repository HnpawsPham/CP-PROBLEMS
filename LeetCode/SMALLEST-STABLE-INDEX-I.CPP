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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++);

    int p[n], s[n];
    p[0] = a[0];
    s[n - 1] = a[n - 1];
    for(int i = 1; i < n; i++)
        p[i] = max(p[i - 1], a[i]);
    for(int i = n - 2; i >= 0; i--)
        s[i] = min(s[i + 1], a[i]);

    int res = -1;
    for(int i = 0; i < n; i++)
        if(p[i] - s[i] <= k){
            if(res == -1 || a[i] < res)
                res = a[i];
        }
    cout<<res;
    return 0;
}