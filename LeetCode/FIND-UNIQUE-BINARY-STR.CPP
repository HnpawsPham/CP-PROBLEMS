#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
string res;
unordered_set<string> st;

bool sol(int i, string s){
    if(i == n){
        if(!st.count(s)) {
            res = s;
            return 1;
        }
        return 0;
    }

    if(sol(i + 1, s + '0')) return 1;
    if(sol(i + 1, s + '1')) return 1;

    return 0;
}

string cantor(vector<string>& a){
    string res = "";

    for(int i = 0; i < n; i++)
        res += (a[i][i] == '0' ? '1' : '0');
    
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    cin>>n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    // backtrack sol
    // for(string x : a) st.insert(x);
    // sol(0, "");
    // cout<<res;

    // math sol
    cout<<cantor(a);
    return 0;
}