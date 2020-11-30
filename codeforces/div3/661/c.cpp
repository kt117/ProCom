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
        ll w[n]; zep(i, 0, n)cin >> w[i];
        
        ll cnt[n + 1]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n)cnt[w[i]]++;

        ll ans[2 * n + 1]; memset(ans, 0, sizeof(ans));

        rep(i, 1, n){
            rep(j, i, n){
                if(j == i){
                    ans[i + j] += cnt[i] / 2;
                }else{
                    ans[i + j] += min(cnt[i], cnt[j]);
                }
            }
        }

        ll mx = 0;
        rep(i, 1, 2 * n)mx = max(mx, ans[i]);
        print(mx)
    }
    
    return 0;
}