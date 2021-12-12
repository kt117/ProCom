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

string seven[3] = {
    "##....#",
    "..##..#",
    "....###"
};

string eight[4] = {
    "###.....",
    "...#..##",
    "....#.##",
    ".....###"
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string ans[n][n];
    
    zep(i, 0, n)zep(j, 0, n)ans[i][j] = '.';

    zep(i, 0, n / 3 * 3){
        zep(j, 0, 3){
            ans[i][i % (n / 3) * 3 + j] = '#';
        }
    }

    if(n % 3 == 1){
        zep(i, 0, 3){
            zep(j, 0, 7){
                ans[n - 3 + i][n - 7 + j] = seven[i][j];
            }
        }
    }else if(n % 3 == 2){
        zep(i, 0, 4){
            zep(j, 0, 8){
                ans[n - 4 + i][n - 8 + j] = eight[i][j];
            }
        }
    }

    zep(i, 0, n){
        zep(j, 0, n)cout << ans[i][j]; cout << endl;
    }

    
    
    return 0;
}