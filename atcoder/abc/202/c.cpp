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
    ll a[n], b[n + 1], c[n];
    zep(i, 0, n)cin >> a[i];
    rep(i, 1, n)cin >> b[i];
    zep(i, 0, n)cin >> c[i];

    ll cnt[n + 1]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, n)cnt[a[i]]++;
    
    ll ans = 0;
    zep(i, 0, n){
        ans += cnt[b[c[i]]];
    }
    print(ans)

    return 0;
}