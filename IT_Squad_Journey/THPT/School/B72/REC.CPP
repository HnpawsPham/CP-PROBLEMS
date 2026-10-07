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
#define taskname "REC"

int n, m, q;
const int maxn = 1005;
int a[maxn][maxn];
namespace sub1{
    void sol(){
        int max1 = 0, max2 = 0, len1 = 0, len2 = 0;
        for(int i = 1; i <= m; i++){
            if(a[1][i] == 1){
                len1++; 
                len2++;
            }
            else if(a[1][i] == 0){
                len1++;
                max2 = max(max2, len2);
                len2 = 0;
            }
            else{
                max1 = max(max1, len1);
                len1 = 0;
                len2++;
            }
        }

        max1 = max(max1, len1);
        max2 = max(max2, len2);
        max1 = max(max1, max2);
  
        while(q--){
            int l, r;
            cin>>l>>r;
            cout<<max1<<el;
        }
    }
}

namespace sub2{
    int res[maxn][maxn], maxx[maxn][maxn], 
    l[maxn], r[maxn];
    stack<int> st;

    int calc(const vi& h){
        for(int i = 1; i <= m; i++){
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            l[i] = (st.empty() ? 1 : st.top() + 1);
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = m; i > 0; i--){
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            r[i] = (st.empty() ? m : st.top() - 1);
            st.push(i);
        }
        while(!st.empty()) st.pop();

        int res = 0;
        for(int i = 1; i <= m; i++)
            res = max(res, h[i] * (r[i] - l[i] + 1));
        return res;
    }

    void precomp(){
        memset(maxx, 0, sizeof maxx);
        memset(res, 0, sizeof res);

        for(int i = 1; i <= n; i++){
            vi h01(m + 1, 0), h12(m + 1, 0);

            for(int j = i; j <= n; j++){
                for(int x = 1; x <= m; x++){
                    if(a[j][x] == 0 || a[j][x] == 1)
                        h01[x]++;
                    else h01[x] = 0;

                    if(a[j][x] == 1 || a[j][x] == 2)
                        h12[x]++;
                    else h12[x] = 0;
                }

                int s1 = calc(h01);
                int s2 = calc(h12);
                maxx[i][j] = max(s1, s2);
            }
        }

        for(int len = 1; len <= n; len++)
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                res[i][j] = maxx[i][j];

                if(i < j)
                    res[i][j] = max(res[i][j], max(res[i + 1][j], res[i][j - 1]));
            }
    }

    void sol(){
        precomp();
        while(q--){
            int l, r;
            cin>>l>>r;
            cout<<res[l][r]<<el;
        }
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    memset(a, 0, sizeof a);
    for(int i =1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin>>a[i][j];
    cin>>q;

    if(n == 1) sub1::sol();
    else sub2::sol();
    return 0;
}

// 1 15
// 1 2 0 1 1 2 0 0 1 0 0 2 1 0 0
// 3
// 2 8
// 9 15
// 1 15