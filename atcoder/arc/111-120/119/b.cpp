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
    string s, t; cin >> s >> t;
    
    ll cnts = 0, cntt = 0;
    zep(i, 0, n){
        if(s[i] == '1')cnts++;
        if(t[i] == '1')cntt++;
    }

    if(cnts != cntt){
        print(-1)
        return 0;
    }

    ll cnt = 0, ans = 0;
    zep(i, 0, n){
        if(s[i] == '1'){
            if(t[i] == '1'){
                // pass
            }else{
                if(cnt >= 0)ans++;
                cnt++;
            }
        }else{
            if(t[i] == '1'){
                if(cnt <= 0)ans++;
                cnt--;
            }else{
                if(cnt != 0)ans++;
            }
        }
    }
    print(ans)
    
    return 0;
}