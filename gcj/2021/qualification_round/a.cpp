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
    
    ll T; cin >> T;
    zep(t, 0, T){
        ll n; cin >> n;
        ll l[n], r[n]; zep(i, 0, n)cin >> l[i];

        ll ans = 0;
        zep(i, 0, n - 1){
            ll mn = l[i];
            ll at = i;
            zep(j, i + 1, n){
                if(l[j] < mn){
                    mn = l[j];
                    at = j;
                }
            }
            //print(at - i + 1)
            ans += at - i + 1;
            
            zep(j, 0, n)r[j] = l[j];
            rep(j, i, at)r[j] = l[at - (j - i)];
            zep(j, 0, n)l[j] = r[j];
            //printa(l, 0, n - 1)
        }

        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
    
    return 0;
}