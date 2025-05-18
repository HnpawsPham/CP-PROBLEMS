#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 3005;
int a[maxn][maxn];

void reset(int &sum, int &t){
    sum = min(sum, t);
    t = 0;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    string s;
    for(int i = 0; i < n; i++){
        cin>>s;
        for(int j = 0; j < m; j++) 
            a[i][j] = int(s[j] - '0');
    }
    
    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            int sum = n + m, t = 0;

            for(int ii = 0; ii < i; ii++){
                if(a[ii][j]) t++;
                else break;
            }

            reset(sum, t);
            for(int ii = i + 1; ii < n; ii++){
                if(a[ii][j]) t++;
                else break;
            }

            reset(sum, t);
            for(int jj = 0; jj < j; jj++){
                if(a[i][jj]) t++;
                else break;
            }
            
            reset(sum, t);
            for(int jj = j + 1; jj < m; jj++) {
                if(a[i][jj]) t++;
                else break;
            }
            
            res += sum;
        }

    cout<<res;
    return 0;
}