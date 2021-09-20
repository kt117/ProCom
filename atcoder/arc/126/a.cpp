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
        ll n[3]; zep(i, 0, 3)cin >> n[i];

        ll ans = 0;
        n[1] /= 2;
        
        ll a = min(n[1], n[2]);
        ans += a;
        n[1] -= a;
        n[2] -= a;

        ll b = min(n[0], n[2] / 2);
        ans += b;
        n[0] -= b;
        n[2] -= 2 * b;

        ll c = min(n[1], n[0] / 2);
        ans += c;
        n[1] -= c;
        n[0] -= 2 * c;

        ll d = min(n[2], n[0] / 3);
        ans += d;
        n[2] -= d;
        n[0] -= 3 * d;

        ll e = n[0] / 5;
        ans += e;
        n[0] -= 5 * e;

        print(ans)
    }
    
    return 0;
}