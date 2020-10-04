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
    
    string s; cin >> s;
    ll n = s.size();

    vector<vector<char>> ans(n);
    vector<ll> ansl(n);
    vector<char> ansr;

    deque<char> v;
    ll cnt = 0;
    vector<char> lst = {'a' - 1, 'a' - 1};

    rrep(i, n - 1, 0){
        if(v.empty()){
            v.push_front(s[i]);
            
            ans[i].push_back(s[i]);
            cnt++;

            lst.push_back(s[i]);
        }else{
            if(s[i] != v[0] || s[i] < lst[lst.size() - 2]){
                v.push_front(s[i]);
                if(v.size() > 10){
                    ansr.push_back(v.back());
                    v.pop_back();
                }

                zep(j, 0, v.size())ans[i].push_back(v[j]);
                cnt++;

                if(s[i] != lst.back())lst.push_back(s[i]);
            }else{
                v.pop_front();
                
                zep(j, 0, v.size())ans[i].push_back(v[j]);
                cnt--;

                lst.pop_back();
            }
        }
        ansl[i] = cnt;
        /*if(s[i] != lst[0]){
            lst[1] = lst[0];
            lst[0] = s[i];
        }*/
    }

    zep(i, 0, n){
        cout << ansl[i] << " ";

        if(ansl[i] > 10){
            zep(j, 0, 5)cout << ans[i][j];
            cout << "..." << ansr[1] << ansr[0] << endl;
        }else{
            zep(j, 0, ansl[i])cout << ans[i][j]; cout << endl;
        }
    }
    
    return 0;
}