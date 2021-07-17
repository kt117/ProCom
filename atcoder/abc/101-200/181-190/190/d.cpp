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
    n *= 2;
    
    ll ans = 0;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(((n / i - i) % 2 + 2) % 2 == 1){
                ans++;
            }

            ll t = n / i;
            if(((n / t - t) % 2 + 2) % 2 == 1){
                ans++;
            }
        }
    }
    print(ans)
    
    return 0;
}