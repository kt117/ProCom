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

ll n, p[555], at;
vector<ll> ans;

void sp(ll k){
    ans.push_back(k);
    ll tmp = p[k];
    p[k] = p[k + 1];
    p[k + 1] = tmp;
}

void lst4(){
    if(p[4] == 4)return;
    if(p[3] == 4){
        if(ans.size() % 2 == 0){
            sp(3);
        }else{
            sp(2);
            sp(3);
            sp(2);
            sp(3);
        }
        return;
    }
    if(p[2] == 4){
        if(ans.size() % 2 == 1){
            sp(2);
            sp(3);
        }else{
            sp(3);
            sp(2);
            sp(3);
        }
        return;
    }
    if(p[1] == 4){
        if(ans.size() % 2 == 0){
            sp(1);
            sp(2);
            sp(3);
        }else{
            sp(2);
            sp(1);
            sp(2);
            sp(3);
        }
    }
}

void lst3(){
    while(p[1] != 1 || p[2] != 2){
        if(ans.size() % 2 == 0){
            sp(1);
        }else{
            sp(2);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll T; cin >> T;
    while(T--){
        while(!ans.empty())ans.pop_back();

        cin >> n;
        rep(i, 1, n)cin >> p[i];

        if(n == 2){
            if(p[1] != 1)sp(1);
        }else{
            rrep(i, n, 5){
                if(p[i] == i)continue;

                rep(j, 1, i)if(p[j] == i)at = j;
                
                if(ans.size() % 2 == 1 && at % 2 == 1){
                    if(at == 3){
                        sp(4);
                    }else{
                        sp(2);
                    }
                }

                if(ans.size() % 2 == 0 && at % 2 == 0){
                    if(at == 2){
                        sp(3);
                    }else{
                        sp(1);
                    }
                }

                rep(j, at, i - 1){
                    sp(j);
                }
            }
            if(n >= 4)lst4();
            lst3();
        }

        print(ans.size())
        zep(j, 0, ans.size())cout << ans[j] << " "; cout << endl;
    }
    
    return 0;
}