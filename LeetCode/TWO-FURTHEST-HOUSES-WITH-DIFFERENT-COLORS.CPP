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
    int color[105];
    memset(color, -1, sizeof color);

    int res = 0;
    for(int i = 0; i < n; i++){
        if(color[a[i]] == -1) color[a[i]] = i;
        for(int j = 0; j <= 100; j++)
            if(j != a[i] && color[j] != -1) 
                res = max(res, i - color[j]);
    }
    cout<<res;
    return 0;
}