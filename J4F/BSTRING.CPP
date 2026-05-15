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
    string s;
    cin>>n>>s;
    int cnt1 = 0;
    for(const char& x : s)
        cnt1 += (x == '1');

    int res = 0, cnt = 0;
    for(int i = 0; i < cnt1; i++)
        if(s[i] == '0') res++;
    
    for(int i = 0; i < n - cnt1; i++)
        if(s[i] == '1') cnt++;
    cout<<min(res, cnt);
    return 0;
}