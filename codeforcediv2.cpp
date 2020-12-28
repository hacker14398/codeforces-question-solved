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
    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n;
        vl a(n);
        rep(i, n) cin >> a[i]; 
        ll count = 0;
        rep(i, n) if(a[i] > 0) count+=a[i];
        ll flag = 0;
        ll sum = 0;
        ll ans = 0;
        rep(i, n){
            if(a[i] <= 0 and flag == 0) count+=a[i];
            else if(a[i] > 0 and flag == 0){
                if(count < a[i]){
                    a[i]=(a[i]-count);
                    break;
                }
                else{
                    a[i] = 0;
                }
                flag = 1;
            }
            else if(a[i] > 0 and flag == 1){
                if(count < a[i]){
                    a[i]=(a[i]-count);
                    break;
                }
                else{
                    a[i] = 0;
                }
            }
            else if(a[i] <= 0) count += a[i];
        }
        rep(i, n) if(a[i] > 0) ans+=a[i];
        cout<<ans<<"\n";
    }
}