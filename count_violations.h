#pragma once

#include <vector>

int count_violations(std::vector<int> &result);

int left_cnt(std::vector<int> &result, int start, int end);
int right_cnt(std::vector<int> &result, int start, int end);