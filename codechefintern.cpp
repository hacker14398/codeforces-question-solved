#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long int
#define rep(i,n) for(ll i = 0; i < n; i++)
#define repp(i, x) for(ll i = 1; i < x; i++)
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<char> vc;
typedef vector<ll>   vl;
typedef vector<pii>  vpii;
typedef vector<pl>   vpl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        vl a(n);
        rep(i, n) cin >> a[i];
        vector<queue<ll>> ans(32, queue<ll>());
        for(ll i = 0; i < 32; i++){
            for(ll j = 0; j < n; j++){
                if(a[j]&(1<<i)) ans[i].push(j);
            }
        }
    for(ll i = 0; i < n; i++){
        ll k = 31;
        while((a[i] > 0 and k >= 0) and x > 0 ){
            if(n < 3){
                if(a[i]&(1<<k) and i != (n-1)){
                    if(!ans.empty() and ans[k].size() > 1){
                        a[ans[k].front()]^=(1<<k);
                        ans[k].pop();
                        a[ans[k].front()]^=(1<<k);
                        ans[k].pop();
                        x--;
                    }
                    else if(ans[k].size()==1){
                        a[ans[k].front()]^=(1<<k);
                        ans[k].pop();
                        a[n-1]^=(1<<k);
                        x--;
                    }
                }
                else if(i == (n-1)){
                    if(x%2 != 0){
                        x = 0;
                        a[n-1]^=1;
                        a[n-2]^=1;
                    }
                }
                    
            }
            else if(a[i]&(1<<k) and i != (n-1)){
                if(!ans.empty() and ans[k].size() > 1){
                    a[ans[k].front()]^=(1<<k);
                    ans[k].pop();
                    a[ans[k].front()]^=(1<<k);
                    ans[k].pop();
                    x--;
                }
                else if(ans[k].size()==1){
                    a[ans[k].front()]^=(1<<k);
                    ans[k].pop();
                    a[n-1]^=(1<<k);
                    x--;
                }
            }
            else if(i == (n-1)){
                x = 0;
            }
            k--;
        }
    }
    if(a[n-1] == 0 and x > 0){
        if(x%2 != 0){
            a[n-1]^=1;
            a[n-2]^=1;
        }
    }
    for(auto j : a) cout<<j<<" ";
        cout<<"\n";
    }
}