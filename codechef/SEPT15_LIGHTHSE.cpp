// https://www.codechef.com/SEPT15/status/LIGHTHSE,nemausus
// https://www.codechef.com/viewplaintext/8106877
//author Naresh
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define all(a) a.begin(),a.end()
#define rep(i, a, b) for(int i=(a); i<(b); ++i)
#define irep(i, a, b) for(int i=(a); i>=(b); --i)
#define iter(i,v) for(auto &i : (v))

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;

typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, int> psi;
typedef pair<string, string> pss;

typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;

// fast input
#define gc getchar_unlocked
template<class T> inline int readnum() { int i=gc(),f=1; for(;i<'0'||i>'9';i=gc()) if(i=='-') { f=-1;i=gc();break; } T ret = 0; for(;i>='0'&&i<='9';i=gc()) { ret = ret*10 + (i-'0'); } return f*ret; }
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() { string i=""; int c=gc(); while(c<'a'||c>'z') c=gc(); while(c>='a'&&c<='z') { i+=(char)c; c=gc(); } return i; }

// read and write
inline void svector(vector<int>& v, int n) { v.reserve(n); rep(i,0,n) v.push_back(si()); }
inline void sarray(int* v, int n) { rep(i,0,n) v[i] = si(); }
template<class T> inline void println(T t) { cout << t << endl; }
template<class T> inline void prints(T t) { cout << t << " "; }
template<class T> inline void print(T t) { cout << t; }
template<class T> inline void printlist(T l) { iter(i,l) prints(i); cout << endl; }
template<class T> inline void printlist(T *l, int n) { rep(i,0,n) prints(*(l+i)); cout << endl; }
template<class T> inline void printmap(T m) { iter(i,m) { prints(i.first); prints(i.second); } cout << endl; }

// general utils
template<class T> inline void setmax(T &a, T b) { if(b > a) a = b; }
template<class T> inline void setmin(T &a, T b) { if(b < a) a = b; }
template<class T> inline bool isInGrid(T i, T j, T n) { return i>=0 && i<n && j>=0 && j<n; }
template<class T> inline bool isInside(T a, T b, T c) { return a > b && a < c; }
template<class T> inline T reverse(T n) { T r = 0; while (n != 0) { r = r*10; r = r+n%10; n = n/10; } return r; }
template<class T> inline int firstdigit(T n) { int r = 0; while (n != 0) { r = n%10; n = n/10; } return r; }
template<class T> inline int digits(T n) { int r = 0; while (n != 0) { ++r; n /= 10; } return r; }
inline int frequency(string& s, char c) { int r = 0; rep(i,0,s.length()) if (s[i] == c) ++r; return r; }

// math utils
extern int MOD;
ll factorial(int x) { return (x < 2) ? 1 : x*factorial(x-1); }
ll getNcr(int n, int r) { return factorial(n)/(factorial(r) * factorial(n-r)); }
inline ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while(b) { if(b & 1) r = r*a % MOD; a = a*a % MOD; b >>= 1; } return r; }
inline ll inver(ll a,ll c = MOD) { ll ans = ipow(a,MOD-2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
int ncr[4][4];
void pascalTriangle() { rep(i, 0, 4) rep(j, 0, i+1) { if (j==0 || j==i) ncr[i][j] = 1; else ncr[i][j] = (ncr[i-1][j-1] + (ll)ncr[i-1][j]) % MOD; } }
inline bool almost_equal(double x, double y, int ulp) { return std::abs(x-y) < std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp || std::abs(x-y) < std::numeric_limits<double>::min(); }

// constants
const double PI = 3.14159265358979323846;
const int MAX_INF = (1LL << 31) - 1;
const int MIN_INF = (1LL << 31);
int MOD = 1E+7 + 7;

int main() {
  int tests, n, x, y;
  cin >> tests;
  while(tests--) {
    cin >> n;
    vector<pii> left, right, top, bottom, points;
    cin >> x >> y;
    auto p = make_pair(x,y);
    points.push_back(p);

    left.push_back(p);
    right.push_back(p);
    top.push_back(p);
    bottom.push_back(p);
    rep(i, 1, n) {
      cin >> x >> y;
      auto p = make_pair(x,y);
      points.push_back(p);

      if (x < left.front().first) left.clear();
      if (left.empty() || left.front().first == x) left.push_back(p);

      if (x > right.front().first) right.clear();
      if (right.empty() || right.front().first == x) right.push_back(p);

      if (y < bottom.front().second) bottom.clear();
      if (bottom.empty() || bottom.front().second == y) bottom.push_back(p);

      if (y > top.front().second) top.clear();
      if (top.empty() || top.front().second == y) top.push_back(p);
    }
    sort(all(left));
    sort(all(right));
    sort(all(top));
    sort(all(bottom));
//    printmap(left);
//    printmap(right);
//    printmap(top);
//    printmap(bottom);
    if (left.back() == top.front()) {
      int pos = find(all(points), left.back())-points.begin();
      printf("1\n%d SE\n", pos+1);
    } else if (top.back() == right.back()) {
      int pos = find(all(points), top.back())-points.begin();
      printf("1\n%d SW\n", pos+1);
    } else if (right.front() == bottom.back()) {
      int pos = find(all(points), bottom.back())-points.begin();
      printf("1\n%d NW\n", pos+1);
    } else if (bottom.front() == left.front()) {
      int pos = find(all(points), left.front())-points.begin();
      printf("1\n%d NE\n", pos+1);
    } else {
      if (top.front().first < bottom.back().first) {
        int pos = find(all(points), top.front())-points.begin();
        printf("2\n%d SE\n", pos+1);
        pos = find(all(points), bottom.back())-points.begin();
        printf("%d NW\n", pos+1);
      } else {
        int pos = find(all(points), top.front())-points.begin();
        printf("2\n%d SW\n", pos+1);
        pos = find(all(points), bottom.back())-points.begin();
        printf("%d NE\n", pos+1);
      }
    }
  }
  return 0;
}

