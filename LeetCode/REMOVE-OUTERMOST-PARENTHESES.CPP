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
    
    string res = "";
    int d = 0;
    for(const char& x : s){
        if(x == '('){
            if(d > 0) res.push_back('(');
            d++;
        }
        else{
            d--;
            if(d > 0) res.push_back(')');
        }
    }
    cout<<res;
    return 0;
}