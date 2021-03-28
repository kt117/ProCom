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
    zep(t, 0, T){
        ll n, c; cin >> n >> c;
        
        ll l[n], pos[n], posr[n]; zep(i, 0, n)pos[i] = i;
        
        c -= n - 1;
        if(c < 0){cout << "Case #" << t + 1 << ": IMPOSSIBLE" << endl; continue;}

        zep(i, 0, n - 1){   
            ll x = min(n - 1 - i, c);
            c -= x;
            l[pos[i + x]] = i + 1;

            zep(j, 0, n)posr[j] = pos[j];
            rep(j, i, i + x)posr[j] = pos[i + x - (j - i)];
            zep(j, 0, n)pos[j] = posr[j];   
        }
        l[pos[n - 1]] = n;
        
        cout << "Case #" << t + 1 << ": ";
        if(c > 0){
            cout << "IMPOSSIBLE" << endl;
        }else{
            zep(i, 0, n)cout << l[i] << " "; cout << endl;
        }
    } 
    
    return 0;
}