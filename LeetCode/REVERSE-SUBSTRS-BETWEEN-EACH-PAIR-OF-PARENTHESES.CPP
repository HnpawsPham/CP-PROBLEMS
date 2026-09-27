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

    int n = s.length();
    stack<int> st;
    string tmp = s;

    for(int i = 0; i < n; i++){
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')'){
            reverse(tmp.begin() + st.top(), tmp.begin() + i + 1);
            st.pop();
        }
    }

    string res = "";
    for(const char& x : tmp)
        if('a' <= x && x <= 'z')
            res.push_back(x);
    cout<<res;
    return 0;
}