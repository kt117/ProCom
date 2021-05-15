#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t, n; cin >> t >> n;
    
    bool use[110 + t]; memset(use, 0, sizeof(use));

    rep(i, 1, 100){
        ll x = i * (100 + t) / 100;
        use[x] = true;
    }

    vector<ll> v;
    rep(i, 1, 100 + t){
        if(!use[i])v.push_back(i);
    }
    
    print((n - 1) / t * (100 + t) + v[n - (n - 1) / t * t - 1])
    
    return 0;
}