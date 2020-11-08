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
    
    ll x, y, a, b; cin >> x >> y >> a >> b;

    ll ans = 0;
    while(x < (b + a - 1 - 1) / (a - 1) && x < (y + a - 1) / a){
        x *= a;
        ans++;
    }

    if(y - 1 - x > 0){
        ans += (y - 1 - x) / b;
    }

    print(ans)
    
    return 0;
}