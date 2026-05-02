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
string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    bool diff = 0;
    for(int i = 1; i < n && !diff; i++)
        if(s[i] != s[i - 1]) diff = 1;
    
    if(!diff) return cout<<0, 0;
    else{
        string revs = s;
        reverse(revs.begin(), revs.end());
        if(revs != s) cout<<n;
        else cout<<n - 1;
    }
    return 0;
}