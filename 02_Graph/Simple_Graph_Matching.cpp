#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(u) for (int i = h[u], v; v = e[i].t, i; i = e[i].n)
const int N = 520, M = 2e5 + 1;
queue<int> q;
int n, m, tot, qwq, ans;
int h[N], lk[N], tag[N], fa[N], pre[N], dfn[N];
struct edge {
  int t, n;
} e[M];
void link(int x, int y) { lk[x] = y, lk[y] = x; }
void add_edge(int x, int y) {
  if (!lk[x] && !lk[y]) link(x, y), ans++;
  e[++tot] = (edge){y, h[x]}, h[x] = tot;
  e[++tot] = (edge){x, h[y]}, h[y] = tot;
}
void rev(int x) {
  if (x) rev(x[pre][lk]), link(x, pre[x]);
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int lca(int x, int y) {
  for (qwq++;; x = x[lk][pre], swap(x, y))
    if (dfn[x = find(x)] == qwq)
      return x;
    else if (x)
      dfn[x] = qwq;
}
int shrink(int x, int y, int p) {
  for (; find(x) != p; x = pre[y]) {
    pre[x] = y, y = lk[x], fa[x] = fa[y] = p;
    if (tag[y] == 2) tag[y] = 1, q.push(y);
  }
}
int blossom(int u) {
  FOR(i, 1, n) tag[i] = pre[i] = 0, fa[i] = i;
  tag[u] = 1, q = queue<int>(), q.push(u);
  for (int p; !q.empty(); q.pop()) REP(u = q.front())
  if (tag[v] == 1)
    p = lca(u, v), shrink(u, v, p), shrink(v, u, p);
  else if (!tag[v]) {
    pre[v] = u, tag[v] = 2;
    if (!lk[v])
      return rev(v), 1;
    else
      tag[lk[v]] = 1, q.push(lk[v]);
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int x, y; m--; add_edge(x, y)) scanf("%d%d", &x, &y);
  FOR(i, 1, n) ans += !lk[i] && blossom(i);
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) cout << i << ' ' << lk[i] << '\n' return 0;
}
