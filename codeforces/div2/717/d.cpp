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

ll n, q, a[101 * 1001], dp[20][101 * 1001], mp[101 * 1001]; 

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> q;
    zep(i, 0, n)cin >> a[i];

    zep(i, 0, n)zep(j, 0, 20)dp[j][i] = INF;
    memset(mp, -1, sizeof(mp));

    zep(i, 0, n){
        for(ll j = 2; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                if(mp[j] != -1)dp[0][mp[j]] = min(dp[0][mp[j]], i);
                mp[j] = i;
                while(a[i] % j == 0)a[i] /= j;
            }
        }
        if(a[i] > 1){
            if(mp[a[i]] != -1)dp[0][mp[a[i]]] = min(dp[0][mp[a[i]]], i);
            mp[a[i]] = i;
        }
    }
    rrep(i, n - 2, 0)dp[0][i] = min(dp[0][i], dp[0][i + 1]);

    zep(j, 1, 20){
        zep(i, 0, n){
            if(dp[j - 1][i] < n)dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }
    
    while(q--){
        ll l, r; cin >> l >> r; l--; r--;

        ll ans = 0;
        rrep(j, 19, 0){
            if(dp[j][l] <= r){
                l = dp[j][l];
                ans += (1LL << j);
            }
        }
        print(ans + 1)
    }

    return 0;
}