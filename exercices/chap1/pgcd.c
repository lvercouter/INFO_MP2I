int pgcd(int a, int b) {
  int x = a, y = b;
  while (y != 0) {
    int tmp = y;
    y = x % y;
    x = tmp;
  }
  return x;
}
