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
    
    ll n, q; cin >> n >> q;

    vector<ll> f(n, -1), b(n, -1);
    
    while(q--){
        ll z; cin >> z;

        if(z == 1){
            ll x, y; cin >> x >> y; x--; y--;
            b[x] = y;
            f[y] = x;
        }
        if(z == 2){
            ll x, y; cin >> x >> y; x--; y--;
            b[x] = -1;
            f[y] = -1;
        }
        if(z == 3){
            ll x; cin >> x; x--;
            while(f[x] != -1){x = f[x];}
            
            vector<ll> ans;
            while(b[x] != -1){
                ans.push_back(x);
                x = b[x];
            }
            ans.push_back(x);

            cout << ans.size() << " ";
            zep(i, 0, ans.size())cout << ans[i] + 1 << " "; cout << endl;
        }
    }
    
    return 0;
}