#include "random_order.h"
#include "count_violations.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

extern int n;

vector<int> randomOrder() {
  srand(unsigned(time(0)));

  vector<int> result(n);
  for(int i=0; i<result.size(); i++) {
    result[i] = i+1;
  }

  random_shuffle(result.begin(), result.end());

  int cnt = count_violations(result);

  cout << "RANDOM " << cnt << '\n';

  return result;
}