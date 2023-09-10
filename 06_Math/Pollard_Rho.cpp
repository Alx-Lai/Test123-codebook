// n is prime -> miller_rabin
// qpow need int128
ll Pollard_Rho(ll x) {
  ll s = 0, t = 0;
  ll c = (ll)rand() % (x - 1) + 1;
  int step = 0, goal = 1;
  ll val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {
    for (step = 1; step <= goal; ++step) {
      t = (qpow(t, 2, x) + c) % x;
      val = (__int128)val * abs(t - s) % x;
      if ((step % 127) == 0) {
        ll d = __gcd(val, x);
        if (d > 1) return d;
      }
    }
    ll d = __gcd(val, x);
    if (d > 1) return d;
  }
}