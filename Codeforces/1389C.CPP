#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'

int sol(){
    string s;
    cin>>s;
    int n = s.length();

    int res = n;
    for(int a = 0; a <= 9; a++)
        for(int b = 0; b <= 9; b++){
            int j = 0;
            for(int i = 0; i < n; i++)
                if(s[i] - '0' == (j % 2 ? b : a)) j++;

            if(a == b) res = min(res, n - j);
            else res = min(res, n - j / 2 * 2);
        }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}