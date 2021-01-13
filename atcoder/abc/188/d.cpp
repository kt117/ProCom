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
    
    ll n, C; cin >> n >> C;
    ll a[n], b[n], c[n]; zep(i, 0, n)cin >> a[i] >> b[i] >> c[i];

    vector<P> v;
    zep(i, 0, n){
        v.push_back(P(a[i], c[i]));
        v.push_back(P(b[i] + 1, -c[i]));
    }

    sort(v.begin(), v.end());

    ll t = 0;
    ll sm = 0;
    ll ans = 0;
    zep(i, 0, v.size()){
        ans += min(C, sm) * (v[i].first - t);

        sm += v[i].second;
        t = v[i].first;
    }

    print(ans)
    
    return 0;
}