int bit[MAXN + 1];
inline int lowbit(int x) { return x & (-x); }
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= lowbit(i);
  }
  return s;
}
void add(int i, int x) {
  while (i <= MAXN) {
    bit[i] += x;
    i += lowbit(i);
  }
}
