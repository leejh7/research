#include "make_graph.h"
#include "random_order.h"
#include "greedy_order.h"
#include "win_prob.h"
#include "count_violations.h"
#include "position_move.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  for(int i=1; i<=4; i+=2) {
    makeGraph(argv[i], argv[i+1]);
    vector<int> rand_result = randomOrder();
    vector<int> go_result = greedyOrder();
    vector<int> wp_result = winProb();
    positionMove(rand_result, "RANDOM");
    positionMove(go_result, "GO");
    positionMove(wp_result, "WP");
  }
}