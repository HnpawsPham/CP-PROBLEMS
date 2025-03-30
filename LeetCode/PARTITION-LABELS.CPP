#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int con(char x){
    return x - 'a';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    int last[26];
    for (int i = 0; i < n; i++) last[con(s[i])] = i;

    int i = last[con(s[0])], l = 0, r;
    while (l < n) {
        r = i;
        for (int j = l; j < i; j++)
            r = max(r, last[con(s[j])]);

        for (int j = i; j < r; j++)
            r = max(r, last[con(s[j])]);

        cout<<r - l + 1<<" ";
        l = r + 1;

        if(l >= n) break;
        i = last[con(s[l])];
    }
    return 0;
}