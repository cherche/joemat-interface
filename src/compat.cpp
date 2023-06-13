#include "compat.h"

g::matrix toMatrix(const char* s) {
    string str(s);
    return toMatrix(str);
}

// We assume the input is something like "[1 0; 0 1]"
// (exactly that much whitespace, no more, no less)
g::matrix toMatrix(string s) {
    string meat = s.substr(1, s.size() - 2);
    //std::cout << meat << std::endl;
    vector<string> rows = split(meat, ";");

    // Make it into a 2d string vector ....
    // Can probably combine this with the next step.
    vector<vector<string>> mat = {};
    for (int i = 0; i < rows.size(); i++) {
        string rowString = rows[i];
        //std::cout << rowString << std::endl;
        vector<string> row = split(rowString, " ");
        mat.push_back(row);
    }

    // TODO: Store symbols in a table
    parser reader;
    int r = mat.size();
    int c = mat[0].size();
    list<ex> els = {};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            els.push_back(reader(mat[i][j]));
        }
    }
    lst myLst(els);

    g::matrix result = g::matrix(r, c, myLst);

    return result;
}

const char* toCharArray(g::matrix a) {
    string str = toString(a);
    return toCharArray(str);
}

string toString(g::matrix a) {
    string result = "";
    for (int i = 0; i < a.rows(); i++) {
        if (i != 0) result += ";";
        for (int j = 0; j < a.cols(); j++) {
            if (j != 0) result += " ";
            std::ostringstream s;
            s << g::dflt << a(i, j);
            result += s.str();
        }
    }
    return "[" + result + "]";
}

lie_algebra* toLieAlgebra(const char* s) {
    string str(s);
    return toLieAlgebra(str);
}

const char* toCharArray(lie_algebra* l) {
    string str = toString(l);
    return toCharArray(str);
}

lie_algebra* toLieAlgebra(string str) {
    vector<g::matrix> generators = toMatrixSequence(str);
    lie_algebra* l = new lie_algebra(generators, false);
    return l;
}

string toString(lie_algebra* l) {
    vector<g::matrix> basis = l->get_basis();
    return toString(basis);
}

const char* toCharArray(string str) {
    // declaring character array (+1 for null terminator)
    char* result = new char[str.length() + 1];
    // copying the contents of the
    // string to char array
    strcpy(result, str.c_str());
    return result;
}

vector<g::matrix> toMatrixSequence(const char* s) {
    string str(s);
    return toMatrixSequence(str);
}

const char* toCharArray(vector<g::matrix> b) {
    string str = toString(b);
    return toCharArray(str);
}

vector<g::matrix> toMatrixSequence(string str) {
    vector<string> matrixStrings = split(str, "\n");

    vector<g::matrix> seq = vector<g::matrix>();
    for (int i = 0; i < matrixStrings.size(); i++) {
        g::matrix matrix = toMatrix(matrixStrings[i]);
        seq.push_back(matrix);
    }

    return seq;
}

string toString(vector<g::matrix> seq) {
    string seqString = "";
    for (int i = 0; i < seq.size(); i++) {
        if (i != 0) {
            seqString += "\n";
        }
        seqString += toString(seq[i]);
    }

    return seqString;
}

string join(vector<string> strings, string joiner) {
    string result = "";
    for (int i = 0; i < strings.size(); i++) {
        if (i != 0) {
            result += joiner;
        }
        result += strings[i];
    }
    return result;
}

vector<string> split(string target, string delimiter) {
    vector<string> components;
    if (!target.empty()) {
        size_t start = 0;
        do {
            const size_t index = target.find(delimiter, start);
            if (index == string::npos) {
                break;
            }
            const size_t length = index - start;
            components.push_back(target.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        components.push_back(target.substr(start));
    }

    return components;
}
