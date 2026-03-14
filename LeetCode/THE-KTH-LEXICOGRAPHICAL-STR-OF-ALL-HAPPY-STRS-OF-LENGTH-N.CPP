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

int n, k;
vector<string> res;

void sol(int i, string s){
    if(i == n){
        res.push_back(s);
        return;
    }

    for(char x : {'a', 'b', 'c'}){
        if(!s.empty() && s.back() == x) continue;
        sol(i + 1, s + x);
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

    cin>>n>>k;
    sol(0, "");

    if(k > res.size()) return cout<<"", 0;
    cout<<res[k - 1];
    return 0;
}