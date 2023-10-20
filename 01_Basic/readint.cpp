inline void r(int &x){
  x = 0;
  char c = getchar();
  while(c>'9'|| c<'0') c = getchar();
  while(c>='0'&&c<='9'){
    x = x*10+c-'0';
    c = getchar();
  }
}
