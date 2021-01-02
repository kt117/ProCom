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
    
    ll n; cin >> n;
    ll c[n]; zep(i, 0, n)cin >> c[i];

    ll mn = c[0]; zep(i, 0, n)mn = min(mn, c[i]);
    ll mne = c[0]; zep(i, 0, n)if(i % 2 == 0)mne = min(mne, c[i]);

    ll ans = 0;
    ll cnt = 0;
    ll cnte = 0;
    ll q; cin >> q;
    while(q--){
        ll f; cin >> f;

        if(f == 1){
            ll x, a; cin >> x >> a; x--;
            
            if(x % 2 == 0){
                if(c[x] - cnt - cnte >= a){
                    c[x] -= a;
                    ans += a;
                    mn = min(mn, c[x]);
                    mne = min(mne, c[x]);
                }
            }else{
                if(c[x] - cnt >= a){
                    c[x] -= a;
                    ans += a;
                    mn = min(mn, c[x]);
                }
            }
        }else if(f == 2){
            ll a; cin >> a;
            if(mne - cnt - cnte >= a){
                ans += a * ((n + 1) / 2);
                cnte += a;
            }
        }else{
            ll a; cin >> a;
            if(mn - cnt >= a && mne - cnt - cnte >= a){
                ans += a * n;
                cnt += a;
            }
        }
    }

    print(ans)

    return 0;
}