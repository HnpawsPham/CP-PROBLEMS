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

int n, len, k;
const ll oo = 1e12;

class MedianWindow{
    private:
        priority_queue<int> minpq;
        priority_queue<int, vi, greater<int>> maxpq;
        unordered_map<int, int> del;
        int szmin, szmax, summin, summax;
        int sz;

        void delmin(){
            while(!minpq.empty() && del[minpq.top()]){
                del[minpq.top()]--;
                minpq.pop();
            }
            return;
        }

        void delmax(){
            while(!maxpq.empty() && del[maxpq.top()]){
                del[maxpq.top()]--;
                maxpq.pop();
            }
            return;
        }

        void balance(){
            if(szmin > szmax + 1){
                int x = minpq.top(); 
                minpq.pop();
                maxpq.push(x);

                summin -= x;
                szmin--;
                summax += x;
                szmax++;
                delmin();
            }
            else if(szmin < szmax){
                int x = maxpq.top();
                maxpq.pop();
                minpq.push(x);

                szmin++;
                summin += x;
                szmax--;
                summax -= x;
                delmax();
            }
        }
    public:
        MedianWindow(int _sz){
            sz = _sz;
            szmin = szmax = summin = summax = 0;
        }

        void add(int x){
            if(minpq.empty() || x <= minpq.top()){
                minpq.push(x);
                summin += x;
                szmin++;
            }
            else{
                maxpq.push(x);
                summax += x;
                szmax++;
            }
            balance();
        }

        void remove(int x){
            del[x]++;
            if(x <= minpq.top()){
                summin -= x;
                szmin--;
                if(x == minpq.top()) delmin();
            }
            else{
                summax -= x;
                szmax--;
                if(x == maxpq.top()) delmax();
            }
            balance();
        }

        ll min_change(){
            int med = minpq.top();
            return 1LL * med * szmin - summin + summax - 1LL * med * szmax;
        }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>len>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    MedianWindow win(len);
    int m = n - len + 1;
    vi cost(m);

    for(int i = 0; i < n; i++){
        win.add(a[i]);

        if(i >= len - 1) {
            cost[i - len + 1] = win.min_change();
            win.remove(a[i - len + 1]);
        }
    }
    // for(int x : cost) cout<<x<<" ";

    vector<vll> dp(m, vll(k + 1, oo));
    for (int i = 0; i < m; i++) dp[i][1] = cost[i];

    for(int j = 2; j <= k; j++){
        vll best(m, oo);
        best[0] = dp[0][j - 1];

        for(int i = 1; i < m; i++)
            best[i] = min(best[i - 1], dp[i][j - 1]);

        for(int i = 0; i < m; i++)
            if(i >= len && best[i - len] < oo)
                dp[i][j] = best[i - len] + cost[i];
    }

    ll res = oo;
    for(int i = 0; i < m; i++) res = min(res, dp[i][k]);
    cout<<res;
    return 0;
}

// 9 3 2
// 5 -2 1 3 7 3 6 4 -1