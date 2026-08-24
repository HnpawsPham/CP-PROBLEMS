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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int cur = 1, sum = 0;
    vi res;

    for(int i = 0; i < n;){
        while(cur == a[i]){
            i++;
            cur++;
        }
        
        if(sum > m - cur) break;
        sum += cur;
        res.push_back(cur++);
    }

    while(sum <= m - cur){
        sum += cur;
        res.push_back(cur++);
    }
    
    cout<<res.size()<<el;
    for(const int& x : res) 
        cout<<x<<" ";
    return 0;
}