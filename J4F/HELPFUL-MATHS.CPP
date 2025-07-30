#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int cnt[4] = {0};
    for(char x : s){
        if(x == '+') continue;
        cnt[x - '0']++;
    }
    
    string res = "";
    for(int i = 1; i < 4; i++)
        while(cnt[i] > 0) {
            res = res + char(i + '0') + '+';
            cnt[i]--;
        }
    res.pop_back();
    cout<<res;
    return 0;
}