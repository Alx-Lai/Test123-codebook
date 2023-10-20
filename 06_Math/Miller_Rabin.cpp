// n < 4,759,123,141      3 : 2, 7, 61
// n < 1,122,004,669,633  4 : 2, 13, 23, 1662803
// n < 3,474,749,660,383  6 : primes <= 13
// n < 2^64               7 : primes <= 23
bool Miller_Rabin(ll a, ll n) {
  if ((a = a % n) == 0) return 1;
  if ((n & 1) ^ 1) return n == 2;
  ll tmp = (n - 1) / ((n - 1) & (1 - n));
  ll t = __lg((n - 1) & (1 - n));
  ll x = qpow(a, tmp, n);
  if (x == 1 || x == n - 1) return 1;
  while (--t) {
    if ((x = qpow(x, 2, n)) == n - 1) return 1;
  }
  return 0;
}
bool Miller_rabin(ll n) {
  static const ll p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  for (int i = 0; i < 9; i++) {
    if (!miller_rabin(p[i], n)) return false;
  }
  // is Prime
  return true;
}
