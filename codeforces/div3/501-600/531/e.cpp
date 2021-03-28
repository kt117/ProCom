#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

long long powmod(long long a, long long x){
    if(x == 0)return 1;
    long long r = powmod(a, x / 2);
    return (x%2)? (r * r % MOD) * a % MOD : r * r % MOD;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    map<ll, ll> l, r;
    zep(i, 0, n){
        if(l.find(a[i]) == l.end()){
            l[a[i]] = i;
            r[a[i]] = i;
        }else{
            r[a[i]] = i;
        }
    }

    vector<P> v;
    for(auto it = l.begin(); it != l.end(); it++){
        v.push_back(P((*it).second, (*it).first));
    }

    for(auto it = r.begin(); it != r.end(); it++){
        v.push_back(P((*it).second, (*it).first));
    }
    sort(v.begin(), v.end());
    
    set<ll> s;
    ll ans = 0;
    zep(i, 0, v.size()){
        ll x = v[i].second;
        if(s.find(x) == s.end()){
            s.insert(x);
        }else{
            s.erase(x);
        }
        if(s.empty())ans++;
    }
    print(powmod(2, ans - 1))

    return 0;
}