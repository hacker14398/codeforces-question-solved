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
typedef vector<char>     vc;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
//typedef vector<vi>      vvi;
typedef vector<vl>      vvl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        string s, p; cin >> s >> p;
        map<char, ll> ans;
        for(auto i : s) ans[i]++;
        for(auto i : p){
            ans[i]--;
        }
        string res1, res;
        for(auto i : ans){
            while(i.second--) res1 += i.first;
        }
        sort(res1.begin(), res1.end());
        auto itr = lower_bound(res1.begin(), res1.end(), p[0]);
        auto itr1 = upper_bound(res1.begin(), res1.end(), p[0]);
        ll pos = (itr - res1.begin());
        ll up = itr1 - res1.begin();
        std::vector<string> v;
        for(ll i = pos; i <= up; i++){
            string r;
            r+=res1;
            r.insert(i, p);
            v.emplace_back(r);
        }
        sort(v.begin(), v.end());
        cout<<v[0]<<"\n";
    }    
    return 0;
}