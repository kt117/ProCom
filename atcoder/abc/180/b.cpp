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
    ll x[n]; zep(i, 0, n)cin >> x[i];
    
    ll a = 0;
    zep(i, 0, n)a += abs(x[i]);
    print(a)
    ll b = 0;
    zep(i, 0, n)b += x[i] * x[i];
    cout << fixed << setprecision(20) << sqrt(b) << endl;
    ll c = 0;
    zep(i, 0, n)c = max(c, abs(x[i]));
    print(c)

    return 0;
}