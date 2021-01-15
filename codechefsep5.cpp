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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n, x, ans = 0; cin >> n;
        vl xorsum;
        for(ll i = 1; i <= 20; i++){
            cout<<1<<" "<<(1ul<<i)<<"\n";
            cout.flush();
            cin >> x;
            xorsum.emplace_back(x);
        }
        reverse(xorsum.begin(), xorsum.end());
        ll s = xorsum[0]-n*(1ul<<20);
        for(ll i = 1; i < xorsum.size(); i++){
            if(xorsum[i] >= s) xorsum[i]=((n-(xorsum[i]-s)/(1ul<<(xorsum.size()-i)))/2);
            else{
                xorsum[i] = (n+(s-xorsum[i])/(1ul<<(xorsum.size()-i)))/2;
            }
        }
        for(ll i = 1; i < xorsum.size(); i++) if(xorsum[i]%2 != 0) ans += 1ul<<(xorsum.size()-i);
        if(s%2 != 0) ans++;
        cout<<2<<" "<<ans<<"\n";
        cout.flush();
        ll res; cin >> res;
        if(!res) break;
        cout<<"\n";
        cout.flush();
    }
}