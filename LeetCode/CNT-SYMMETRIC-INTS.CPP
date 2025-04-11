#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int l, r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r;
    int cnt = 0, suml, sumr, n;

    for(int i = l; i <= r; i++){
        if(i < 10) continue;
        
        string s = to_string(i);
        n = s.length();
        if(n % 2) continue;

        suml = sumr = 0;

        for(int j = 0; j < n / 2; j++){
            suml += s[j] - '0';
            sumr += s[n - j - 1] - '0';
        }
        cnt += (sumr == suml);
    }
    cout<<cnt;
    return 0;
}