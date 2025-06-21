#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
int k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>k;
    int cnt[26] = {0};
    int n = s.length();

    for(const char& x : s)
        cnt[x - 'a']++;

    int res = n;

    for(const int& i : cnt){
        if(i == 0) continue;
        int tmp = 0;

        for(const int& j : cnt){
            if(j == 0) continue;

            if(j < i) tmp += j;
            
            else if(j > i + k)  
                tmp += (j - i - k);
        }
        res = min(res, tmp);
    }

    cout<<res;
    return 0;
}