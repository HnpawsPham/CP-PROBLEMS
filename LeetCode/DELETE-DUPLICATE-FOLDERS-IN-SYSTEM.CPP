#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vs vector<string>

struct Node{
    string name;
    unordered_map<string, Node*> child;
    bool del = 0;

    Node() {}
    Node(string name1) : name(name1) {}
};

unordered_map<string, int> mp;
unordered_map<int, vector<Node*>> check;
int cnt = 0;

// build path
int dfs(Node* u){
    if(u->child.empty()) return 0;

    vector<pair<string, int>> sub;
    for(auto& [name, v] : u->child)
        sub.push_back({name, dfs(v)});
    
    sort(sub.begin(), sub.end());

    string s;
    for(auto& [name, x] : sub)
        s += '(' + name + to_string(x) + ')';

    if(!mp.count(s)) mp[s] = ++cnt;

    int id = mp[s];
    check[id].push_back(u);
    return id;
}

vector<vs> res;
vs path;

// build result 
void get(Node* u){
    for(auto& [name, v] : u->child){
        if(v->del) continue;

        path.push_back(name);
        res.push_back(path);
        get(v);
        path.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vs> a(n);
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        string x;
        for(int j = 0; j < m; j++){
            cin>>x;
            a[i].push_back(x);
        }
    }

    Node* root = new Node();
    for(const vs& v : a){
        Node* cur = root;
        for(const string& s : v){
            if(!cur->child.count(s))
                cur->child[s] = new Node(s);

            cur = cur->child[s];
        }
    }
    dfs(root);

    // remove duplicate
    for(auto& [_, v] : check){
        if(v.size() >= 2) 
            for(auto x : v) x->del = 1;
    }
    get(root);

    for(auto v : res){
        for(auto x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}

// 6
// 1 a
// 1 c
// 1 d
// 2 a b
// 2 c b
// 2 d a