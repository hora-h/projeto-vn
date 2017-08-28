#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter);

string find_inside(string src, char c1, char c2, string::size_type _inicio, string::size_type *_fim);

#endif /* _UTILS_H */

