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
    string s1, s2;
    cin>>n>>m>>s1>>s2;
    
    set<pii> cnt;

    int x = 0, y = 0;
    cnt.insert({0, 0});
    for(const char& c : s1){
        if(c == 'D') y++;
        else x++;
        cnt.insert({x, y});
    }
    
    x = m - 1; y = n - 1;
    int res = 0;
    if(cnt.find({x, y}) != cnt.end()) res++;

    for(const char& c : s2){
        if(c == 'U') y--;
        else x--;
        if(cnt.find({x, y}) != cnt.end()) res++;
    }
    cout<<res;
    return 0;
}

