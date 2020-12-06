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
        ll a[n]; zep(i, 0, n){cin >> a[i]; a[i]--;}

        ll cnt[n]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n)cnt[a[i]]++;
        bool ok = true;
        zep(i, 0, n)if(cnt[i] > (n + 1) / 2)ok = false;
        if(!ok){print(-1) continue;}

        ll ans = 0;
        memset(cnt, 0, sizeof(cnt));
        cnt[a[0]]++;
        cnt[a[n - 1]]++;
        zep(i, 0, n - 1){
            if(a[i] == a[i + 1]){
                ans++;
                cnt[a[i]] += 2;
            }
        }
        
        ll mx = 0;
        zep(i, 0, n)mx = max(mx, cnt[i]);
        print(ans + max(mx - (ans + 2), 0LL))
    }
    
    return 0;
}