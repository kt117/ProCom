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
        zep(i, 1, n)a[i] += a[i - 1];

        double ans = -INF;
        zep(i, 0, n - 1){
            double x = double(a[i]) / (i + 1) + double(a[n - 1] - a[i]) / (n - i - 1);
            // print(x)
            ans = max(ans, x);
        }
        cout << fixed << setprecision(20) << ans << endl;
    }
    
    return 0;
}