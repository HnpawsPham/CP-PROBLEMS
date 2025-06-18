#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    
    int cnt[26] = {0};
    for(int i = 0; i < n; i++) 
        cnt[s[i] - 'A']++;

    bool middle = 0;

    string res(n, '0');
    int j = n / 2 - 1;

    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0) continue;
        if((n % 2 == 0 && cnt[i] % 2) || (middle && cnt[i] % 2)) return cout<<"NO SOLUTION", 0;

        if(cnt[i] % 2){
            middle = 1;
            res[n / 2] = i + 'A';
            cnt[i]--;
        }

        while(cnt[i]){
            res[j] = res[n - j - 1] = i + 'A';
            cnt[i]-=2;
            j--;
        }
    }
    cout<<res;
    return 0;
}