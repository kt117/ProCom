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
    
    ll n, k; cin >> n >> k;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    ll cnt[n]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, n)cnt[a[i]]++;

    ll ans = 0;
    zep(i, 0, n){
        if(cnt[i] < k){
            ans += (k - cnt[i]) * i;
            k = cnt[i];
        }
    }
    print(ans)
    
    return 0;
}