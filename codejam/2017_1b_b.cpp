// Author: Naresh
#include <algorithm>
#include <bitset>
#include <climits>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)
#define iter(i, v) for (auto &i : (v))

typedef long long ll;

#define gc getchar_unlocked
template <class T>
inline T readnum() {
  int i = gc(), f = 1;
  for (; i < '0' || i > '9'; i = gc())
    if (i == '-') {
      f = -1;
      i = gc();
      break;
    }
  T ret = 0;
  for (; i >= '0' && i <= '9'; i = gc()) {
    ret = ret * 10 + (i - '0');
  }
  return f * ret;
}
// utility methods to read input.
inline int si() { return readnum<int>(); }
inline ll sll() { return readnum<ll>(); }
inline string ss() { static char buf[100000]; if (scanf("%s", buf) != 1) return ""; return buf; }
inline void svector(vector<int> &v, int n) { v.reserve(n); rep(i, 0, n) v.push_back(si()); }
inline void sarray(int *v, int n) { rep(i, 0, n) v[i] = si(); }

// utility methods to debug write.
template <class T> void print(T t, string s = " ") { cerr << t << s; }
template <class T> void printlist(T l) { iter(i, l) print(i); cerr << endl; }
template <class T> void printlist(T *l, int n) { rep(i, 0, n) print(*(l + i)); cerr << endl; }
template <class T> void printmap(T m) { iter(i, m) { print(i.first); print(i.second); } cerr << endl; }
template <class T> void printpair(T m, T n) { cerr << m << " " << n << endl; }

// general utils.
template <class T> inline void setmax(T &a, T b) { if (b > a) a = b; }
template <class T> inline void setmin(T &a, T b) { if (b < a) a = b; }
template <class T> inline T reverse(T n) { T r = 0; while (n != 0) { r = r * 10; r = r + n % 10; n = n / 10; } return r; }
template <class T> inline int firstdigit(T n) { int r = 0; while (n != 0) { r = n % 10; n = n / 10; } return r; }
template <class T> inline int digits(T n) { int r = 0; while (n != 0) { ++r; n /= 10; } return r; }
inline int frequency(string &s, char c) { int r = 0; rep(i, 0, s.length()) if (s[i] == c)++ r; return r; }

// math utils
extern ll MOD;
// multiply add mod
template <class T> inline T mam(T a, T b, T c) { return ((a * b) % MOD + c) % MOD; }
ll factorial(int x) { return (x < 2) ? 1 : x * factorial(x - 1); }
ll ncr(int n, int r) { return factorial(n) / (factorial(r) * factorial(n - r)); }
ll ipow(ll a, ll b, ll c = MOD) { ll r = 1; while (b) { if (b & 1) r = r * a % MOD; a = a * a % MOD; b >>= 1; } return r; }
ll inver(ll a, ll c = MOD) { ll ans = ipow(a, MOD - 2); return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
bool almost_equal(double x, double y, int ulp = 4) {
  return abs(x - y) < numeric_limits<double>::epsilon() * abs(x + y) * ulp ||
         abs(x - y) < numeric_limits<double>::min();
}

// constants
const double PI = 3.141592653589793238463;
ll MOD = 1E+9 + 7;

struct C {
  char base;
  char opp;
  int count;
  bool operator<(const C& rhs) const { return count < rhs.count; }
};

int main() {
  int tests = si();
  rep(t, 0, tests) {
    int n = si();
    int R = si();
    int o = si();
    int Y = si();
    int g = si();
    int B = si();
    int v = si();

    int b = B - o;
    int y = Y - v;
    int r = R - g;
    vector<pair<int, C>> colors;
    colors.push_back(std::pair<int, C>(r, {'R', 'G', g}));
    colors.push_back(std::pair<int, C>(b, {'B' ,'O', o}));
    colors.push_back(std::pair<int, C>(y, {'Y' ,'V', v}));
    sort(all(colors));
    int trips = min(min(r, b), y);
    int doubles = min(colors[1].first - trips, colors[2].first - trips);
    int singles = colors[2].first - trips - doubles;
    printf("Case #%d: ", t + 1);
    if (singles > trips || b < 0 || y < 0 || r < 0 ||
        (colors[0].first == 0 && colors[0].second.count > 0) ||
        (colors[1].first == 0 && colors[1].second.count > 0)) {
      printf("IMPOSSIBLE");
    } else {
      string out = "";
      rep (i, 0, colors[0].second.count) {
        out += colors[0].second.base;
        out += colors[0].second.opp;
      }
      rep(i, 0, singles) {
        out += colors[0].second.base;
        out += colors[2].second.base;
        out += colors[1].second.base;
        out += colors[2].second.base;
      }
      rep(i, 0, trips - singles) {
        out += colors[0].second.base;
        out += colors[1].second.base;
        out += colors[2].second.base;
      }
      rep(i, 0, doubles) {
        out += colors[1].second.base;
        out += colors[2].second.base;
      }
      if (colors[1].second.count > 0) {
        char last = out[out.length()-1];
        out = out.substr(0, out.length()-1);
        rep (i, 0, colors[1].second.count) {
          out += colors[1].second.opp;
          out += colors[1].second.base;
        }
        out += last;
      }
      rep (i, 0, colors[2].second.count) {
        out += colors[2].second.opp;
        out += colors[2].second.base;
      }
      printf("%s", out.c_str());
    }
    printf("\n");
  }
  return 0;
}
