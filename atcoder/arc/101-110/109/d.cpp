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

ll f(ll a, ll b, ll c, ll d){
    
    if(a == 0 && b == 0){return c + d;}
    if(a == 0 && b == 1){
        if(c == 0 && d == 0)return 2;
        if(c == 0 && d == 1)return 1;
        if(c == 1 && d == 0)return 2;
        if(c == 1 && d == 1)return 1;
    }
    if(a == 1 && b == 0){
        if(c == 0 && d == 0)return 2;
        if(c == 0 && d == 1)return 2;
        if(c == 1 && d == 0)return 1;
        if(c == 1 && d == 1)return 1;
    }
    if(a == 1 && b == 1){
        if(c == 0 && d == 0)return 3;
        if(c == 0 && d == 1)return 2;
        if(c == 1 && d == 0)return 2;
        if(c == 1 && d == 1)return 1;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll T; cin >> T;
    vector<ll> ans;
    while(T--){
        P x[3]; zep(i, 0, 3)cin >> x[i].first >> x[i].second;

        if(x[0].first == x[2].first)swap(x[1], x[2]);
        if(x[1].first == x[2].first)swap(x[0], x[2]);
        if(x[0].second == x[2].second)swap(x[0], x[1]);
        
        if(abs(x[1].first > x[1].second)){
            zep(i, 0, 3)swap(x[i].first, x[i].second);
        }

        if(x[1].first >= 0){
            if(x[1].second >= 0){
                //
            }else{
                x[1].second *= -1;
            }
        }else{
            if(x[1].second >= 0){
                //
            }else{
                x[1].second *= -1;
            }
            x[1].first *= -1;
        }

        ll res = 0;
        if(x[1].first <= 1){
            if(x[1].second > 1){
                ll tmp = x[1].second - 1;
                res += 2 * tmp;
                zep(i, 0, 3)x[i].second -= tmp;
            }
        }else{
            ll tmp = x[1].first - 1;
            res += 2 * tmp;
            zep(i, 0, 3)x[i].first -= tmp;
            zep(i, 0, 3)x[i].second -= tmp;

            if(x[1].second > 1){
                ll tmp2 = x[1].second - 1;
                res += 2 * tmp2;
                zep(i, 0, 3)x[i].second -= tmp2;
            }
        }

        ll ax = (x[0].second > x[1].second)? 0 : 1;
        ll ay = (x[2].first > x[1].first)? 0 : 1;
        ans.push_back(res + f(x[1].first, x[1].second, ax, ay));
    }

    zep(i, 0, ans.size()){
        print(ans[i])
    }
    
    return 0;
}