#pragma once
#include <set>

int GetError(int argc, char* argv[], int& n);
int SumOfDigits(int n);
void PrintSets(std::set<int> const& divSumSet, std::set<int> const& evenSumSet);
std::set<int> CreateDivSumSet(int n);
std::set<int> CreateEvenSumSet(int n);
std::set<int> CrossSet(std::set<int> const& divSumSet, std::set<int> const& evenSumSet);