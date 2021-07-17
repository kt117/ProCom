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
    string s, x; cin >> s >> x;

    vector<ll> v(n);
    ll t = 1;
    rrep(i, n - 1, 0){
        v[i] = (s[i] - '0') * t % 7;
        t *= 10;
        t %= 7;
    }

    bool w[n + 1][7]; memset(w, 0, sizeof(w));
    w[n][0] = true;

    rrep(i, n - 1, 0){
        if(x[i] == 'T'){
            zep(j, 0, 7){
                if(w[i + 1][j]){
                    w[i][j] = true;
                }
            }

            zep(j, 0, 7){
                if(w[i + 1][(j + v[i]) % 7]){
                    w[i][j] = true;
                }
            }
        }else{
            zep(j, 0, 7){
                w[i][j] = true;
            }

            zep(j, 0, 7){
                if(!w[i + 1][j]){
                    w[i][j] = false;
                }
            }

            zep(j, 0, 7){
                if(!w[i + 1][(j + v[i]) % 7]){
                    w[i][j] = false;
                }
            }
        }
    }
    print(w[0][0]? "Takahashi" : "Aoki")
    
    return 0;
}