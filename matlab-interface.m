mex -setup cpp;
libName = "joemat";
libFile = "bin/joemat.dylib";
headerFile = "include/libjoemat.h";
clibgen.generateLibraryDefinition(headerFile, "Libraries", libFile, "PackageName", libName);
