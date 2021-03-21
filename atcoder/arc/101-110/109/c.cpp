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
    
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    ll p[110]; p[0] = 1;
    rep(i, 1, 100)p[i] = p[i - 1] * 2 % n;
    //printa(p, 0, 4)
    char d[k + 1][n];

    zep(j, 0, n)d[0][j] = s[j];

    rep(i, 1, k){
        zep(j, 0, n){
            ll o = (j + p[i - 1]) % n;

            if(d[i - 1][j] == 'R'){
                if(d[i - 1][o] != 'P'){
                    d[i][j] = d[i - 1][j]; 
                }else{
                    d[i][j] = d[i - 1][o];
                }
            }else if(d[i - 1][j] == 'P'){
                if(d[i - 1][o] != 'S'){
                    d[i][j] = d[i - 1][j]; 
                }else{
                    d[i][j] = d[i - 1][o];
                }
            }else{
                if(d[i - 1][o] != 'R'){
                    d[i][j] = d[i - 1][j]; 
                }else{
                    d[i][j] = d[i - 1][o];
                }
            }
            //cout << d[i][j];
        }
        //cout << endl;
    }

    print(d[k][0])

    return 0;
}