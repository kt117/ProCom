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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];

    ll c[n]; zep(i, 0, n)c[i] = a[i] * b[i];
    ll sm = 0; zep(i, 0, n)sm += c[i];

    ll ans = sm;
    zep(i, 0, n - 1){
        ll cur = sm;
        rep(j, 1, min(i + 1, n - (i + 1))){
            cur -= a[i - j + 1] * b[i - j + 1];
            cur -= a[i + j] * b[i + j];
            cur += a[i - j + 1] * b[i + j];
            cur += a[i + j] * b[i - j + 1];
            ans = max(ans, cur);
        }
    }

    zep(i, 1, n - 1){
        ll cur = sm;
        rep(j, 1, min(i, n - i - 1)){
            cur -= a[i - j] * b[i - j];
            cur -= a[i + j] * b[i + j];
            cur += a[i - j] * b[i + j];
            cur += a[i + j] * b[i - j];
            ans = max(ans, cur);
        }
    }
    print(ans)

    return 0;
}