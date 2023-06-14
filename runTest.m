addpath('./joemat')

% TODO
% create "compat" functions which produce string representations
% of ML matrices (or of column arrays of matrices in the case of,
% for instance, a list of generators for a Lie algebra)
% convert ML matrix list to be formatted like below
% [] around each matrix
% spaces separating elements in same row
% semicolons separating rows
% newlines separating matrices
% no additional characters (e.g., "[1 0; 0 0]" would be invalid)
% Note that MATLAB uses newline instead of \n
% ("\n" just produces the literal string consisting of backslash-n).
generatorsString = "[1 0;0 0]" + newline + "[-1 0;0 0]";

clib.joemat.setLieAlgebra(generatorsString);
dim = clib.joemat.getLieAlgebraDim();
basisString = clib.joemat.getLieAlgebraBasis();

% TODO: same thing but in reverse.
% turn string representations into ML matrices (or arrays of matrices)
% I think eval might work and work with symbols in the expected way.

% TODO
% possibly create a bunch of MATLAB functions which hide clib
% so users can just write something,
% e.g., getLieAlgebraBasis(ML matrix) -> column array of ML matrices,
% so that the user will not need to handle string conversions themselves

% TODO
% Hook everything into the old app.

disp("Generators:" + newline + generatorsString);
disp("Dimension: " + dim);
disp("Basis: " + newline + basisString);
