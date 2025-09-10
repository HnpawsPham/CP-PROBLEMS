#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, n;
    string s;

    cin>>tc;
    while(tc--){
        cin>>n>>s;
        int sum = s[0] - '0';
        string res = "";

        for(int i = 1; i < n; i++){ 
            int x = int(s[i] - '0');

            if(sum <= 0) {
                res += '+';
                sum += x;
            }
            else {
                res += '-';
                sum -= x;
            }
        }
        cout<<res<<el;
    }

    return 0;
}