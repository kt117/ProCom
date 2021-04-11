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
        string s; cin >> s;
        ll n = s.size();

        bool okl[n + 10];
        okl[0] = true;
        okl[1] = true;
        zep(i, 0, n){
            okl[i + 2] = okl[i + 1];
            if(i > 0 && s[i - 1] == '1' && s[i] == '1'){
                okl[i + 2] = false;
            }
        }

        bool okr[n + 10];
        okr[n + 1] = true;
        okr[n] = true;
        rrep(i, n - 1, 0){
            okr[i] = okr[i + 1];
            if(i < n - 1 && s[i] == '0' && s[i + 1] == '0'){
                okr[i] = false;
            }
        }

        bool ans = false;
        rep(i, 0, n + 1){
            if(okl[i] && okr[i])ans = true;
        }
        print(ans? "YES" : "NO")
    }
    
    return 0;
}