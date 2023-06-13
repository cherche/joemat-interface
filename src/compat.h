#ifndef COMPAT_H
#define COMPAT_H

#include <vector>
#include <list>
#include <sstream>
using std::vector;
using std::list;
using std::string;

#include "joemat/src/headers/lie_algebra.h"

#include <ginac/matrix.h>
#include <ginac/ex.h>
#include <ginac/mul.h>
#include <ginac/add.h>
#include <ginac/parser.h>
#include <ginac/operators.h>
using GiNaC::parser;
using GiNaC::lst;
using GiNaC::ex;
namespace g = GiNaC;

g::matrix toMatrix(const char* s);
const char* toCharArray(g::matrix a);
g::matrix toMatrix(string s);
string toString(g::matrix a);

lie_algebra* toLieAlgebra(const char* s);
const char* toCharArray(lie_algebra* l);
lie_algebra* toLieAlgebra(string str);
string toString(lie_algebra* l);

vector<g::matrix> toMatrixSequence(const char* s);
const char* toCharArray(vector<g::matrix> b);
vector<g::matrix> toMatrixSequence(string str);
string toString(vector<g::matrix> b);

const char* toCharArray(string str);
// the following is already handled by C++
// string toString(const char*);
string join(vector<string> strings, string joiner);
vector<string> split(string target, string delimiter);

#endif // COMPAT_H
