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
    int res = n + 15;
    string ss = s;

    for(string pat : {"RGB", "RBG", "BRG", "BGR", "GBR", "GRB"}){
        int cnt = 0;
        string x = s;
        for(int i = 0; i < n; i++)
            if(x[i] != pat[i % 3]){
                x[i] = pat[i % 3];
                cnt++;
            }
        
        if(cnt < res){
            res = cnt;
            ss = x;
        }
    }
    cout<<res<<el<<ss;
    return 0;
}