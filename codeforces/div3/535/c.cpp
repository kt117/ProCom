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
    string s; cin >> s;
    string t[2] = {"RGB", "RBG"};

    ll ans = INF;
    string u = s;
    zep(k, 0, 2){
        zep(j, 0, 3){
            string buf = s;
            ll cnt = 0;

            zep(i, 0, n){
                if(buf[i] != t[k][(i + j) % 3]){
                    buf[i] = t[k][(i + j) % 3];
                    cnt++;
                }
            }

            if(cnt < ans){
                ans = cnt;
                u = buf;
            }
        }
    }

    print(ans)
    print(u)
    
    return 0;
}