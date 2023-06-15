#include <stdio.h>
#include "interface.h"

using std::cout;
using std::endl;

void setUp(const char* generatorsString) {
    setLieAlgebra(generatorsString);
}

void testDim() {
    int dim = getLieAlgebraDim();
    cout << "Dimension: " << dim << endl;
}

void testBasis() {
    const char* basisString = getLieAlgebraBasis();
    cout << "Basis: " << endl << basisString << endl;
}

void testNormalizer() {
    const char* normalizerString = getLieAlgebraNormalizer();
    cout << "Normalizer:" << endl << normalizerString << endl;
}

void testCentralizer() {
    const char* centralizerString = getLieAlgebraCentralizer();
    cout << "Centralizer:" << endl << centralizerString << endl;
}

int main(int argc, char* argv[]) {
    // const char* s = "[1 0 0 0;0 1 0 0;0 0 1 0;0 0 0 0]";
    // int rank = getMatrixRank(s);
    // cout << "Matrix: " << s << endl;
    // cout << "Rank: " << rank << endl;

    // const char* generatorsString = "[1 0;0 0]\n[-1 0;0 0]";
    // int dim = getLieAlgebraDim(generatorsString);
    // const char* basisString = getLieAlgebraBasis(generatorsString);

    const char* generatorsString = "[1 0;0 0]\n[-1 0;0 0]";
    cout << "Generators:" << endl << generatorsString << endl;
    setUp(generatorsString);

    testDim();
    testBasis();
    testNormalizer();
    testCentralizer();

    return 0;
}
