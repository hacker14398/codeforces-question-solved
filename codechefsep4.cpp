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

ll ncr(ll n, ll k) { 
    ll res = 1; 
    if (k > n - k) k = n - k; 
    for(ll i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    }
    return res; 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll sum = (n*(n+1))/2;
        if(sum%2 == 1) cout<<0<<"\n";
        else{
            ll ans = 0;
            ll half = sum/2;
            ll index;
            ll d = 1+4*(sum);
            ll mid = sqrt(d);
            index = (-1+mid)>>1;
            ll count = (index*(index+1))>>1;
            if(count == half){
                ans += ncr(index, 2);
                if(n-index >= 2) ans += ncr(n-index, 2);
                ll rem = half - (count - index);
                ll lower = index + 1 - rem, upper = n - rem;
                ans += (upper-lower+1);
            }
            else{
                ll rem = half - count;
                ll lower = index + 1 - rem, upper = n - rem;
                ans += (upper-lower+1);
            }
            cout<<ans<<"\n";
        }
    }
}