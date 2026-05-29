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

int n, m;
const int maxn = 5e5 + 5;
int child[maxn][2] = {0}, en[maxn] = {0}, con[maxn] = {0};
int id = 0;

void add(const string& s){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - '0';
        if(!child[u][k]) 
            child[u][k] = ++id;

        u = child[u][k];
        con[u]++;
    }
    en[u]++;
    return;
}


int query(const string& s){
    int u = 0, res = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - '0';
        if(!child[u][k]) 
            return res;

        u = child[u][k];
        res += en[u];
    }
    return res + con[u] - en[u]; 
}

void inp(int n, vector<string>& a){
    for(int i = 0; i < n; i++){
        int sz;
        char x;
        cin>>sz;
        string s = "";
        while(sz--){
            cin>>x;
            s.push_back(x);
        }
        a.push_back(s);
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

    cin>>n>>m;
    vector<string> a, b;
    inp(n, a); inp(m, b);

    for(const string& s : a)add(s);
    for(const string& s : b) 
        cout<<query(s)<<el;
    return 0;
}