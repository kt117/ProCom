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

ll n, a[500], b[500];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    zep(i, 0, n){
        cin >> a[i] >> b[i];
    }

    zep(i, 0, n){if(a[i] != -1 && b[i] != -1 && a[i] > b[i]){print("No") return 0;}}

    ll it[2 * n + 1], ot[2 * n + 1];
    memset(it, -1, sizeof(it));
    memset(ot, -1, sizeof(ot));
    
    zep(i, 0, n){
        if(a[i] != -1){
            if(it[a[i]] != -1){print("No") return 0;}
            it[a[i]] = i;
        }
        if(b[i] != -1){
            if(ot[b[i]] != -1){print("No") return 0;}
            ot[b[i]] = i;
        }
    }

    rep(i, 1, 2 * n){if(it[i] != -1 && ot[i] != -1){print("No") return 0;}}

    bool dp[n + 1]; memset(dp, 0, sizeof(dp));
    dp[0] = true;

    rep(l, 0, n - 1){
        if(dp[l]){
            rep(r, l + 1, n){
                bool ok = true;

                rep(k, 2 * l + 1, l + r){if(ot[k] != -1)ok = false;}
                rep(k, l + r + 1, 2 * r){if(it[k] != -1)ok = false;}

                rep(k, 1, r - l){
                    if(!(it[2 * l + k] == -1 || ot[l + r + k] == -1 || it[2 * l + k] == ot[l + r + k])){
                        ok = false;
                    }
                }

                if(ok){
                    dp[r] = true;
                }
            }
        }
    }

    print(dp[n]? "Yes" : "No")
    return 0;
}