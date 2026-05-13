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

int tc = 1;

int sol(){
    int n;
    string s;
    cin>>n>>s;
    bool check[26] = {0};
    int cntl[n + 1] = {0}, cntr[n + 2] = {0};
    for(int i = 1; i <= n; i++){
        cntl[i] = cntl[i - 1];
        if(!check[s[i - 1] - 'a']){
            cntl[i]++;
            check[s[i - 1] - 'a'] = 1;
        }
    }

    memset(check, 0, sizeof check);
    for(int i = n; i > 0; i--){
        cntr[i] = cntr[i + 1];
        if(!check[s[i - 1] - 'a']){
            cntr[i]++;
            check[s[i - 1] - 'a'] = 1;
        }
    }

    int res = 0;
    for(int i = 1; i < n; i++)
        res = max(res, cntl[i] + cntr[i + 1]);
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}