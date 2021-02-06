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
    
    ll n, m; cin >> n >> m;
    ll a[m + 2]; rep(i, 1, m)cin >> a[i];
    sort(a + 1, a + m + 1);
    a[0] = 0;
    a[m + 1] = n + 1;

    ll mn = INF;
    rep(i, 0, m){
        if(a[i + 1] - a[i] - 1 > 0){
            mn = min(mn, a[i + 1] - a[i] - 1);
        }
    }

    ll ans = 0;
    rep(i, 0, m){
        //print(mn)
        //print(a[i + 1] - a[i] - 1)
        ans += (a[i + 1] - a[i] - 1 + mn - 1) / mn;
    }
    print(ans)
    
    return 0;
}