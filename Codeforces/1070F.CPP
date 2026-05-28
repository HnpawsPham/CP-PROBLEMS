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

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    vi a01, a10, b;
    int res = 0, cnt11 = 0;

    while(q--){
        string s;
        int x;
        cin>>s>>x;
        if(s == "11"){
            res += x;
            cnt11++;
        }
        else if(s == "01") a01.push_back(x);
        else if(s == "10") a10.push_back(x);
        else b.push_back(x);
    }
    sort(a01.begin(), a01.end(), greater<int>());
    sort(a10.begin(), a10.end(), greater<int>());
    
    int n = a01.size(), m = a10.size();
    int sz = min(n, m);
    for(int i = 0; i < sz; i++)
        res += a01[i] + a10[i];
    
    for(int i = sz; i < n; i++)
        b.push_back(a01[i]);
    for(int i = sz; i < m; i++) 
        b.push_back(a10[i]);

    sort(b.begin(), b.end());
    while(!b.empty() && cnt11--){
        res += b.back();
        b.pop_back();
    }
    cout<<res;
    return 0;
}