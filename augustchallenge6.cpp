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
//typedef vector<vi> vvi;
typedef vector<vl>   vvl;
ll m = 10e9+7;

ll ncr(ll n, ll k) { 
    ll res = 1; 
    if (k > n - k) k = n - k; 
    for(ll i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    }
    return res; 
} 

ll right(vl &a, ll index, ll range, vvl &dp){
    ll ans = 1;
    for(ll i = index; i < a.size(); i++){
        ll count = 0;
        if(a[i] != 0){
            for(ll j = 0; j <= min(range, a[i]); j++){
                count = ((count%m) + (dp[a[i]][j])%m)%m;
            }
            ans = ((ans%m)*(count%m))%m;
        }
    }
    return ans;
}

ll left(vl &a, ll index, ll range, vvl &dp){
    ll ans = 1;
    //cout<<index<<" "<<range<<"\n";
    //cout<<a[index]<<"\n";
    for(ll i = index; i > 0; i--){
        ll count = 0;
        if(a[i] != 0){
            if(a[i] < range) range = a[i]+1;
            for(ll j = 0; j < range; j++){
                count = ((count%m) + (dp[a[i]][j])%m)%m;
            }
            //cout<<count<<"\n";
            ans = ((ans%m)*(count%m))%m;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        vvl dp(n+1, vl(n+1, 0));
        ll n, x; cin >> n;
        vl a(n+1, 0);
        rep(i, n){
            cin >> x;
            a[x]++;
        }
        vl ans(n+1, 0);
        for(ll i = 1; i <= n; i++){
            for(ll j = 0; j <= a[i]; j++){
                dp[i][j] = ncr(i, j);
            }
        }
        for(ll i = 0; i <= n; i++){
            if(a[i] != 0){
                ll leftans = 1, rightans = 1;
                for(ll j = 1; j <= a[i]; j++){
                    if(i > 1) leftans = left(a, i-1, j, dp);
                    if(i < n) rightans = right(a, i+1, j, dp);
                    ll q = dp[a[i]][j];
                    q = ((q%m)*(leftans%m)*(rightans%m))%m;
                    ans[i] += q;
                }
            }
        }
        rep(i, ans.size()){
            if(i != 0) cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }    
    return 0;
}