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

    int cntat = 0;
    for(const char& x : s)
        if(x == '@') cntat++;
    if(cntat == 0) return cout<<"No solution", 0;

    bool head = 0, at = 0;
    string res = "";
    for(int i = 0; i < n; i++){
        res.push_back(s[i]);

        if(s[i] == '@'){
            if(!head || at) return cout<<"No solution", 0;
            at = 1;
            cntat--;
        }
        else{
            head = 1;
            if(at){
                if(cntat) res.push_back(',');
                head = at = 0;
            }
        }
    }
    if(res.back() == '@') 
        return cout<<"No solution", 0;
    
    cout<<res;
    return 0;
}