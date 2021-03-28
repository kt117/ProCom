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

    ll cnt[2] = {0, 0};
    while(m % 2 == 0){cnt[0]++; m /= 2;}
    while(m % 3 == 0){cnt[1]++; m /= 3;}
    while(n % 2 == 0){cnt[0]--; n /= 2;}
    while(n % 3 == 0){cnt[1]--; n /= 3;}

    if(n == m && cnt[0] >= 0 && cnt[1] >= 0){
        print(cnt[0] + cnt[1])
    }else{
        print(-1)
    }
    
    return 0;
}