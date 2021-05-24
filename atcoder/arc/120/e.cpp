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
    ll a[n + 2]; rep(i, 1, n)cin >> a[i];
    a[0] = a[1];
    a[n + 1] = a[n];

    ll ans = 0;
    rep(i, 1, n - 1){
        ans = max(ans, a[i + 2] - a[i - 1]);
    }
    print(ans / 2)
    
    return 0;
}