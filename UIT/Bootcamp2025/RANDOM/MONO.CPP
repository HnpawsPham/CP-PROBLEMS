#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int cur, res;

void sol(int i, int n, string s, int st, const string& a){
    if(i == n){
        int tmp = stoi(s);
        if(tmp <= cur) res = max(res, tmp);
        return;
    }

    for(int j = st; j <= 9 - n + i + 1; j++)
        sol(i + 1, n, s + to_string(j), j + 1, a);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;
        res = 0;
        cur = stoi(s);

        vi a;
        for(const char& x : s)
            a.push_back(int(x - '0'));
        int n = a.size();

        // th1
        for(int i = 1; i <= 9 - n + 1; i++)
            sol(0, n, "", i, s);

        int tmp = 0;
        for(int i = 9 - n + 2; i <= 9; i++)
            tmp = tmp * 10 + i;

        cout<<max(tmp, res)<<" ";

        // th2
        int gud = -1;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i - 1]) gud = a[i - 1];
            if(gud != -1) a[i] = gud;
        } 
            
        for(int x : a) cout<<x;
        cout<<el;
    }
    return 0;
}

// 5
// 110
// 9
// 2345
// 1232
// 124657698

// 1
// 12539

// 6
// 100
// 19
// 9
// 2
// 3
// 123655

// 10
// 58956734
// 3453
// 542347
// 457834
// 9077
// 127323
// 67897856
// 4564884
// 7989453
// 896097
