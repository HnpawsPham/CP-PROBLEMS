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

int check(char a, char b){
    if(a == 'R' && b == 'L') return 2;
    if((a == 'S' && b == 'L') || (a == 'R' && b == 'S')) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    
    stack<char> st;
    int res = 0, d;
    for(char& x : s){
        while(!st.empty() && check(st.top(), x)){
            res += check(st.top(), x);
            x = 'S';
            st.pop();
        }
        st.push(x);
    }
    // cout<<s<<el;
    cout<<res;
    return 0;
}

// RLRSLL
// LLRR
// RRRL
// RSLRRLRSSLLRLLSRRLRRSLRSLRSSLRSLRLLRSLLRSSLRRLLLRRSLSLRRLLRSRLLRSRLSRLLRSLSRRLRRLSSRRLRL