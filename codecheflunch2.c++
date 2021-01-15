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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--){
        ll n, m, x, y; cin >> n >> m >> x >> y;
        ll count = 0;
        if(n == 1 and m == 1){
            cout<<x<<"\n";
            continue;
        }
        if(y >= x){
            ll s = (n*m);
            if(s%2 != 0){
                ll ans = ceil(s/2);
                count += ans*x;
                ans = s/2;
                if((y-x) >= x) count+=ans*x;
                else count+=ans*(y-x);
            }
            else{
                ll ans = s/2;
                count += ans*x;
                if((y-x) >= x) count+=ans*x;
                else count+=ans*(y-x);
            }
        }
        else{
            ll s = (n*m);
            ll c = ceil((double)s/2);
            //cout<<c<<"\n";
            count += c*y;
        }
        cout<<count<<"\n";
    }
    return 0;
}