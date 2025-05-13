#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define MOD 1000000007

string s;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>t;

    int cnt[26] = {};
    for(char x : s) cnt[x - 'a']++;

    int i = 25;
    while(t--){
        int cur = (i + 1) % 26;
        cnt[cur] = (cnt[cur] + cnt[i]) % MOD;
        i = (i - 1 + 26) % 26
    }

    int sum = 0;
    for(int x : cnt) sum = (sum + x) % MOD;
    cout<<sum;
    return 0;
}