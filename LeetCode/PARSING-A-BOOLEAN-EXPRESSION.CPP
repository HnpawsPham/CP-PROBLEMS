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

bool sol(int& i, const string& s){
    if(i == n) return 0;

    if(s[i] == 't'){
        i++;
        return 1;
    }
    if(s[i] == 'f'){
        i++;
        return 0;
    }
    
    char op = s[i++];
    i++;
    bool t = 0, f = 0;
    while(s[i] != ')'){
        if(s[i] == ','){
            i++;
            continue;
        }

        if(sol(i, s)) t = 1;
        else f = 1;
    }
    i++;

    if(op == '|') return t;
    if(op == '&') return !f;
    if(op == '!') return !t;
    return 0;
}

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

    n = s.length();
    int i = 0;
    cout<<sol(i, s);
    return 0;
}