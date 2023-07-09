# Might need to play around with the Windows flags
ifeq ($(OS),Windows_NT)
	CFLAGS := -std=c++17
	LDFLAGS := -Wl,-Bstatic
	STATIC_LIBFILE := bin/libjoemat.lib
	SHARED_LIBFILE := bin/libjoemat.dll
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CFLAGS := -std=c++17
		LDFLAGS := -Wl,-Bstatic
		STATIC_LIBFILE := bin/libjoemat.a
		SHARED_LIBFILE := bin/libjoemat.so
	endif
# Need to compile for x86_64 because MATLAB runs on it ...
# Otherwise, MATLAB says that it's not compatible because
# it's a 32-bit library (which is at least half right, haha).
	ifeq ($(UNAME_S),Darwin)
		CFLAGS := -std=c++17 -arch x86_64
		LDFLAGS := -Wl,-v
		STATIC_LIBFILE := bin/libjoemat.a
		SHARED_LIBFILE := bin/libjoemat.dylib
	endif
endif


# Note that macOS's `ld` has no -Bstatic option,
# so the only way to force a static link is by
# removing all the shared versions of the libraries,
# wherever they might appear in the PATH
$(SHARED_LIBFILE): bin/shared/interface.o bin/shared/compat.o bin/shared/libjoemat.a
	$(CXX) $(CFLAGS) -shared bin/shared/interface.o bin/shared/compat.o -o $@ $(LDFLAGS) -Lbin/shared -ljoemat -lginac -lcln -lgmp

bin/shared/interface.o: src/interface.cpp
	$(CXX) $(CFLAGS) -fPIC -c -o $@ $^ $(LDFLAGS)

bin/shared/compat.o: src/compat.cpp
	$(CXX) $(CFLAGS) -fPIC -c -o $@ $^ $(LDFLAGS)

bin/shared/libjoemat.a:
	make -C src/joemat
	cp src/joemat/out/library.a bin/shared/libjoemat.a

bin/mainshared.o: test/main.cpp
	$(CXX) $(CFLAGS) -fPIC -c -o $@ $^ $(LDFLAGS)

bin/testshared: bin/mainshared.o
	$(CXX) -o $@ $(CFLAGS) -Lbin -ljoemat $^


$(STATIC_LIBFILE): bin/static/interface.o bin/static/compat.o bin/static/lie_algebra.o bin/static/lin_alg.o bin/static/utils.o
	ar rcs $@ $^

bin/static/interface.o: src/interface.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/static/compat.o: src/compat.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/static/lie_algebra.o:
	make -C src/joemat
	cp src/joemat/out/lie_algebra.o bin/static

bin/static/lin_alg.o:
	make -C src/joemat
	cp src/joemat/out/lin_alg.o bin/static

bin/static/utils.o:
	make -C src/joemat
	cp src/joemat/out/utils.o bin/static

bin/mainstatic.o: test/main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/teststatic: bin/mainstatic.o
	$(CXX) -o $@ $(CFLAGS) -Lbin -ljoemat -lginac -lcln -lgmp $^

static: $(STATIC_LIBFILE)
shared: $(SHARED_LIBFILE)
teststatic: $(STATIC_LIBFILE) bin/teststatic
testshared: $(SHARED_LIBFILE) bin/testshared
all: $(STATIC_LIBFILE) $(SHARED_LIBFILE) teststatic testshared

clean:
	rm -r bin/*
	mkdir -p bin/static
	mkdir -p bin/shared
