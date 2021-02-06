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

const double EPS = 1e-10;
const double PI = acosl(-1.0);

struct Point{
    double x, y;
    Point(double x=0.0, double y=0.0) : x(x), y(y) {}
};
inline Point operator + (Point p, Point q){return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (Point p, Point q){return Point(p.x - q.x, p.y - q.y);}
inline Point operator / (Point p, double a){return Point(p.x / a, p.y / a);}
inline Point rot(Point p, double ang){return Point(p.x * cos(ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));}
inline Point rot90(Point p){return Point(-p.y, p.x);}
inline double cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
inline double dot(Point p, Point q){return p.x * q.x + p.y * q.y;}
inline double abs(Point p){return sqrt(dot(p, p));}

struct Line{
    double a, b, c;
    Line(Point p=Point(), Point q=Point()){
        a = p.y - q.y;
        b = -(p.x - q.x);
        c = -(a * p.x + b * p.y);
    }
};

int ccw(Point a, Point b, Point c){
    if(cross(b - a, c - a) > EPS)return 1;
    if(cross(b - a, c - a) < -EPS)return -1;
    return 0;
}

Point intersection(Line l, Line m){return Point((l.b * m.c - m.b * l.c) / (l.a * m.b - m.a * l.b), (m.a * l.c - l.a * m.c) / (l.a * m.b - m.a * l.b));}

Point circumcenter(Point a, Point b, Point c){
    Line ab((a + b) / 2, (a + b) / 2 + rot90(a - b));
    Line bc((b + c) / 2, (b + c) / 2 + rot90(b - c));
    return intersection(ab, bc);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<Point> v(n);
    zep(i, 0, n)cin >> v[i].x >> v[i].y;
    
    bool ok = false;
    zep(i, 0, n){
        zep(j, i + 1, n){
            zep(k, j + 1, n){
                if(ccw(v[i], v[j], v[k]) == 0)ok = true;
            }
        }
    }
    print(ok? "Yes" : "No")

    return 0;
}