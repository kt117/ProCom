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
        ll a[n + 1]; rep(i, 1, n)cin >> a[i];

        bool f = true;
        ll cnt = 0;
        rep(i, 1, n){
            if(a[i] == i){
                if(!f){
                    f = true;
                }
            }else{
                if(f){
                    f = false;
                    cnt++;
                }
            }
        }

        if(cnt == 0){
            print(0)
        }else if(cnt == 1){
            print(1)
        }else{
            print(2)
        }
    }
    
    return 0;
}