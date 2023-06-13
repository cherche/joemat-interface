mex -setup cpp;
libName = "joemat";
libFile = "bin/libjoemat.dylib";
headerFile = "include/joemat.h";
clibgen.generateLibraryDefinition(headerFile, "Libraries", libFile, "PackageName", libName);
