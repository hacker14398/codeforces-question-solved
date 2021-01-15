#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
typedef long long ll;
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

ll check(vl &A, ll x, ll y){
    unordered_set<ll> ans;
    for(ll i = x; i < y; i++){
        ans.insert(A[i]);
    }
    if(ans.size() == (y-x)) return 1;
    else return 0;
}

ll divleft(vl &A, ll x, ll y){
    if(x == y) return 0;
    map<ll, ll> ans; 
    for(ll i = x; i >= y; i--){
        ans[A[i]]++;
    }
    ll count = 0;
    for(auto i : ans){
        if(i.second > 1) count += i.second;
    }
    return count;
}
ll divright(vl &A, ll x, ll y){
    if(x == y) return 0;
    map<ll, ll> ans; 
    for(ll i = x; i < y; i++){
        ans[A[i]]++;
    }
    ll count = 0;
    for(auto i : ans){
        if(i.second > 1) count += i.second;
    }
    return count;
}

ll cost(vector<ll> &temp, ll k){
    map<ll, ll> ans;
    for(auto i : temp){
        ans[i]++;
    }
    ll count = 0;
    for(auto i : ans){
        if(i.second > 1) count += i.second;
    }
    count += k;
    return count;
}

ll solution(vector<ll> &A, ll start, ll end, ll k){
    if(start == end) return 0;
    unordered_set<ll> temp;
    vector<ll> left, right;
    ll orignal_cost = cost(A, k);
    ll i;
    for(i = 0; i < A.size(); i++){
        if (temp.find(A[i]) == temp.end()){
            temp.insert(A[i]);
            left.emplace_back(A[i]);
        }
        else break;
    }
    for(ll j = i; j < A.size(); j++){
        right.emplace_back(A[j]);
    }
    ll left_cost = cost(left, k);
    ll right_cost = solution(right, i, A.size(), k);
    return min(orignal_cost, (left_cost+right_cost));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        vl a(n);
        rep(i, n) cin >> a[i];
        if(check(a, 0, n)){
            cout<<k<<"\n";
            continue;
        }
        if(k == 1){
            ll res = solution(a, 0, n, k);
            cout<<res<<"\n";
            continue;
        }
        ll orignal_cost = cost(a, k);
        ll minof = INT_MIN;
        ll index;
        for(ll i = 0; i < n; i++){
            ll left = divleft(a, i, 0);
            ll right = divright(a, i+1, n);
            ll ans = (orignal_cost - k) - (left + right);
            if(ans > minof){
                minof = ans;
                index = i;
            }
        }
        vl a1, a2;
        for(ll i = 0; i <= index; i++){
            a1.emplace_back(a[i]);
        }
        for(ll i = index+1; i < n; i++){
            a2.emplace_back(a[i]);
        }
        ll leftres = solution(a1, 0, index+1, k);
        ll rightres = solution(a2, index+1, n, k);
        ll res = min(orignal_cost, (leftres+rightres));
        cout<<res<<"\n";
    }    
    return 0;
}