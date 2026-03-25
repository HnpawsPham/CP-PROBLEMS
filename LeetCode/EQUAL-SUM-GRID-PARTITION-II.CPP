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

unordered_set<int> s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

     unordered_set<int> s;

    if(n == 1){
        long total = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++){
            total += a[0][i];
            mp[a[0][i]] = i;
        }

        long sum = 0;
        for(int i = 1; i < m; i++){
            sum += a[0][i];
            if(sum == total - sum) return cout<<1, 0;
            int target = abs(2 * sum - total);
            if(mp.count(target) && (mp[target] == i || mp[target] == 0 || mp[target] == m - 1)) return cout<<1, 0;
        }

        sum = 0;
        for(int i = m - 1; i > 0; i--){
            sum += a[0][i];
            if(sum == total - sum) return cout<<1, 0;
            int target = abs(2 * sum - total);
            if(mp.count(target) && (mp[target] == i || mp[target] == 0 || mp[target] == m - 1)) return cout<<1, 0;
        }
        return 0;
    }

    if(m == 1){
        long total = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            total += a[i][0];
            mp[a[i][0]] = i;
        }

        long sum = 0;
        for(int i = 1; i < n; i++){
            sum += a[i][0];
            if(sum == total - sum) return cout<<1, 0;
            int target = abs(2 * sum - total);
            if(mp.count(target) && (mp[target] == i || mp[target] == 0 || mp[target] == n - 1)) return cout<<1, 0;
        }

        sum = 0;
        for(int i = n - 1; i > 0; i--){
            sum += a[i][0];
            if(sum == total - sum) return cout<<1, 0;
            int target = abs(2 * sum - total);
            if(mp.count(target) && (mp[target] == i || mp[target] == 0 || mp[target] == n - 1)) return cout<<1, 0;
        }
        return 0;
    }

    vector<vll> p(n + 1, vll(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] + a[i - 1][j - 1] - p[i - 1][j - 1];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 1 && j > 0 && j < m - 1)
                continue;
            s.insert(a[i - 1][j]);
        }
        if (p[i][m] == p[n][m] - p[i][m])
            return cout<<1, 0;

        if (2 * p[i][m] > p[n][m] && s.count(2 * p[i][m] - p[n][m]))
            return cout<<1, 0;

        if (i == 1)
            for (int j = 1; j < m - 1; j++)
                s.insert(a[0][j]);
    }
    s.clear();

    for (int i = n; i > 1; i--) {
        for (int j = 0; j < m; j++) {
            if(i == n && j > 0 && j < m - 1)
                continue;
            s.insert(a[i - 1][j]);
        }

        if (2 * p[i][m] < p[n][m] && s.count(p[n][m] - 2 * p[i][m]))
            return cout<<1, 0;

        if (i == n)
            for (int j = 1; j < m - 1; j++)
                s.insert(a[n - 1][j]);
    }
    s.clear();

    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if ((j == 1 && i > 0 && i < n - 1))
                continue;
            s.insert(a[i][j - 1]);
        }
        if (p[n][j] == p[n][m] - p[n][j])
            return cout<<1, 0;
        if (2 * p[n][j] > p[n][m] && s.count(2 * p[n][j] - p[n][m]))
            return cout<<1, 0;
        if (j == 1)
            for (int i = 1; i < n - 1; i++)
                s.insert(a[i][0]);
    }
    s.clear();

    for (int j = m - 1; j >= 1; j--) {
        for (int i = 0; i < n; i++) {
            if(j == m - 1 && i > 0 && i < n - 1)
                continue;
            s.insert(a[i][j]);
        }

        if (2 * p[n][j] < p[n][m] && s.count(p[n][m] - 2 * p[n][j]))
            return cout<<1, 0;

        if (j == m - 1)
            for (int i = 1; i < n - 1; i++)
                s.insert(a[i][m - 1]);
    }

    cout<<0;
    return 0;
}

// 2 2
// 1 3
// 2 4

// 2 2
// 1 4 
// 2 3

// 2 3
// 1 2 4
// 2 3 5

// 2 3
// 4 1 8
// 3 2 6