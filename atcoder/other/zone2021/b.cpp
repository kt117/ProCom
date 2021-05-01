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
    
    ll n, D, H; cin >> n >> D >> H;
    ll d[n], h[n]; zep(i, 0, n)cin >> d[i] >> h[i];

    double ans = 0;
    zep(i, 0, n){
        ans = max(ans, double(D * h[i] - d[i] * H) / (D - d[i]));
    }
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}