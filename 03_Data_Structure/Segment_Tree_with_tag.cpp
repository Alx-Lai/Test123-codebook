void push(int id, int l, int r) {
  int mid = (l + r) >> 1;
  seg[id * 2] += tag[id] * (mid - l + 1);
  seg[id * 2 + 1] += tag[id] * (r - mid);
  tag[id * 2] += tag[id];
  tag[id * 2 + 1] += tag[id];
  tag[id] = 0;
}
void modify(int id, int l, int r, int ql, int qr, int val) {
  if (ql > r || qr < l)
    return;
  if (ql <= l && r <= qr) {
    seg[id] += val * (r - l + 1);
    tag[id] += val;
    return;
  }
  if (l == r)
    return;
  push(id, l, r);
  int mid = (l + r) >> 1;
  modify(id * 2, l, mid, ql, qr, val);
  modify(id * 2 + 1, mid + 1, r, ql, qr, val);
  seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int query(int id, int l, int r, int ql, int qr) {
  if (ql > r || qr < l)
    return 0;
  if (ql <= l && r <= qr)
    return seg[id];
  push(id, l, r);
  int mid = (l + r) >> 1;
  return query(id * 2, l, mid, ql, qr) + query(id * 2 + 1, mid + 1, r, ql, qr);
}
