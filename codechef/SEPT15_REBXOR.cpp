// https://www.codechef.com/SEPT15/status/REBXOR,nemausus
// https://www.codechef.com/viewplaintext/8074953
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

struct Node {
  Node* left;
  Node* right;
};

void insert(Node* root, unsigned int value, int pos) {
  if (pos == -1) return;
  unsigned int bit = value & (1U<<pos);
  if (bit == 0) {
    if (root->left == nullptr) root->left = new Node();
    insert(root->left, value, pos-1);
  } else {
    if (root->right == nullptr) root->right = new Node();
    insert(root->right, value, pos-1);
  }
}

unsigned int getMax(Node* root, unsigned int value, int pos, unsigned int mxor, unsigned int ans) {
  if (pos == -1) return ans;
  unsigned int bit = value & (1U<<pos);
  Node* next;
  if (bit == 0) {
    if (root->right != nullptr) {
      next = root->right;
      ans |= 1U<<pos;
    } else {
      next = root->left;
    }
  } else {
    if (root->left != nullptr) {
      next = root->left;
      ans |= 1U<<pos;
    } else {
      next = root->right;
    }
  }
  if (ans < (mxor & (~0U ^ ((1<<pos)-1)))) {
    return 0;
  }
  return getMax(next, value, pos-1, mxor, ans);
}
unsigned int arr[400000], mleft[400000], mright[400000];
int main() {
  int n = si();
  rep(i, 0, n) {
    arr[i] = si();
  }

  int depth = 30;

  auto root = new Node();
  int xors = 0;
  unsigned int mxor = 0;
  insert(root, 0, depth);
  rep(i, 0, n) {
    xors = xors ^ arr[i];
    mleft[i] = max(mxor, getMax(root, xors, depth, mxor, 0));
    mxor = mleft[i];
    insert(root, xors, depth);
  }

  root = new Node();
  xors = 0;
  mxor = 0;
  insert(root, 0, depth);
  rep(i, 0, n) {
    xors = xors ^ arr[n-i-1];
    mright[i] = max(mxor, getMax(root, xors, depth, mxor, 0));
    mxor = mright[i];
    insert(root, xors, depth);
  }
  ll ans = -1;
  rep(i, 0, n-1) {
    ll sum = (ll)mleft[i] + (ll)mright[n-i-2];
    setmax(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}

