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
        ll n, m; cin >> n >> m;
        ll s[n][4]; zep(i, 0, n)zep(j, 0, 4)cin >> s[i][j];
        if(m % 2 != 0){print("NO") continue;}

        bool dig = false;
        zep(i, 0, n){
            if(s[i][1] == s[i][2])dig = true;
        }

        bool p = false;
        zep(i, 0, n){
            zep(j, i, n){
                if(s[i][0] == s[j][0] && s[i][3] == s[j][3] && s[i][1] == s[j][2] && s[i][2] == s[j][1])p = true;
            }
        }

        print((dig && p)? "YES" : "NO")
    }
    
    return 0;
}