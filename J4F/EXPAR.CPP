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

string s, t, tmp;
int n;
bool x = 0, y = 0;

bool get(int& i){
    if(s[i] == 'x') return x;
    if(s[i] == 'y') return y;

    while(i >= 0 && '0' <= s[i] && s[i] <= '9') i--;
    i++;
    int num = 0;
    while(i < n && '0' <= s[i] && s[i] <= '9'){
        num = num * 10 + int(s[i] - '0');
        i++;
    }
    i--;
    return num % 2;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>tmp;
    if(tmp == "Odd") x = 1;
    cin>>tmp;
    if(tmp == "Odd") y = 1;

    n = s.length();
    int i = 0;
    bool res = 0, cur = get(i);

    for(; i < n; i++){
        if(s[i] == '*')
            cur &= get(++i);
    
        else if(s[i] == '+' || s[i] == '-'){
            res ^= cur;
            cur = get(++i);
        }
    }

    if(res ^ cur) cout<<"Odd";
    else cout<<"Even";
    // int cnto = 0, cnte = 0;

    // for(int i = 0; i < n; i++){
    //     if(s[i] == '*'){
    //         bool a = get(s[i - 1]), b = get(s[i + 1]);
    //         if(!a || !b) cnte++;
    //         else cnto++;

    //         i++;
    //         continue;
    //     }

    //     if(i == n - 1 || (i + 1 < n && s[i + 1] != '*'))
    //         t.push_back(s[i]);
    // }

    // n = t.length();
    // for(int i = 0; i < n; i++){
    //     bool x = get(t[i]);
    //     if(!x) cnto++;
    //     else cnte++;
    // }

    // if(cnto % 2 == 0 && cnte % 2 == 0) cout<<"Even";
    // else cout<<"Odd";
    return 0;
}