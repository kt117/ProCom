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

ll cnt[2][3], abc, acb, bac, bca, cab, cba;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s; cin >> s;

    zep(i, 0, n){
        cnt[0][s[i] - 'A']++;
        cnt[1][s[n + i] - 'A']++;
    }

    rep(x, 0, cnt[0][0]){
        abc = x;
        acb = cnt[0][0] - abc; if(acb < 0)continue;
        bca = cnt[1][2] - acb; if(bca < 0)continue;
        bac = cnt[0][1] - bca; if(bac < 0)continue;
        cab = cnt[1][0] - bac; if(cab < 0)continue;
        cba = cnt[0][2] - cab; if(cba < 0)continue;
        break;
    }

    ll ans[3 * n], cnta[6];

    memset(cnta, 0, sizeof(cnta));
    zep(i, 0, n){
        if(s[i] == 'A'){
            if(cnta[0] < abc){
                ans[i] = 0;
                cnta[0]++;
            }else{
                ans[i] = 1;
            }
        }else if(s[i] == 'B'){
            if(cnta[2] < bac){
                ans[i] = 2;
                cnta[2]++;
            }else{
                ans[i] = 3;
            }
        }else{
            if(cnta[4] < cab){
                ans[i] = 4;
                cnta[4]++;
            }else{
                ans[i] = 5;
            }
        }
    }

    memset(cnta, 0, sizeof(cnta));
    zep(i, n, 2 * n){
        if(s[i] == 'A'){
            if(cnta[2] < bac){
                ans[i] = 2;
                cnta[2]++;
            }else{
                ans[i] = 4;
            }
        }else if(s[i] == 'B'){
            if(cnta[0] < abc){
                ans[i] = 0;
                cnta[0]++;
            }else{
                ans[i] = 5;
            }
        }else{
            if(cnta[1] < acb){
                ans[i] = 1;
                cnta[1]++;
            }else{
                ans[i] = 3;
            }
        }
    }

    memset(cnta, 0, sizeof(cnta));
    zep(i, 2 * n, 3 * n){
        if(s[i] == 'A'){
            if(cnta[3] < bca){
                ans[i] = 3;
                cnta[3]++;
            }else{
                ans[i] = 5;
            }
        }else if(s[i] == 'B'){
            if(cnta[1] < acb){
                ans[i] = 1;
                cnta[1]++;
            }else{
                ans[i] = 4;
            }
        }else{
            if(cnta[0] < abc){
                ans[i] = 0;
                cnta[0]++;
            }else{
                ans[i] = 2;
            }
        }
    }

    zep(i, 0, 3 * n)cout << ans[i] + 1; cout << endl;
    
    return 0;
}