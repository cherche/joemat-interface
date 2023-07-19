#ifndef COMPAT_H
#define COMPAT_H

#include <vector>
#include <list>
#include <sstream>
using std::vector;
using std::list;
using std::string;

#include "../lib/joemat/src/headers/lie_algebra.h"

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

/**
 * Returns a GiNaC matrix from its string representation
 *
 * A string representation should conform to the following:
 * - at the start and end of the string are '[' and ']'
 *   (a pair of square brackets), respectively.
 * - between every two rows is one semicolon ';'
 * - between every two entries in the same row is one comma ',',
 *   or between every two entries in the same row is one space ' '
 *   (it is not acceptable to mix commas and space for the same row)
 *
 * This specification closely resembles MATLAB matrix syntax;
 * however; there is limited tolerance for extraneous whitespace
 * (e.g., a string with spaces after the semicolons
 * should still be accepted) but no promise is made.
 *
 * @param str A string representation of a matrix
 * @return The GiNaC matrix represented by <str>
 */
g::matrix toMatrix(string str);
// Example of acceptable input: "[1 0;0 1]"
// Another example of acceptable input: "[1,0;0 1]"

/**
 * Returns the string representation of a GiNaC matrix
 * 
 * The returned string representation conforms to the
 * same standard required of the input to <toMatrix>.
 *
 * @param a A GiNaC matrix
 * @returns A string representation of <a>
 */
string toString(g::matrix a);

/**
 * Returns a vector of GiNaC matrices based on their string representations
 *
 * A string representation of a vector of GiNaC matrices
 * (a "matrix sequence") is one which is the concatenation
 * of the string representations of each of its matrices
 * (see <toMatrix>),  * joined by newlines '\n' between
 * each pair of string representations.
 *
 * There is limited tolerance for extraneous whitespace
 * and newlines (e.g., there may be two newlines between
 * successive matrices) but no promise is made.
 *
 * @param str A string representation of a matrix sequence
 * @return The vector of GiNaC matrices represented by <str>
 */
vector<g::matrix> toMatrixSequence(string str);

/**
 * Returns the string representation of a vector of GiNaC matrices
 * 
 * The returned string representation conforms to the
 * same standard required of the input to <toMatrixSeq>.
 *
 * @param seq A vector of GiNaC matrices
 * @returns A string representation of <seq>
 */
string toString(vector<g::matrix> b);

/**
 * Returns the Lie algebra generated by a string representation
 * of a vector of GiNaC matrices
 *
 * See <toMatrixSeq>
 *
 * @param str A string representation of a matrix sequence
 * @return The Lie algebra represented by <str>
 */
lie_algebra* toLieAlgebra(string str);

/**
 * Returns the string representation of a Lie algebra
 * 
 * The returned string representation conforms to the
 * same standard required of the input to <toLieAlgebra>.
 *
 * @param l A Lie algebra
 * @returns A string representation of <l>
 */
string toString(lie_algebra* l);

/**
 * Returns a vector of Lie algebras based on their string representations
 *
 * A string representation of a vector of Lie algebras
 * is one which is the concatenation of the string
 * representations of each of its Lie algebras
 * (see <toLieAlgebra>), joined by "\n@\n" between
 * each pair of string representations.
 *
 * There is limited tolerance for extraneous whitespace
 * and newlines (e.g., two Lie algebra string representations
 * might be  * separated by "\n\n@\n") but no promise is made.
 *
 * @param str A string representation of a Lie algebra
 * @return The vector of Lie algebras represented by <str>
 */
vector<lie_algebra*> toLieAlgebraSequence(string str);

/**
 * Returns the string representation of a vector of Lie algebras
 * 
 * The returned string representation conforms to the
 * same standard required of the input to <toLieAlgebraSequence>.
 *
 * @param seq A vector of Lie algebras
 * @returns A string representation of <seq>
 */
string toString(vector<lie_algebra*> seq);

g::matrix toMatrix(const char* s);
const char* toCharArray(g::matrix a);
vector<g::matrix> toMatrixSequence(const char* s);
const char* toCharArray(vector<g::matrix> b);
lie_algebra* toLieAlgebra(const char* s);
const char* toCharArray(lie_algebra* l);
vector<lie_algebra*> toLieAlgebraSequence(const char* s);
const char* toCharArray(vector<lie_algebra*> b);

const char* toCharArray(string str);
// the following is already handled by C++
// string toString(const char*);
string join(vector<string> strings, string joiner);
vector<string> split(string target, string delimiter);
string replace(string target, string oldseg, string newseg);

void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);
void compress_spaces_and_newlines(string &s);

#endif // COMPAT_H
