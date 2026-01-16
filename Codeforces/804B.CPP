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

const int MOD = 1e9 +7;

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

    int cntb = 0, res = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'b') 
            cntb = (cntb + 1) % MOD;
        else{
            res = (res + cntb) % MOD;
            cntb = cntb * 2 % MOD;   
        }
    }
    cout<<res;
    return 0;
}