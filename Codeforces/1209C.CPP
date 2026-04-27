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
//#define taskname ""

int tc = 1;
int n;
string s;
// const int maxn = 2e5 + 5;
// int p[maxn][10] = {0};

// string check(bool addcon){
//     string res = s;
//     int max2 = 0;
    
//     for(int i = 1; i <= n; i++){
//         int x = s[i - 1] - '0';
//         bool ok = 1;
//         for(int j = x - 1; j >= 0 && ok; j--)
//             if(p[n][j] - p[i][j] > 0 || (x >= max2) * addcon){
//                 res[i - 1] = '2';
//                 ok = 0;
//                 max2 = max(max2, x);
//             }
//         if(ok) res[i - 1] = '1';
//     }

//     int cur = 0;
//     for(int i = 0; i < n; i++)
//         if(res[i] - '0' == 1){
//             int x = s[i] - '0';
//             if(x < cur) return "-";
//             cur = x;
//         }

//     for(int i = 0; i < n; i++)
//         if(res[i] - '0' == 2){
//             int x = s[i] - '0';
//             if(x < cur) return "-";
//             cur = x;
//         }
//     return res;
// }

bool check(const string& res){
    int cur = 0;
    for(int i = 0; i < n; i++)
        if(res[i] - '0' == 1){
            int x = s[i] - '0';
            if(x < cur) return 0;
            cur = x;
        }

    for(int i = 0; i < n; i++)
        if(res[i] - '0' == 2){
            int x = s[i] - '0';
            if(x < cur) return 0;
            cur = x;
        }
    return 1;
}

string sol(){
    cin>>n>>s;

    // for(int i = 1; i <= n; i++)
    //     for(int j = 0; j < 10; j++)
    //         p[i][j] = p[i - 1][j] + (s[i - 1] - '0' == j);

    // string tmp = check(0);
    // if(tmp != "-") return tmp;
    // return check(1);

    for(int j = 0; j < 10; j++){
        string res = s;
        int max2 = 0;

        for(int i = 0; i < n; i++){
            int x = s[i] - '0';
            if(x > j){
                res[i] = '2';
                max2 = max(max2, x);
            }
            else if(x < j) res[i] = '1';
            else{
                if(x < max2) res[i] = '1';
                else{
                    res[i] = '2';
                    max2 = x;
                }
            }
        }
        if(check(res)) return res;
    }
    return "-";
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 3 4
// 6148
// 5
// 46368
// 4
// 6967