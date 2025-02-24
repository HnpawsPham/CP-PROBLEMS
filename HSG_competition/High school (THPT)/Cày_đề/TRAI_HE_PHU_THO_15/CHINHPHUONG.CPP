#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, sz;
vector<int> cp, res;

void build_cp(){
    for(int i = 1; i < 320; i++) 
        cp.push_back(i * i);
    sz = cp.size();
    return;
}
bool sol(int sum, int cnt, int st){
    if(cnt == 4){
        if(sum == n){
            for(int x : res) cout<<x<<" ";
            return 1;
        }
        return 0;
    }

    for(int i = st; i < sz; i++){
        int num = sqrt(cp[i]);
        res.push_back(num);
        if(sol(sum + cp[i], cnt + 1, i)) return 1;
        res.pop_back();
    }
    return 0;
}

int main(){
    freopen("CPHUONG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    build_cp();

    if(!sol(0, 0, 0)) cout<<-1;
    return 0;
}