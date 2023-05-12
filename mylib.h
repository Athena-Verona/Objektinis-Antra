#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <random>
#include <stdexcept>
#include <chrono>
#include <map>
#include <filesystem>

using std::stof;
using std::stoi;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::copy;
using std::sort;
using std::fixed;
using std::vector;
using std::swap;
using std::runtime_error;
using std::map;
using std::mt19937;


using hrClock = std::chrono::high_resolution_clock; 
typedef std::uniform_int_distribution<int>  int_distribution;