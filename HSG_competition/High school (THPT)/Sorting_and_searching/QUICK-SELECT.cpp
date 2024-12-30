#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = (int)1e5 + 5;
int a[maxn];
int n, k;

int partition(int l, int r){
    int x = a[l];
    int i = l;

    for(int j = l; j < r; j++){
        if(a[j] <= x){
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int find_smallest(int l, int r, int k){
    if(k <= 0 || k > r - l + 1) return -1;

    int i = partition(l, r);

    if(i - l == k - 1) return a[i];
    if(i - l > k - 1) return find_smallest(l, i - 1, k);
    return find_smallest(i + 1, r, k - i + l - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];



    return 0;
}