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

    int n = s.length();
    int prev = 0, cur = 0, res = 0;
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i] != s[i - 1]){
            // cout<<prev<<" "<<cur<<el;
            res += min(cur, prev);
            prev = cur;
            cur = 1;
        }
        else cur++;
    }
    cout<<res + min(cur, prev);
    return 0;
}