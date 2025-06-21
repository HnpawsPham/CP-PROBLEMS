#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 1e5 + 3;
int bit[maxn] = {0};

void update(int i, int del) {
    for (; i <= n; i += i & -i) {
        bit[i] += del;
    }
    return;
}

int sum(int i) {
    int res = 0;

    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int query_range(int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1], pos[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
        update(i, 1);
    }

    int l = 1, r = n;
    for (int step = 1; step <= n; step++) {
        int x, cnt;
        
        if (step % 2 == 1) {
            x = l++;
            int cur = pos[x];
            cnt = query_range(1, cur - 1);
            update(cur, -1);
        } 
        else {
            x = r--;
            int cur = pos[x];
            cnt = query_range(cur + 1, n);
            update(cur, -1);
        }
        cout<<cnt<<el;
    }

    // BRUTE FORCE
    // int l = 1, r = n;
    // for(int i = 1; i <= n; i++){
    //     int target = (i % 2 ? l++ : r--);
    //     int pos = find(a.begin(), a.end(), target) - a.begin();

    //     int cnt = abs(pos - target);
    //     a.erase(a.begin() + pos);
    //     a.insert(a.begin() + target, target);

    //     cout<<cnt<<el;
    // }
    return 0;
}

