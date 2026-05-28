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

const int maxn = 8e5 + 5;
int child[maxn][26], best1[maxn], best2[maxn];
int id = 0;

void push(int u, int pos){
    if(best1[u] == -1) best1[u] = pos;
    else if(best2[u] == -1 && best1[u] != pos)
        best2[u] = pos;
    return;
}

void add(const string& s, int pos, const vector<string>& a){
    int u = 0;
    push(0, pos);
    int n = s.size();

    for(int i = n - 1; i >= 0; i--){
        int k = s[i] - 'a';
        if(!child[u][k]){
            child[u][k] = ++id;
            best1[id] = best2[id] = -1;
        }
        u = child[u][k];
        push(u, pos);
    }
    return;
}

int query(const string& s, int ban){
    int u = 0;
    int n = s.size();
    int res = (best1[0] == ban ? best2[0] : best1[0]);

    for(int i = n - 1; i >= 0; i--){
        int k = s[i] - 'a';
        if(!child[u][k]) break;
        u = child[u][k];
        
        int pick = (best1[u] == ban ? best2[u] : best1[u]);
        if(pick != -1) res = pick;
    }
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

    string tmp;
    bool change = 0;
    vector<string> a, b;
    while(getline(cin, tmp)){
        if(!tmp.empty()){
            if(change) b.push_back(tmp);
            else a.push_back(tmp);
        }
        else change = 1;
    }

    int n = a.size();
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++)
        add(a[i], i, a);

    for(const string& s : b){
        int pos = lower_bound(a.begin(), a.end(), s) - a.begin();
        cout<<a[query(s, pos)]<<el;
    }
    return 0;
}