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
    
    ll k, n, m; cin >> k >> n >> m;
    ll a[k]; zep(i, 0, k)cin >> a[i];
    ll b[k]; zep(i, 0, k)b[i] = m * a[i] / n;

    ll c[k]; zep(i, 0, k)c[i] = m * a[i] - n * b[i];
    P d[k]; zep(i, 0, k)d[i] = P(c[i], i);
    sort(d, d + k, greater<>());
    
    zep(i, 0, k)m -= b[i];
    zep(i, 0, m)b[d[i].second]++;

    zep(i, 0, k)cout << b[i] << " "; cout << endl;
    
    return 0;
}