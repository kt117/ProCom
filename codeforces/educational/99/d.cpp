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
        ll n, x; cin >> n >> x;
        ll a[n]; zep(i, 0, n)cin >> a[i];
        
        ll b = n - 1;
        while(b > 0 && a[b - 1] <= a[b])b--;

        ll ans = 0;
        zep(i, 0, n){
            if(i >= b){
                if(i == 0 || a[i - 1] <= a[i])break;

                if(x < a[i]){
                    swap(x, a[i]);
                    ans++;
                }else{
                    ans = -1;
                    break;
                }
            }else{
                if(x < a[i]){
                    swap(x, a[i]);
                    ans++;
                }else{
                    if(i == 0 || a[i - 1] <= a[i]){
                        //
                    }else{
                        ans = -1;
                        break;
                    }
                }
            }
        }
        print(ans)
    }
    
    return 0;
}