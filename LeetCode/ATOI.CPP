#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);
    int n = s.length();

    long long num = 0;
    int sign = 1;
    bool first = 1, allowspace = 1;

    for(int i = 0; i < n; i++){
        if(num > INT_MAX) break;
        if(s[i] == ' ') {
            if(allowspace) continue;
            else break;
        }

        else if(!isdigit(s[i])){
            if(!first) break;
            if(i < n - 1 && !isdigit(s[i + 1])) break;
            
            if(s[i] == '-') {
                sign = -sign;
                first = 0;
            } 
            else if(s[i] == '+') 
                first = 0;
            else break;
            continue;
        }
        
        num = num * 10 + int(s[i] - '0');
        first = 0;
        allowspace = 0;
    }
    num *= sign;
    int res = max(min(num, 1LL * INT_MAX), 1LL * INT_MIN);
    cout<<res;
    return 0;
}