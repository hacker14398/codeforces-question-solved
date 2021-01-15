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
ll MOD = 1e9+7;
vector<ll> fact(1e5+1, 1);

ll Pow(ll base, ll pow) {
    ll res = 1;
    while(pow > 0) {
        if(pow&1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        pow >>= 1;
    }
    return res%MOD;
}

ll modinverse(ll x) {
    return Pow(x, MOD-2);
}

//ncr%p (fermat's theorem)
ll ncr(ll n, ll r) {
    ll inverse = modinverse(fact[r]);
    return (fact[n]*((inverse * inverse) % MOD)) % MOD;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i = 2; i < 1e5+1; ++i) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
         ll n; cin >> n;
        vl arr(n);
        ll mx = LLONG_MIN, freq = 0;
        ll ans = Pow(2, n);
        rep(i, n){
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        for(auto x : arr) {
            if(x == mx) {
                freq ++;
            }
        }
        if(!(freq&1)) {
            ll minus = ncr(freq, freq/2);
            minus = (minus * Pow(2, n-freq))%MOD;
            ans = (ans+MOD-minus)%MOD;
        }
        cout << ans << "\n";
    }
}