#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define tiii tuple<int, int, int>
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Router {
public:
    int n;
    queue<ordered_set<vector<int>>::iterator> q;
    ordered_set<vi> s;

    Router(int lim) {
        n = lim;
    }
    
    bool addPacket(int src, int target, int timestamp) {
        vi x = {target, timestamp, src};
        if(s.find(x) != s.end()) return 0;
        if(q.size() == n) forwardPacket();

        s.insert(x);
        q.push(s.find(x));
        return 1;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        auto it = q.front();
        q.pop();
        vi v = *it;
        s.erase(it);
        return {v[2], v[0], v[1]};
    }
    
    int getCount(int target, int st, int en) {
        auto itl = s.upper_bound({target, st, -1});
        auto itr = s.upper_bound({target, en, (int)2e5 + 5});
        
        if(itl == s.end()) return 0;
        int l = s.order_of_key(*itl);
        if(itr == s.end()) return s.size() - l;
        else return s.order_of_key(*itr) - l;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}