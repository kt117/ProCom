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
    ll a[n]; zep(i, 0, n)cin >> a[i];
    sort(a, a + n);

    ll mnb = 0, ans = 0;
    zep(i, 0, n){
        mnb *= 2;
        mnb %= MOD;
        if(i > 0)mnb += a[i - 1];
        mnb %= MOD;
        ans += (mnb + a[i]) % MOD * a[i] % MOD;
        ans %= MOD;
    }
    print(ans)

    return 0;
}