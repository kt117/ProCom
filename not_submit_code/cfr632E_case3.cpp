/*
https://codeforces.com/contest/1333/problem/E
3x3の場合にrook pays strictly less vuns than the queenな盤面があるかを全探索した。
*/

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
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll pena(vector<ll> v, bool q){
    ll m[3][3]; zep(i, 0, 9){m[i/3][i%3] = v[i];}
    bool use[3][3]; memset(use, 0, sizeof(use));

    ll ai, aj;
    zep(i, 0, 3){zep(j, 0, 3){if(m[i][j] == 1){ai = i; aj = j;}}}
    use[ai][aj] = true;

    ll res = 0;
    zep(t, 1, 9){
        ll ni, nj;
        ll mi = INF;

        zep(i, 0, 3){
            zep(j, 0, 3){
                if((i == ai || j == aj) || (q && (i+j == ai+aj || i-j == ai-aj))){
                    if(!use[i][j] && m[i][j] < mi){
                        ni = i; nj = j; mi = m[i][j];
                    }
                }
            }
        }

        if(mi == INF){
            res++;

            zep(i, 0, 3){
                zep(j, 0, 3){
                    if(!use[i][j] && m[i][j] < mi){
                        ni = i; nj = j; mi = m[i][j];
                    }
                }
            }
        }
        ai = ni; aj = nj;
        use[ai][aj] = true;
    }
    return res;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    vector<ll> v;
    rep(i, 1, 9){v.push_back(i);}
    
    do{
        if(pena(v, false) < pena(v, true)){
            printa(v, 0, 8)
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    
    return 0;
}