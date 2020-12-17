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
    while(T--){
        ll n; cin >> n;
        ll t[n], x[n]; zep(i, 0, n)cin >> t[i] >> x[i];

        ll ans = 0;
        ll now = 0;
        ll at = 0;
        ll move = 0;
        ll dir = 1;
        zep(i, 0, n){
            if(move <= t[i] - now){
                if(i > 0){
                    if(dir > 0){
                        if(at <= x[i - 1] && x[i - 1] <= at + move)ans++;
                    }else{
                        if(at - move <= x[i - 1] && x[i - 1] <= at)ans++;
                    }
                }
                at += dir * move;
                move = 0;
            }else{
                if(i > 0){
                    if(dir > 0){
                        if(at <= x[i - 1] && x[i - 1] <= at + (t[i] - now))ans++;
                    }else{
                        if(at - (t[i] - now) <= x[i - 1] && x[i - 1] <= at)ans++;
                    }
                }
                at += dir * (t[i] - now);
                move -= t[i] - now;
            }

            if(move == 0){
                move = abs(x[i] - at);
                dir = (x[i] - at) / abs(x[i] - at);
            }

            now = t[i];
            //cout << ans << " " << at << " " << move << " " << dir << endl;
        }

        if(dir > 0){
            if(at <= x[n - 1] && x[n - 1] <= at + move)ans++;
        }else{
            if(at - move <= x[n - 1] && x[n - 1] <= at)ans++;
        }

        print(ans)        
    }
    
    return 0;
}