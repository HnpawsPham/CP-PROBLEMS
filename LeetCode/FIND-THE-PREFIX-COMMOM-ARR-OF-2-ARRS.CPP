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
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    
    vector<int> cnta(51, 0), cntb(51, 0), res(n, 0);
    for(int i = 0; i < n; i++){
        cnta[a[i]]++;
        cntb[b[i]]++;

        int cnt = 0;
        for(int i = 0; i < 51; i++)
            cnt += min(cnta[i], cntb[i]);
        res[i] = cnt;
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

4
1 3 2 4
3 1 2 4