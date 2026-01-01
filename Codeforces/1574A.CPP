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

void sol(){
    int n;
    cin>>n;
    string res;
    for(int i = 1; i <= n; i++){
        res = "";
        for(int j = 1; j <= i; j++)
            res.push_back('(');
        
        for(int j = 1; j <= i; j++)
            res.push_back(')');

        for(int j = i + 1; j <= n; j++){
            res.push_back('(');
            res.push_back(')');
        }
        cout<<res<<el;
    }
    return;
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
    while(tc--)
        sol();
    return 0;
}