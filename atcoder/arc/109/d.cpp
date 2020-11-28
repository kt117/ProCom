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
    
    ll T; cin >> T;
    vector<ll> ans;
    while(T--){
        P x[3]; zep(i, 0, 3)cin >> x[i].first >> x[i].second;

        if(x[0].first == x[2].first){
            auto tmp = x[1];
            x[1] = x[2];
            x[2] = tmp;
        }

        if(x[1].first == x[2].first){
            auto tmp = x[0];
            x[0] = x[2];
            x[2] = tmp;
        }

        if(x[0].second == x[2].second){
            auto tmp = x[0];
            x[0] = x[1];
            x[1] = tmp;
        }
        //zep(i, 0, 3)cout << x[i].first << x[i].second << endl;
        if(x[1].first > 0){
            if(x[1].second > 0){
                ans.push_back(max(max(2 * (x[0].second - 1), 2 * x[0].first - 1), max(2 * (x[2].first - 1), 2 * x[2].second - 1)));
            }else if(x[1].second == 0){
                ans.push_back(max(2 * x[0].first - 1, 2 * (x[1].first - 1)));
            }else{
                ans.push_back(max(max(2 * (- x[0].second) - 1, 2 * x[0].first - 1), max(2 * (x[2].first - 1), - 2 * x[2].second)));
            }
        }else if(x[1].first == 0){
            if(x[1].second > 0){
                ans.push_back(max(2 * (x[0].second - 1), 2 * x[2].second - 1));
            }else if(x[1].second == 0){
                ll tmp = 0;
                if(x[0] == P(0, -1))tmp++;
                if(x[2] == P(-1, 0))tmp++;
                ans.push_back(tmp);
            }else{
                ans.push_back(max(2 * (- x[0].second) - 1, 2 * (- x[1].second)));
            }
        }else{
            if(x[1].second > 0){
                ans.push_back(max(max(2 * (x[0].second - 1), - 2 * x[0].first), max(2 * (- x[2].first) - 1, 2 * x[2].second - 1)));
            }else if(x[1].second == 0){
                ans.push_back(max(2 * (- x[0].first), 2 * (- x[1].first) - 1));
            }else{
                ans.push_back(max(max(2 * (- x[0].second) - 1, - 2 * x[0].first), max(2 * (- x[2].first) - 1, - 2 * x[2].second)));
            }
        }
    }

    zep(i, 0, ans.size()){
        print(ans[i])
    }
    
    return 0;
}