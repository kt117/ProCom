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
        ll b[n]; zep(i, 0, n)cin >> b[i];

        ll ok = 0;
        ll ng = n + 1;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;
            
            ll at = 0;
            ll d = 0;
            zep(i, 0, mid){
                d = max(d - (b[i] - at - 1), 0LL);
                at = b[i];
                d++;
            }

            if(d <= 2 * n - at - (n - mid)){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll okmin = ok;
        
        reverse(b, b + n);
        ok = 0;
        ng = n + 1;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;
            
            ll at = 2 * n  + 1;
            ll d = 0;
            zep(i, 0, mid){
                d = max(d - (at - b[i] - 1), 0LL);
                at = b[i];
                d++;
            }

            if(d <= at - 1 - (n - mid)){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll okmax = ok;
        //cout << okmin << " " << okmax << endl;
        print(max(0LL, n + 1 - (n - okmin) - (n - okmax)))
    }
    
    
    return 0;
}