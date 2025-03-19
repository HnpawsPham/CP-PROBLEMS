#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
string str;

int main(){
    freopen(".\\txt\\BRACKET.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin>>n>>str;

    int dp[n];
    memset(dp, 0, sizeof(dp));
    stack<int> pos;
    int res = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') pos.push(i);
        else{
            if(pos.empty()) continue;
            int j = pos.top(); pos.pop();

            bool ok = (str[j] == '[' && str[i] == ']') ||
                      (str[j] == '(' && str[i] == ')') ||
                      (str[j] == '{' && str[i] == '}');

            if(ok){
                dp[i + 1] = dp[j] + 1;
                res += dp[i + 1];
            }
            else while(!pos.empty()) pos.pop();
        }
    }
    cout<<res;

    return 0;
}