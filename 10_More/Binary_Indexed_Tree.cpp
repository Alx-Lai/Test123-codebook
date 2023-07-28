int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}
void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}
