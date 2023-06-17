function mat = stringToMatrix(string)

% saves time to avoid unnecessary symbols
if hasSymbols(string)
    mat = str2sym(string)
else
    mat = str2num(string)
end

function val = hasSymbols(string)
    matches = regexp(string, "[a-zA-Z]")
    val = length(matches) > 0

