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

ll cnt[3];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll k = 0;
    while(n){
        cnt[(n % 10) % 3]++;
        n /= 10;
        k++;
    }

    if(cnt[0] == 0 && ((cnt[1] == 0 && cnt[2] <= 2) || (cnt[2] == 0 && cnt[1] <= 2))){
        print(-1)
    }else{
        ll ans = k;
        ans -= cnt[0];
        while(!((cnt[1] == 0 && cnt[2] <= 2) || (cnt[2] == 0 && cnt[1] <= 2))){
            if(cnt[1] >= 3 && cnt[2] >= 3){
                ans -= 6;
                cnt[1] -= 3;
                cnt[2] -= 3;
            }else if(cnt[1] >= 3 && cnt[2] <= 1){
                ans -= 3;
                cnt[1] -= 3;
            }else if(cnt[2] >= 3 && cnt[1] <= 1){
                ans -= 3;
                cnt[2] -= 3;
            }else if(cnt[1] >= 2 && cnt[2] >= 2){
                ans -= 4;
                cnt[1] -= 2;
                cnt[2] -= 2;
            }else if(cnt[1] >= 1 && cnt[2] >= 1){
                ans -= 2;
                cnt[1]--;
                cnt[2]--;
            }
        }

        print(ans)
    }
    
    return 0;
}