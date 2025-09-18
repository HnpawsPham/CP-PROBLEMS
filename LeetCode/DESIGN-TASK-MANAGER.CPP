#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define fi first
#define se second

struct comp{
    bool operator()(const piii& a, const piii& b) const{
        if(a.fi.fi != b.fi.fi) return a.fi.fi > b.fi.fi;
        return a.fi.se > b.fi.se;
    }
};

class TaskManager {
public:
    unordered_map<int, pii> mp;
    set<piii, comp> s; 

    TaskManager(vector<vi>& tasks){
        for(auto v : tasks){
            mp[v[1]] = {v[2], v[0]};
            s.insert({{v[2], v[1]}, v[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        s.insert({{priority, taskId}, userId});
    }
    
    void edit(int taskId, int val) {
        auto [priority, userId] = mp[taskId];
        mp[taskId].fi = val;
        s.erase({{priority, taskId}, userId});
        s.insert({{val, taskId}, userId});
    }
    
    void remove(int taskId) {
        auto [priority, userId] = mp[taskId];
        mp.erase(taskId);
        s.erase({{priority, taskId}, userId});
    }
    
    int top() {
        if(mp.empty()) return -1;
        auto [tmp, userId] = *s.begin();
        mp.erase(tmp.se);
        s.erase(*s.begin());
        return userId;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}