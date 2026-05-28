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

#define vi vector<int>

class Trie {
private:
    int const maxn = 2005;
    int id;
    vector<vi> child;
    vector<bool> check;

public:
    Trie(){
        id = 0;
        child.assign(maxn * 50, vi(26, 0));
        check.assign(maxn * 50, 0);
    }
    
    void insert(string s) {
        int u = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            int k = s[i] - 'a';
            if(!child[u][k]) 
                child[u][k] = ++id;

            u = child[u][k];
        }
        check[u] = 1;
        return;
    }
    
    bool search(string s) {
        int u = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            int k = s[i] - 'a';
            if(!child[u][k]) return 0;
            u = child[u][k];
        }
        return check[u];
    }
    
    bool startsWith(string s) {
        int u = 0;
        int n = s.length();

        for(int i = 0; i < n; i++){
            int k = s[i] - 'a';
            if(!child[u][k]) return 0;
            u = child[u][k];
        }
        return 1;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}