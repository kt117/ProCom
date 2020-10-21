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
    
    ll n; cin >> n;
    ll a[n], b[n];
    zep(i, 0, n)cin >> a[i];
    zep(i, 0, n)cin >> b[i];

    ll ans = 0;
    zep(i, 0, n)ans += a[i];

    ll c[2][n / 2];
    
    zep(i, 0, n)c[i % 2][i / 2] = b[i] - a[i];
    sort(c[0], c[0] + n / 2);
    sort(c[1], c[1] + n / 2);
    
    zep(i, 0, n / 2)if(c[0][i] + c[1][i] > 0)ans += c[0][i] + c[1][i];

    print(ans);
    
    return 0;
}