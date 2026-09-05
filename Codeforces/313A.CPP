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
    if(s[0] != '-') cout<<s;
    else{
        int n = s.length();
        if(n < 2) cout<<0;
        else{
            char last = s.back();
            s.pop_back();
            if(s.back() > last){
                s.pop_back();
                if(s + last == "-0")
                    cout<<0;
                else cout<<s + last;
            }
            else cout<<s;
        }
    }
    return 0;
}