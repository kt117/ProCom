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
    
    ll q; cin >> q;
    while(q--){
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        ll x = 1;
        ll y = 1;
        while(n - k + 1 > x){
            x *= 2;
            y++;
        }
        y = min(y, k);

        zep(bit, 0, (1LL << y)){
            bool ok[n - k + 1]; memset(ok, 0, sizeof(ok));

            
        }

    }
    
    return 0;
}