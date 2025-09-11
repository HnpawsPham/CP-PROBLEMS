#include <bits/stdc++.h>
#define fi first
#define se second
#define el cout <<"\n"
#define SZ(x) ((int)(x).size())
using namespace std;

typedef long long ll;
typedef pair<int,int> vii;

int n;
const int maxn = 2e5 + 5;
int a[maxn], c[maxn];
ll dp[maxn];

struct CHT{
    vector<vii>V;
    int id=0;
    bool check(vii a,vii b,vii c){
        return (b.se-a.se)*(a.fi-c.fi)>=(c.se-a.se)*(a.fi-b.fi);
    }

    ll Cal(vii y,int x){
        return y.fi*x+y.se;
    }

    void add(vii _new){
        while(SZ(V)>1&&check(V[SZ(V)-2],V[SZ(V)-1],_new)) V.pop_back();
        V.push_back(_new);
    }
    
    ll get(int x){
        if(id>SZ(V)-1) id=SZ(V)-1;
        while(id<SZ(V)-1&&id>0&&Cal(V[id],x)>=Cal(V[id+1],x)) id++;
        return Cal(V[id],x);
    }
} hull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>c[i];
    
    for(int i=2;i<=n;i++){
        hull.add({c[i-1],dp[i-1]});
        dp[i]=hull.get(a[i]);
    }
    cout<<dp[n];
    return 0;
}