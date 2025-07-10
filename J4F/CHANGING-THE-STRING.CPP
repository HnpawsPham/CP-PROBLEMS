#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vsi vector<set<int>>

int t, n, q;
string s;
char x, y;

void setchar(int i, int from, int to, vector<vsi>& op){
    auto it = op[from][to].begin();
    op[from][to].erase(it);
    s[i] = 'a';
    return;
}

// 0: a, 1: b, 2: c
void sol(){
    vector<vsi> op(3, vsi (3));
    for(int i = 0; i < q; i++){
        cin>>x>>y;
        op[x - 'a'][y - 'a'].insert(i);
    }

    for(int i = 0; i < n; i++){
        if(s[i] == 'a') continue;
        if(s[i] == 'b'){
            // b -> a
            if(!op[1][0].empty())
                setchar(i, 1, 0, op);
            // b -> c -> a
            else if(!op[1][2].empty()){
                auto it = *op[1][2].begin();
                auto pos = op[2][0].lower_bound(it);

                if(pos != op[2][0].end()){
                    op[2][0].erase(pos);
                    op[1][2].erase(it);
                    s[i] = 'a';
                }
            }
        }
        else{
            // c -> a
            if(!op[2][0].empty())
                setchar(i, 2, 0, op);
  
            else if(!op[2][1].empty()){
                // c -> b
                auto it = *op[2][1].begin();
                op[2][1].erase(it);
                s[i] = 'b';

                // c -> b -> a
                auto pos = op[1][0].lower_bound(it);

                if(pos != op[1][0].end()){
                    op[1][0].erase(pos);
                    s[i] = 'a';
                }
            }
        }
    }
    cout<<s<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>q>>s;
        sol();
    }

    return 0;
}