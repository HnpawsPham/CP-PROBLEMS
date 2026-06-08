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

const int maxn = 405;
int mp[405][405];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, offset = 200;
    cin>>n;
    vi xpos, ypos;

    for(int i = 0; i < n; i++){
        int x, y, c;
        cin>>x>>y>>c;
        x += offset;
        y += offset;
        xpos.push_back(x);
        ypos.push_back(y);
        mp[x][y] = c;
    }

    sort(xpos.begin(), xpos.end());
    xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
    sort(ypos.begin(), ypos.end());
    ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

    ll res = 0;
    int color[4] = {1, 2, 3, 4};
    n = xpos.size();
    m = ypos.size();

    do{
        if(color[0] > color[2]) continue;

        for(int i = 0; i < n - 1; i++)
            for(int x = i + 1; x < n; x++){
                int cntl = 0, cntr = 0;

                for(int j = 0; j < m; j++){
                    int l = mp[xpos[i]][ypos[j]];
                    int r = mp[xpos[x]][ypos[j]];

                    if(l == color[0] && r == color[1]) cntl++;
                    if(l == color[2] && r == color[3]) cntr++;
                }
            res += cntl * cntr;
        }
    } while(next_permutation(color, color + 4));
    cout<<res;
    return 0;
}