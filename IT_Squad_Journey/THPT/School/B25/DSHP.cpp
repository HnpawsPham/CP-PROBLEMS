#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;
const int maxn = (int)1e5 + 5;
int a[maxn];
int p[3][maxn];

int main(){
    freopen(".\\txt\\DSHP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    p[0][0] = p[1][0] = p[2][0] = 0;
    for(int i = 1; i <= n;i++){
        cin>>a[i];
        p[a[i]][i] = p[a[i]][i - 1] + 1;
    }

    int m = (n + 1) / 2 - (n % 2 != 0);

    for(int len = m; len > 0; len-=2){
        int l = 1;

        while(l + len < n){
            int mid = l + len - 1;
            int r = mid + len - 1;
           
            int freq_l = -1, freq_r = -1, val_l, val_r;
            for(int x = 0; x < 3; x++){
                if(p[x][mid] - p[x][l - 1] > freq_l){
                    freq_l = p[x][mid] - p[x][l - 1];
                    val_l = x;
                }
                if(p[x][r] - p[x][mid - 1] > freq_r){
                    freq_r = p[x][r] - p[x][mid - 1];
                    val_r = x;
                }
            }

            if(val_l == val_r){
                freq_r = 0;
                for(int x = 0; x < 3; x++){
                    if(x == val_r) continue;
                    if(p[x][r] - p[x][mid - 1] > freq_r){
                        freq_r = p[x][r] - p[x][mid - 1];
                        val_r = x;
                    }
                }
            }

            int sum_l = 0, sum_r = 0;

            for(int x = 0; x < 3; x++)
                if(x != val_l) sum_l += p[x][mid] - p[x][l - 1];

            for(int x = 0; x < 3; x++)
                if(x != val_r) sum_r += p[x][r] - p[x][mid - 1];

            if(sum_l + sum_r <= k) return cout<<len * 2, 0;
            l++;
        }
    }
    return 0;
}