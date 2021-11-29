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
    
    ll h, w, C, q; cin >> h >> w >> C >> q;
    ll t[q], n[q], c[q]; zep(i, 0, q){cin >> t[i] >> n[i] >> c[i]; n[i]--; c[i]--;}
    
    ll ans[C]; memset(ans, 0, sizeof(ans));
    set<ll> use;

    ll hcnt = h, wcnt = w;
    rrep(i, q - 1, 0){
        if(t[i] == 1){
            if(use.find(n[i]) == use.end()){
                ans[c[i]] += wcnt;
                hcnt--;
                use.insert(n[i]);
            }
        }else{
            if(use.find(h + n[i]) == use.end()){
                ans[c[i]] += hcnt;
                wcnt--;
                use.insert(h + n[i]);
            }
        }
        // zep(i, 0, C)cout << ans[i] << " "; cout << endl;
    }

    zep(i, 0, C)cout << ans[i] << " "; cout << endl;

    return 0;
}