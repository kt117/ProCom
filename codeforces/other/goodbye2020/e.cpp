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
        ll n; cin >> n;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        ll cnt[60]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n){
            zep(j, 0, 60){
                if(a[i] & (1LL << j))cnt[j]++;
            }
        }

        ll ans = 0;
        zep(i, 0, n){
            ll l = 0;
            zep(j, 0, 60){
                if(a[i] & (1LL << j)){
                    l += (1LL << j) % MOD * cnt[j] % MOD;
                    l %= MOD;
                }
            }

            ll r = 0;
            zep(j, 0, 60){
                if(a[i] & (1LL << j)){
                    r += (1LL << j) % MOD * n % MOD;
                    r %= MOD;
                }else{
                    r += (1LL << j) % MOD * cnt[j] % MOD;
                    r %= MOD;
                }
            }

            ans += l * r % MOD;
            ans %= MOD;
        }
        print(ans)
    }
    
    return 0;
}