#include <stdio.h>
#include "interface.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    const char* s = "[1 0 0 0;0 1 0 0;0 0 1 0;0 0 0 0]";
    int rank = getMatrixRank(s);
    cout << "Matrix: " << s << endl;
    cout << "Rank: " << rank << endl;

    // const char* generatorsString = "[1 0;0 0]\n[-1 0;0 0]";
    // int dim = getLieAlgebraDim(generatorsString);
    // const char* basisString = getLieAlgebraBasis(generatorsString);
    const char* generatorsString = "[1 0;0 0]\n[-1 0;0 0]";
    setLieAlgebra(generatorsString);
    int dim = getLieAlgebraDim();
    const char* basisString = getLieAlgebraBasis();
    cout << "Generators:" << endl << generatorsString << endl;
    cout << "Dimension: " << dim << endl;
    cout << "Basis: " << endl << basisString << endl;

    return 0;
}
