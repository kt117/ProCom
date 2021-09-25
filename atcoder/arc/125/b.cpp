#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;

    ll ans = 0;
    for(ll q = 1; q * q <= n; q++){
        if(q % 2 == 0){
            ans += n / q / 2 % MOD + MOD - (q - 1) / 2 % MOD;
        }else{
            ans += (n / q + 1) / 2 % MOD + MOD - q / 2 % MOD;
        }
        ans %= MOD;
    }
    print(ans)
    
    return 0;
}