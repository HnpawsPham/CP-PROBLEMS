#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s1>>s2;
    int n = s2.length(), m = s1.length();
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for(const char& x : s1) cnt1[x - 'a']++;

    for(int i = 0; i < n; i++){
        cnt2[s2[i] - 'a']++;

        if(i >= m) cnt2[s2[i - m] - 'a']--;

        if(cnt1 == cnt2) return cout<<1, 0;
    }
    cout<<0;
    return 0;
}