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

string t = "atcoder";

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll T; cin >> T;
    while(T--){
        string s; cin >> s;
        if(s > t){print(0) continue;}

        ll ans = -1;
        zep(i, 0, s.size()){
            if(s[i] != 'a'){
                if(s[i] > 't'){
                    ans = i - 1;
                }else{
                    ans = i;
                }
                break;
            }
        }
        print(ans)
    }
    
    return 0;
}