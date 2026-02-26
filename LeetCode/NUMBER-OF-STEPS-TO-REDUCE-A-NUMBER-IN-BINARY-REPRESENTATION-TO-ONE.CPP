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
    
    int cnt = 0;
    while(!s.empty() && s != "1"){
        if(s.back() == '1'){
            int n = s.length();
            for(int i = n - 1; i >= 0; i--){
                if(s[i] == '0'){
                    s[i] = '1';
                    break;
                }
                s[i] = '0';
            }
        }
        else s.pop_back();
        cnt++;
    }
    cout<<cnt;
    return 0;
}