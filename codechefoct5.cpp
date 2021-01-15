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
    ll v, h, n, m; cin >> v >> h >> n >> m;
    vl vp(n), hp(m);
    rep(i, n) cin >> vp[i];
    rep(i, m) cin >> hp[i];
    unordered_set<ll> setB;
    for(ll i = 0;i < m; i++){
        setB.insert(hp[i]);
    }
    unordered_map<ll, ll> difvp;
    unordered_set<ll> difhp;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            difvp.insert({abs(vp[j] - vp[i]), 1});
        }
    }
    for(ll i = 0; i < m; i++){
        for(ll j = i+1; j < m; j++){
            difhp.insert(abs(hp[j]-hp[i]));
        }
    }
    ll sol1 = 0, sol2 = 0;
    auto itr = difhp.begin();
    while(itr != difhp.end()){
        if(difvp.find(*itr) != difvp.end()){
            sol1++;
            difvp[*itr] = -1;
        }
        itr++;
    }
    for(ll i = 0; i < h; i++){
        ll count = 0;
        if(setB.find(i) == setB.end()){
            unordered_set<ll> newpoint, del;
            for(ll j = 0; j < m; j++){
                newpoint.insert(abs(i-hp[j]));
            }
            auto itr1 = newpoint.begin();
            while(itr1 != newpoint.end()){
                if(difvp.find(*itr1) != difvp.end() and difvp[*itr1] == 1){
                    difvp[*itr1] = -1;
                    del.insert(*itr1);
                    count++;
                }
                itr1++;
            }
            auto itr2 = del.begin();
            while(itr2 != del.end()){
                difvp[*itr2] = 1;
                itr2++;
            }
        }
        sol2 = max(count, sol2);
    }
    cout<<sol1+sol2;
}