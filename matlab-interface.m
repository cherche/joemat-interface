mex -setup cpp;
libName = "joemat";
libFile = "/Users/ryan/Documents/MATLAB/joemat-interface/bin/libjoemat.dylib";
headerFile = "/Users/ryan/Documents/MATLAB/joemat-interface/include/libjoemat.h";
clibgen.generateLibraryDefinition(headerFile, "Libraries", libFile, "PackageName", libName);
