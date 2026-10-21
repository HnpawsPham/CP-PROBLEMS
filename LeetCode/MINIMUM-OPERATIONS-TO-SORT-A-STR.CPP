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

    string s;
    cin>>s;
    
    string tmp = s;
    sort(tmp.begin(), tmp.end());
    if(s == tmp) return cout<<0, 0;

    int n = s.length();
    if(n == 2) return cout<<-1, 0;

    if(tmp[0] == s[0]) return cout<<1, 0;
    if(tmp.back() != tmp[n - 2] && tmp.back() == s[0] && tmp[0] != tmp[1] && s.back() == tmp[0]) 
        return cout<<3, 0;
    cout<<2;
    return 0;
}