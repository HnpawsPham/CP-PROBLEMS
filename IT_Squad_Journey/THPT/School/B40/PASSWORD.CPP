#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool low(char x){
    if('a' <= x && x <= 'z') return 1;
    return 0;
}

bool up(char x){
    if('A' <= x && x <= 'Z') return 1;
    return 0;
}

bool num(char x){
    if('0' <= x && x <= '9') return 1;
    return 0; 
}

int main(){
    // freopen("PASSWORD.INP", "r", stdin);
    // freopen("PASSWORD.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    int cntu = 0, cntl = 0, cntd = 0, res = 0;
    int l = 0;

    for(int r = 0; r < n; r++){
        cntu += up(s[r]);
        cntl += low(s[r]);
        cntd += num(s[r]);

        while(l <= r && cntu > 0 && cntl > 0 && cntd > 0){
            if(r - l + 1 >= 6)
                res += n - r;

            cntu -= up(s[l]);
            cntl -= low(s[l]);
            cntd -= num(s[l]);
            l++;
        }
    }
    cout<<res;
    return 0;
}

// abc3456789PQ 

// abc123defghijk