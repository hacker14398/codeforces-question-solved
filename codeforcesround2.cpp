#include<bits/stdc++.h>
using namespace std;
//typedef vector<vi> vvi;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    int l = 0, r = n;
    int flag = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[mid] == x){
            flag = mid;
            break;
        }
        if(x < a[mid]) r = mid-1;
        else if(x > a[mid]) l = mid+1;
    }
    cout<<flag<<"\n";
}