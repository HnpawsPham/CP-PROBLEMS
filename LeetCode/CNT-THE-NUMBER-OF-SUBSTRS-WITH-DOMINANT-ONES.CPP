#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    int prev[n + 1] = {-1};
    for(int i = 0; i < n; i++){
        if(i == 0 || (s[i - 1] == '0'))
            prev[i + 1] = i;
        else prev[i + 1] = prev[i];
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        int cnt0 = (s[i - 1] == '0');

        while(j > 0 && cnt0 * cnt0 <= n){
            int cnt1 = (i - prev[j]) - cnt0;
            if(cnt1 >= cnt0 * cnt0)
                res += min(cnt1 - cnt0 * cnt0 + 1, j - prev[j]);

            j = prev[j];
            cnt0++;
        }
    }
    cout<<res;
    return 0;
}