// dfs to find pa[i][0] and de[i] first
for (int i = 1; i < 20; i++) {
  for (int j = 1; j <= n; j++) {
    pa[j][i] = pa[pa[j][i-1]][i-1];
  }
}

int lca(int a, int b) {
  if (de[a] < de[b]) swap(a, b);
  int diff = de[a] - de[b];
  for (int i = 0; i < 20; i++) {
    if (diff & 1) a = pa[a][i];
    diff >>= 1;
  }
  if (a == b) return a;
  for (int i = 19; i >= 0; i--) {
    if (pa[a][i] != pa[b][i]) {
      a = pa[a][i];
      b = pa[b][i];
    }
  }
  return pa[a][0];
}
