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
    
    ll b, c;
    cin >> b >> c;

    ll ans = 0;
    if(b > 0){
        ans += b - max(b - c / 2, 0LL) + 1;
        ans += b - max(b - (c - 1) / 2, 0LL) + 1;
        if(b - (c - 1) / 2 <= 0)ans--;
        ans += (c - 1) / 2;
        ans += (c - 2) / 2;
    }else if(b < 0){
        ans += - b - max(- b - (c - 1) / 2, 0LL) + 1;
        ans += - b - max(- b - (c - 2) / 2, 0LL) + 1;
        if(- b - (c - 2) / 2 <= 0)ans--;
        ans += c / 2;
        ans += (c - 1) / 2;
    }else{
        ans++;
        ans += c / 2;
        ans += (c - 1) / 2;
    }
    print(ans)
    
    return 0;
}