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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t = 1;
    while(t--){
        ll n; cin >> n;
        vl a(n);
        rep(i, n) cin >> a[i];
        vl c;
        vl b(32, 0);
        rep(i, n){
            for(ll j = i+1; j < n; j++){
                ll ans = a[i]+a[j];
                c.emplace_back(ans);
            }
        }
        rep(i, c.size()){
            rep(j, 32){
                if(c[i]&(1<<j)) b[j]++;  
            }
        }
        ll count = 0;
        rep(i, 32){
            if(b[i]%2 != 0){
                count += pow(2, i);
            }
        }
        cout<<count;
    }
}