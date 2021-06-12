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
    
    ll dp[150]; memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    zep(i, 2, 150){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    ll at = 0;
    while(dp[at + 1] <= n)at++;

    n -= dp[at];

    vector<ll> ans;
    rep(i, 0, at){
        if(i == at){
            ans.push_back(3);
        }else if(i == 0){
            ans.push_back(1);
        }else{
            if(i % 2 == 0){
                ans.push_back(3);
            }else{
                ans.push_back(4);
            }
        }

        while(dp[at - i] <= n){
            if(i % 2 == 0){
                ans.push_back(1);
            }else{
                ans.push_back(2);
            }
            n -= dp[at - i];
        }
    }

    // ll x = 0, y = 0;
    // zep(i, 0, ans.size()){
    //     if(ans[i] == 1){
    //         x++;
    //     }else if(ans[i] == 2){
    //         y++;
    //     }else if(ans[i] == 3){
    //         x += y;
    //     }else{
    //         y += x;
    //     }
    // }
    // print(x)

    print(ans.size())
    zep(i, 0, ans.size()){
        print(ans[i])
    }

    return 0;
}