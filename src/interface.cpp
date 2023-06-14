#include "interface.h"

lie_algebra* storedLieAlgebra;
lie_algebra* workingLieAlgebra;

void setLieAlgebra(const char* s) {
    storedLieAlgebra = toLieAlgebra(s);
    workingLieAlgebra = storedLieAlgebra;
}

int getLieAlgebraDim() {
    return workingLieAlgebra->get_dim();
}

const char* getLieAlgebraBasis() {
    vector<g::matrix> basis = workingLieAlgebra->get_basis();
    return toCharArray(basis);
}

int getLieAlgebraDim(const char* s) {
    workingLieAlgebra = toLieAlgebra(s);
    int dim = getLieAlgebraDim();
    workingLieAlgebra = storedLieAlgebra;
    return dim;
}

const char* getLieAlgebraBasis(const char* s) {
    workingLieAlgebra = toLieAlgebra(s);
    const char* result = getLieAlgebraBasis();
    workingLieAlgebra = storedLieAlgebra;
    return result;
}

int getMatrixRank(const char* s) {
    g::matrix x = toMatrix(s);
    int r = lin_alg::rank(x);
    return r;
}

int getZero() {
    return 0;
}
