#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <unistd.h>

#include "../../boilerplate.hpp"

// Kind of pointless, but I'll write a test for
// completionism's sake...

const int TESTS = 10;

int main() {
  for (int i = 0; i < TESTS; i++) {
    const int rand_ms = randint(50, 500);
    set_timer();
    usleep(rand_ms * 1000);
    assert(abs(elapsed() - rand_ms) < 10);
  }

  cerr << "Tests passed\n";

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}