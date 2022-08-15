#pragma once

class WinProb
{
public:
  int v;
  double prob;
  WinProb(int v, double prob)
  {
    this->v = v;
    this->prob = prob;
  }
  friend bool operator<(const WinProb &wp1, const WinProb &wp2)
  {
    return wp1.prob < wp2.prob;
  }
};

void winProb();