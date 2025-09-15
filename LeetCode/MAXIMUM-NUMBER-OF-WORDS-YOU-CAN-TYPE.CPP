#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    getline(cin, s);
    cin>>t;

    bool ok = 1;
    int cnt = 0;
    unordered_set<char> st(t.begin(), t.end());
    for(char x : s){
        if(st.count(x)) ok = 0;
        if(x == ' ') {
            cnt += ok;
            ok = 1;
        }
    }
    cout<<cnt + ok;
    return 0;
}