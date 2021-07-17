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
    
    string s[3]; zep(i, 0, 3)cin >> s[i];

    map<char, ll> mp;
    ll cnt = 0;
    zep(i, 0, 3){
        zep(j, 0, s[i].size()){
            if(mp.find(s[i][j]) == mp.end()){
                mp[s[i][j]] = cnt; cnt++;
            }
        }
    }
    /*for(auto it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }*/
    if(cnt > 10){
        print("UNSOLVABLE") return 0;
    }

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    do{
        bool ok = true;
        zep(i, 0, 3)if(v[mp[s[i][0]]] == 0)ok = false;
        if(!ok)continue;

        ll n[3]; memset(n, 0, sizeof(n));
        zep(i, 0, 3){
            ll cnt = 1;
            rrep(j, s[i].size() - 1, 0){
                n[i] += v[mp[s[i][j]]] * cnt;
                cnt *= 10;
            }
        }

        if(n[0] + n[1] == n[2]){
            zep(i, 0, 3){
                print(n[i])
            }
            return 0;
        }
    }while(next_permutation(v.begin(), v.end()));
    
    print("UNSOLVABLE")

    return 0;
}