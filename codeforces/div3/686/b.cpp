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

        ll cnt[n + 1]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, n)cnt[a[i]]++;

        ll ans = -1;
        rep(i, 1, n){
            if(cnt[i] == 1){
                ans = i;
                break;
            }
        }

        if(ans == -1){
            print(ans)
        }else{
            zep(i, 0, n){
                if(a[i] == ans){
                    print(i + 1)
                }
            }
        }
    }
    
    return 0;
}