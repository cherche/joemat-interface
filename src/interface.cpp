#include "interface.h"

int getMatrixRank(const char* s) {
    g::matrix x = toMatrix(s);
    int r = lin_alg::rank(x);
    return r;
}

int getLieAlgebraDim(const char* s) {
    lie_algebra* l = toLieAlgebra(s);
    int dim = l->get_dim();
    return dim;
}

const char* getLieAlgebraBasis(const char* s) {
    lie_algebra* l = toLieAlgebra(s);
    vector<g::matrix> basis = l->get_basis();
    return toCharArray(basis);
}

int getZero() {
    return 0;
}
