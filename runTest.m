addpath('./joemat')
addpath('./mlfunctions')

generatorsString = "[1 0;0 0]" + newline + "[-1 0;0 0]";
clib.joemat.setLieAlgebra(generatorsString);
dim = clib.joemat.getLieAlgebraDim();
basisString = clib.joemat.getLieAlgebraBasis();
disp("Generators:" + newline + generatorsString);
disp("Dimension: " + dim);
disp("Basis: " + newline + basisString);


generators = {[0 1;0 0], [0 0;1 0]}
disp("Generators:" + newline + matrixSeqToString(generators))
disp("Dimension: " + getLieAlgebraDim(generators))
disp("Basis: " + newline + matrixSeqToString(getLieAlgebraBasis(generators)))
