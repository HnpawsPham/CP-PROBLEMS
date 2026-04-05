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

    string s, t;
    cin>>s>>t;

    int n = s.length(), m = t.length();
    int sz = n + m - 1;
    string res(sz, 'a');
    vector<bool> fixed(sz, 0);

    for(int i = 0; i < n; i++)
        if(s[i] == 'T')
            for(int j = i; j < i + m; j++)
                if(fixed[j] && res[j] != t[j - i]) 
                    return cout<<"", 0;
                else{
                    fixed[j] = 1;
                    res[j] = t[j - i];
                }

    for(int i = 0; i < n; i++)
        if(s[i] == 'F'){
            bool ok = 0;
            int cur = -1;
            for(int j = i + m - 1; j >= i; j--){
                if(t[j - i] != res[j]) ok = 1;
                if(cur == -1 && !fixed[j]) cur = j;   
            }

            if(ok) continue;
            if(cur != -1) res[cur] = 'b';
            else return cout<<"", 0;
        } 
    cout<<res;
    return 0;
}

// TFTF
// ab

// TFTF
// abc