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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll r[n]; zep(i, 0, n)cin >> r[i];
        ll m; cin >> m;
        ll b[m]; zep(i, 0, m)cin >> b[i];

        zep(i, 1, n)r[i] += r[i - 1];
        zep(i, 1, m)b[i] += b[i - 1];

        ll ansr = 0; zep(i, 0, n)ansr = max(ansr, r[i]);
        ll ansb = 0; zep(i, 0, m)ansb = max(ansb, b[i]);

        print(ansr + ansb)
    }
    
    return 0;
}