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
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    ll x = 1;
    while(t--){
        ll n, k, w; cin >> n >> k >> w;
        vl v(n), h(n); 
        rep(i, k) cin >> v[i];
        ll v1, v2, v3, v4; cin >> v1 >> v2 >> v3 >> v4;
        rep(i, k) cin >> h[i];
        ll h1, h2, h3, h4; cin >> h1 >> h2 >> h3 >> h4;
        while(k < n){
            ll val = ((v1*v[k-2]+v2*v[k-1]+v3)%v4)+1;
            ll height = ((h1*h[k-2]+h2*h[k-1]+h3)%h4)+1;
            v.emplace_back(val);
            h.emplace_back(height);
        }
        
        if(ans == 1) cout<<"Case #"<<x<<":"<<" "<<"Y"<<"\n";
        else cout<<"Case #"<<x<<":"<<" "<<"N"<<"\n";
        x++;
    }
    return 0;
}