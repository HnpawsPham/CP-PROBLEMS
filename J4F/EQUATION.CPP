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

int tc = 1;

const ll MOD = 123456789;

bool isOp(const char& x){
    return (x == '+' || x == '-' || x == '*');
}

ll convert(const string& s){
    ll res = 0;
    int sign = 1;
    for(const char& x : s){
        if(x == '-') sign = -1;
        else res = (res * 10 + (x - '0')) % MOD;
    }
    return (res * sign % MOD + MOD) % MOD;
}

ll sol(){
    string s;
    cin>>s;
    int n = s.length();

    vll a;
    vector<char> op;

    string t;
    for(int i = 0; i < n; i++){
        if(i == 0 && s[i] == '-')
            t.push_back(s[i]);

        if('0' <= s[i] && s[i] <= '9')
            t.push_back(s[i]);

        if(i > 0 && isOp(s[i])){
            if(!t.empty()){
                a.push_back(convert(t));
                t = "";
            }
            op.push_back(s[i]);
        }
    }

    if(!t.empty())
        a.push_back(convert(t));

    // mul first
    int sz = op.size();
    vll st;
    st.push_back(a[0]);

    for(int i = 0; i < sz; i++){
        if(op[i] == '*'){
            ll cur = st.back();
            st.pop_back();
            st.push_back(cur * a[i + 1] % MOD);
        }
        else st.push_back(a[i + 1]);
    }

    ll res = st[0];
    int j = 1;
    for(int i = 0; i < sz; i++){
        if(op[i] == '+')
            res = (res + st[j++]) % MOD;
        else if(op[i] == '-')
            res = (res - st[j++] + MOD) % MOD;
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

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}