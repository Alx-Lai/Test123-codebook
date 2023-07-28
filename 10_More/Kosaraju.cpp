vector<pii> edge[100020], redge[100020];
int vis[100020], scc[100020];
void dfs1(int x, vector<int> &stk) {
  vis[x] = 1;
  for (pii i : edge[x])
    if (!vis[i.X])
      dfs1(i.X, stk);
  stk.emplace_back(x);
}
void dfs2(int x, int id) {
  scc[x] = id;
  for (pii i : redge[x])
    if (!scc[i.X])
      dfs2(i.X, id);
}
void kosaraju() {
  int nscc = 0;
  vector<int> stk;
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs1(i, stk);
  while (stk.size()) {
    if (!scc[stk.back()])
      dfs2(stk.back(), ++nscc);
    stk.pop_back();
  }
}
