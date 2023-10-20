struct Seg {
  struct line {
    ll m, c;
    line(ll _m = 0, ll _c = LLONG_MAX) : m(_m), c(_c) {}
    ll operator()(ll x) { return m * x + c; }
  };
  struct node {
    node *l, *r;
    line f;
    node() {
      f = line();
      l = r = nullptr;
    }
  };
  typedef node *pnode;
  pnode root;
  int sz;
  Seg(int _sz = 0) : sz(_sz + 1), root(nullptr) {}
  void insert(line v, int l, int r, int L, int R, pnode &nd) {
#define mid ((l + r) >> 1)
#define M ((L + R) >> 1)
    if (nd == nullptr) {
      nd = new node();
    }
    if (L >= l && R <= r) {
      // empty
      if (v.m == 0 && v.c == LLONG_MAX) {
        nd->f = v;
        return;
      }
      if (nd->f(L) <= v(L)) {
        if (nd->f(R) <= v(R)) return;
        if (nd->f(M) <= v(M)) {
          return insert(v, l, r, M + 1, R, nd->r);
        } else {
          swap(nd->f, v);
          return insert(v, l, r, L, M, nd->l);
        }
      }

      if (nd->f(R) >= v(R)) {
        nd->f = v;
        return;
      }

      if (nd->f(M) >= v(M)) {
        swap(nd->f, v);
        return insert(v, l, r, M + 1, R, nd->r);
      }
      return insert(v, l, r, L, M, nd->l);
    }
    if (l <= M) insert(v, l, r, L, M, nd->l);
    if (r > M) insert(v, l, r, M + 1, R, nd->r);
  }

  void insert(ll l, ll r, ll a, ll b) { 
    insert({a, b}, l, r, -sz, sz, root);
  }

  ll query(ll x, int L, int R, pnode &nd) {
    // cerr << format("(L,R)=({},{})\n", L, R);
    ll res = LLONG_MAX;
    if (nd == nullptr) {
      return res;
    }
    res = min(res, nd->f(x));
    if (x <= M) {
      res = min(res, query(x, L, M, nd->l));
    } else {
      res = min(res, query(x, M + 1, R, nd->r));
    }
    return res;
  }
  ll query(ll x) { return query(x, -sz, sz, root); }
};
// usage:
//  Seg tree(sz);
//  tree.insert(l, r-1, m, c);
//  tree.query(p);
