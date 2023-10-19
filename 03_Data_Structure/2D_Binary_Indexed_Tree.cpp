int lowbit(int x) {return x&(-x);}
ll bit[MAXN][MAXN];
void add (int x, int y, int d){
  for (int i = x; i <= C; i += lowbit(i)) {
    for (int j = y; j <= R; j += lowbit(j)) bit[i][j] += d;
  }
}
int sum (int x, int y) {
  int rt = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j)) rt += bit[i][j];
  return rt;
}
int count(int l, int t, int r, int d) {
  return sum(r, d) + sum(l-1, t-1) - sum(l-1, d) - sum(r, t-1);
}
