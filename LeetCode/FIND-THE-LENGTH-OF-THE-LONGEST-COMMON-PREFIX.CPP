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

    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    unordered_set<string> sa, sb;
    for(int x : a){
        string s = to_string(x), t = "";
        for(const char& c : s){
            t.push_back(c);
            sa.insert(t);
        }
    }
    for(int x : b){
        string s = to_string(x), t = "";
        for(const char& c : s){
            t.push_back(c);
            sb.insert(t);
        }
    }

    int maxx = 0;
    for(const int& x : a){
        string s = to_string(x), t = "";
        for(const char& c : s){
            t.push_back(c);
            if(sb.count(t))
                maxx = max(maxx, (int)t.size());
        }
    }

    for(const int& x : b){
        string s = to_string(x), t = "";
        for(const char& c : s){
            t.push_back(c);
            if(sa.count(t))
                maxx = max(maxx, (int)t.size());
        }
    }
    cout<<maxx;
    return 0;
}

// 3 1
// 1 10 100
// 1000