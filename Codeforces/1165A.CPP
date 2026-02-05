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

int n, x, y;
string s; 

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x>>y>>s;
    int cnt = 0, i = n - 1;
    for(; i >= n - y; i--)
        cnt += (s[i] == '1');

    if(s[i--] == '0') cnt++;

    for(; i >= n - x; i--)
        cnt += (s[i] == '1');
    cout<<cnt;
    return 0;
}