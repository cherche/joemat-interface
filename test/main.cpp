#include <stdio.h>
#include "../src/interface.h"

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

    const char* L5_1_string = "[0.25 1 0 0;0 0.25 0 0;0 0 0.25 0;0 0 0 -0.75]\n[0 1 0 0;0 0 1 0;0 0 0 0;0 0 0 0]\n[0 0 1 0;0 0 0 0;0 0 0 0;0 0 0 0]";
    const char* L5_2_string = "[0.25 0 0 0;0 0.25 0 1;0 0 -0.75 0;0 0 0 0.25]\n[0 1 0 0;0 0 0 0;0 0 0 0;0 0 0 0]\n[0 0 0 1;0 0 0 0;0 0 0 0;0 0 0 0]";
    const char* L5_4_string = "[0 1 0 0;0 0 1 0;0 0 0 1;0 0 0 0]\n[0 0 a 0;0 0 0 a+1;0 0 0 0;0 0 0 0]\n[0 0 0 1;0 0 0 0;0 0 0 0;0 0 0 0]";
    const char* L5_5_string = "[0 1 0 0;0 0 0 0;0 0 0 1;0 0 0 0]\n[0 0 a 0;0 0 0 a+1;0 0 0 0;0 0 0 0]\n[0 0 0 1;0 0 0 0;0 0 0 0;0 0 0 0]";
    const char* generatorsString = L5_4_string;
    cout << "Generators:" << endl << generatorsString << endl;
    setUp(generatorsString);

    testDim();
    testBasis();
    testNormalizer();
    testCentralizer();

    return 0;
}
