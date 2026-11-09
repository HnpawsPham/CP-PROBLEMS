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

    vector<string> a;
    string s;
    int n = 0;
    while(getline(cin, s)){
        a.push_back(s);
        n = max(n, (int)s.size());
    }
    
    for(int i = 0; i < n + 2; i++) cout<<'*';
    cout<<el;
    
    bool priorleft = 1;
    for(const string& x: a){
        int sz = x.size(); 
        cout<<'*';

        int space = (n - sz) / 2;

        int l = space, r = space;
        if((n - sz) % 2){
            l += !priorleft;
            r += priorleft;
            priorleft = !priorleft;
        }

        for(int i = 0; i < l; i++) cout<<' ';
        cout<<x;
        for(int i = 0; i < r; i++) cout<<' ';
        cout<<'*'<<el;
    }

    for(int i = 0; i < n + 2; i++) cout<<'*';
    return 0;
}