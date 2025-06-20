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
    int x = 0, y = 0, res = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if(s[i] == 'N') y++;
        else if(s[i] == 'S') y--;
        else if(s[i] == 'E') x++;
        else x--;
            
        res = max(res, min(abs(x) + abs(y) + k * 2, i + 1));
    }

    cout<<res;
    return 0;
}