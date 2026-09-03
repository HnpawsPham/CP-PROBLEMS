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

    int cnt = 0, res = 0;
    for(int i = n - 1; i >= 0; i--)
        if(s[i] == '<') cnt++;
        else if(cnt > 0) 
            res = max(cnt, res + 1);
    cout<<res;
    return 0;
}