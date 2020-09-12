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
        ll a[n]; zep(i, 0, n)cin >> a[i];

        sort(a, a + n);

        ll ans = -INF;
        ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
        ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[0] * a[1]);
        ans = max(ans, a[n - 1] * a[0] * a[1] * a[2] * a[3]);

        zep(i, 0, n)a[i] = abs(a[i]);
        sort(a, a + n);

        ans = max(ans, -1 * a[0] * a[1] * a[2] * a[3] * a[4]);
        
        print(ans)
    }
    
    return 0;
}