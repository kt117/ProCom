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
    ll a[2 * n]; char c[2 * n]; zep(i, 0, 2 * n)cin >> a[i] >> c[i];

    multiset<ll> s[3];
    zep(i, 0, 2 * n){
        s[c[i] % 3].insert(a[i]);
    }

    if(s[0].size() % 2 == 0 && s[1].size() % 2 == 0 && s[2].size() % 2 == 0){
        print(0) return 0;
    }
    // cout << 'R' % 3 << 'G' % 3 << 'B' % 3 << endl;
    ll v[3][3];
    zep(i, 0, 3)zep(j, 0, 3)v[i][j] = INF;
    zep(i, 0, 3){
        zep(j, 0, 3){
            for(auto it = s[i].begin(); it != s[i].end(); it++){
                ll x = *it;
                if(s[j].lower_bound(x) != s[j].end()){
                    ll y = *s[j].lower_bound(x);
                    v[i][j] = min(v[i][j], y - x);
                    v[j][i] = min(v[j][i], y - x);
                }
            }
        }
    }
    //zep(i, 0, 3){zep(j, 0, 3)cout << v[i][j] << " "; cout << endl;}

    zep(i, 0, 3){
        if(s[i].size() % 2 == 0){
            print(min(v[(i + 1) % 3][(i + 2) % 3], v[i][(i + 1) % 3] + v[i][(i + 2) % 3]))
            return 0;
        }
    }

    return 0;
}