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

const ll MAX = 1e6;
vector<bool> prime(MAX + 1, true);
ll n, k;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> k;
    
    vector<ll> v(k);
    zep(i, 0, k)v[i] = n - i;

    ll ans = 1;
    rep(i, 2, MAX){
        if(prime[i]){
            for(ll j = 2; i * j <= MAX; j++){
                prime[i * j] = false;
            }

            ll cnt = 0;

            for(ll j = ((n - k) / i + 1) * i; j <= n; j += i){
                while(v[n - j] % i == 0){
                    cnt++;
                    v[n - j] /= i;
                }
            }

            for(ll j = i; j <= k; j += i){
                ll x = j;
                while(x % i == 0){
                    cnt--;
                    x /= i;
                }
            }

            // if(i <= 10)cout << i << " " << cnt << endl;
            ans *= cnt + 1; ans %= MOD;
        }
    }
    
    zep(i, 0, k){
        if(v[i] > 1){
            ans *= 2; ans %= MOD;
        }
    }

    print(ans)
    
    return 0;
}