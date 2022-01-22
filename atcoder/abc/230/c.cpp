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
    
    ll n, a, b; cin >> n >> a >> b;
    ll p, q, r, s; cin >> p >> q >> r >> s;

    rep(i, p, q){
        rep(j, r, s){
            bool bk = false;

            ll lb = max(1 - a, 1 - b), rb = min(n - a, n - b);
            if(a + lb <= i && i <= a + rb && b + lb <= j && j <= b + rb && i - a == j - b){
                bk = true;
            }
            lb = max(1 - a, b - n), rb = min(n - a, b - 1);
            if(a + lb <= i && i <= a + rb && b - rb <= j && j <= b - lb && i - a == b - j){
                bk = true;
            }
            cout << (bk? "#" : ".");
        }
        cout << endl;
    }
    
    return 0;
}