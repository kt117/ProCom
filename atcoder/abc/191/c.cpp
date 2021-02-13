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

ll h, w, ans;
string s[10]; 


int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> h >> w;
    zep(i, 0, h)cin >> s[i];

    ll ans = 0;
    zep(i, 1, h){
        zep(j, 1, w){
            if(s[i - 1][j - 1] == '#' && s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j] == '.')ans++;
            if(s[i - 1][j - 1] == '.' && s[i - 1][j] == '#' && s[i][j - 1] == '.' && s[i][j] == '.')ans++;
            if(s[i - 1][j - 1] == '.' && s[i - 1][j] == '.' && s[i][j - 1] == '#' && s[i][j] == '.')ans++;
            if(s[i - 1][j - 1] == '.' && s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i][j] == '#')ans++;

            if(s[i - 1][j - 1] == '#' && s[i - 1][j] == '#' && s[i][j - 1] == '#' && s[i][j] == '.')ans++;
            if(s[i - 1][j - 1] == '#' && s[i - 1][j] == '#' && s[i][j - 1] == '.' && s[i][j] == '#')ans++;
            if(s[i - 1][j - 1] == '#' && s[i - 1][j] == '.' && s[i][j - 1] == '#' && s[i][j] == '#')ans++;
            if(s[i - 1][j - 1] == '.' && s[i - 1][j] == '#' && s[i][j - 1] == '#' && s[i][j] == '#')ans++;
        }
    }
    print(ans)

    return 0;
}