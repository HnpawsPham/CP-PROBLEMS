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

class Robot {
public:
    int n, m, x, y, dir;
    int dx[4] = {0, -1, 0, 1},
        dy[4] = {-1, 0, 1, 0};
    string direction[4] = {"South", "West", "North", "East"};

    Robot(int w, int h) {
        n = h; m = w;
        x = y = 0;
        dir = 3; //0123 SWNE rotate -1
    }
    
    void step(int d) {
        d %= 4 * (m + n - 2);

        while(d){
            int x1 = x + d * dx[dir];
            int y1 = y + d * dy[dir];
            int delta = 0;

            if(dx[dir]){
                if(dx[dir] > 0){
                    delta = min(m - x - 1, d);
                    x += delta;
                }
                else{
                    delta = min(x, d);
                    x -= delta;
                }
            }
            if(dy[dir]){
                if(dy[dir] > 0){
                    delta = min(n - y - 1, d);
                    y += delta;
                }
                else{
                    delta= min(y, d);
                    y -= delta;
                }
            }
            d -= delta;

            if(d > 0)
                dir = (dir - 1 + 4) % 4;
        }
        return;
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return direction[dir];
    }
};

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
    Robot a(n, m);
    a.step(2);
    cout<<a.getDir();
    return 0;
}