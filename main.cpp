#include "make_graph.h"
#include "greedy_order.h"
#include "win_prob.h"
#include "count_violations.h"
#include "position_move.h"
#include <iostream>
using namespace std;

int main()
{
  makeGraph();
  vector<int> go_result = greedyOrder();
  vector<int> wp_result = winProb();
  positionMove(go_result, "GO");
  positionMove(wp_result, "WP");
}