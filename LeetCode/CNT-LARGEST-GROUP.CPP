#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    unordered_map<int, int> mp;
    int len = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0, x = i;
        while(x > 0){
            cnt += x % 10;
            x /= 10;
        }
        mp[cnt]++;
        len = max(len, mp[cnt]);
    }

    int cnt = 0;
    for(pii x : mp)
        if(x.se == len) cnt++;
    cout<<cnt;
    return 0;
}