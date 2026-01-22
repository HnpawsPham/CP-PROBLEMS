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
    string res = s;

    if(s.find("http") == 0)
        res.insert(4, "://");
    else res.insert(3, "://");

    int pos = res.find("ru", res.find("://") + 4);
    res.insert(pos, 1, '.');
    
    if(pos + 3 < res.size())
        res.insert(pos + 3, 1, '/');
    cout<<res;
    return 0;
}