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
    
    ll n, m; cin >> n >> m;
    ll b[n][m]; zep(i, 0, n)zep(j, 0, m){cin >> b[i][j]; b[i][j]--;}

    if(b[0][0] % 7 + m - 1 >= 7){   
        print("No") return 0;
    }
    
    zep(j, 0, m){
        if(b[0][j] != b[0][0] + j){
            print("No") return 0;
        }
    }

    zep(i, 1, n){
        zep(j, 0, m){
            if(b[i][j] != b[i - 1][j] + 7){
                print("No") return 0;
            }
        }
    }
    
    print("Yes")
    
    return 0;
}