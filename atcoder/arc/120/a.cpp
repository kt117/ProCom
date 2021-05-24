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

    ll mx[n];
    mx[0] = a[0];
    zep(i, 1, n)mx[i] = max(mx[i - 1], a[i]);

    ll cum[n];
    zep(i, 0, n)cum[i] = a[i];
    zep(i, 1, n)cum[i] += cum[i - 1];
    
    ll cumcum[n];
    cumcum[0] = 0;
    zep(i, 1, n)cumcum[i] = cum[i - 1];
    zep(i, 1, n)cumcum[i] += cumcum[i - 1];

    zep(i, 0, n){
        ll res = 0;
        res += cum[i];
        res += mx[i] * (i + 1);
        res += cumcum[i];
        print(res)
    }

    return 0;
}