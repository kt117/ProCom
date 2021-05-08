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

ll p[1000];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    zep(i, 2, 1000){
        if(p[i] == 0){
            for(ll j = 2; i * j < 1000; j++){
                p[i * j] = i;
            }
        }
    }
    p[1] = -1;

    ll ans = 0;
    zep(i, 0, 20){
        zep(j, 0, 20){
            ll x; cin >> x;
            if(p[x] == 0)ans++;
        }
    }
    print(ans)
    
    return 0;
}