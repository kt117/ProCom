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
    
    ll n, k; cin >> n >> k;
    ll p[n]; zep(i, 0, n)cin >> p[i];

    ll ten[n]; memset(ten, 0, sizeof(ten));
    zep(i, 0, n){zep(j, 0, i)if(p[j] > p[i])ten[i]++;

    ll ans = 1;
    rep(j, 1, n){
        ll at = -1;
        zep(i, 0, n)if(p[i] == j){at = i; break;}

        ll ten = 0;
        zep(i, 0, at)if(p[i] > j)ten++;
        
        if(ten == k){
            ll cnt = 0;
            while(at > 0 && p[at - 1] < j){cnt++; at--;}
            
            ans *= cnt + 1;
            ans %= MOD;
        }
        // cout << at << " " << ten << " " << ans << endl;
    }
    print(ans)
    
    return 0;
}