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
typedef long long ll;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define irep(i, a, b) for (int i = (a); i >= (b); --i)

// Stream operators for std::pair
template<class F, class S> ostream& operator<<(ostream& os, const pair<F,S>& p) { return os << p.first << ":" << p.second; }
template<class F, class S> istream& operator>>(istream& is, pair<F,S>& p) { return is >> p.first >> p.second; }

// Debug write to stderr
template <class T> void print(T& t, string s = "") { cerr << "    " << t << s; }
template <class T> void printlist(T& l, int n, string s = "") { rep(i,0,n) print(l[i], s); print("\n"); }
template <class T> void printmap(T& m, string s = "") { for(auto& i : m) { print(i, s); } print("\n"); }

// Input from stdin
#define sint(x) int x; cin >> x
#define sdouble(x) double x; cin >> x
#define slong(x) ll x; cin >> x
#define sstring(x) string x; cin >> x
template <class T> void sarray(T& v, int n) { rep(i, 0, n) { cin >> v[i]; } }
template <class T> void sgrid(T& v, int r, int c) { rep(i, 0, r) rep(j, 0, c) { cin >> v[i][j]; } }

template <class T> void chmin(T &a, T b) { if (b < a) a = b; }
template <class T> void chmax(T &a, T b) { if (b > a) a = b; }

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sint(tests);
  rep(t, 0, tests) {
    cout << "Case #" << t + 1 << ": ";
    solve();
    cout << "\n";
  }
  return 0;
}
