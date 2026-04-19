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

    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    int i = 0, j = 0, res = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            res = max(res, j - i);
            j++;
        }
        else{
            i++;
            if(j < i) j = i;
        }
    }
    cout<<res;
    return 0;
}

// 5 5
// 55 30 5 4 2
// 100 20 10 10 5