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
    
    int in[n];
    memset(in, 0, sizeof in);
    for(int i = 0; i < n; i++)
        in[a[i]]++;

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(!in[i]) q.push(i);

    int d[n];
    memset(d, 0, sizeof d);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        d[a[u]] = max(d[a[u]], d[u] + 1);
        in[a[u]]--;     

        if(!in[a[u]]) q.push(a[u]);
    }

    int cnt2 = 0, maxc = 0;
    for(int i = 0; i < n; i++){
        if(!in[i]) continue;

        int cur = i, sz = 0;
        while(in[cur]){
            in[cur] = 0;
            cur = a[cur];
            sz++;
        }

        if(sz == 2)
            cnt2 += 2 + d[a[i]] + d[i];
        else maxc = max(maxc, sz);
    }
    cout<<max(maxc, cnt2);
    return 0;
}