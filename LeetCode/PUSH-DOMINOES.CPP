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
    vector<int> a(n, 0);

    for(int i = 0, f = 0; i < n; i++){
        if(s[i] == 'L') f = 0;
        else if(s[i] == 'R') f = n;
        else f = max(f - 1, 0);
        a[i] += f;
    }

    for(int i = n - 1, f = 0; i >= 0; i--){
        if(s[i] == 'L') f = n;
        else if(s[i] == 'R') f = 0;
        else f = max(f - 1, 0);
        a[i] -= f;

        s[i] = a[i] > 0 ? 'R' : a[i] < 0 ? 'L' : '.';
    }
    cout<<s;

    return 0;
}