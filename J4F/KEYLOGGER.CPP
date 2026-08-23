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

    deque<char> l, r;
    for(const char& x: s){
        if(x == '-'){
            if(l.empty()) continue;
            l.pop_back();
        }
        else if(x == '>'){
            if(r.empty()) continue;
            l.push_back(r.front());
            r.pop_front();
        }
        else if(x == '<'){
            if(l.empty()) continue;
            r.push_front(l.back());
            l.pop_back();
        }
        else l.push_back(x);
    }

    for(const char& x : l) cout<<x;
    for(const char& x : r) cout<<x;
    return 0;
}