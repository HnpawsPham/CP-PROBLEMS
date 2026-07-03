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

    ll res = 0;
    for(int i = 0, j; i < n;){
        int len = 1;
        for(j = i + 1; s[i] == s[j] && j < n; j++)
            len++;
        res += 1LL * len * 1LL * (len - 1) / 2;
        i = j;
    }
    cout<<res;
    return 0;
}