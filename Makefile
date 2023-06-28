UNAME_S := $(shell uname -s)
# Need to compile for x86_64 because MATLAB runs on it ...
# Otherwise, MATLAB says that it's not compatible because
# it's a 32-bit library (which is at least half right, haha).
ifeq ($(UNAME_S),Darwin)
	CFLAGS := -std=c++17 -arch x86_64
	LDFLAGS := -Wl,-v
	LIBFILE := bin/libjoemat.dylib
else
	CFLAGS := -std=c++17
	LDFLAGS := -Wl,-Bstatic
	LIBFILE := bin/libjoemat.so
endif

# SOURCES=$(src/)

#bin/static/%.o: src/%.cpp
#	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

# Static library doesn't seem to work ...
# so we'll be stuck with shared.
# However, this might not be too big a deal since
# we can still statically link stuff into it.
# (No idea how that works.)
$(LIBFILE): bin/joemat/libjoemat.a bin/compat.o bin/interface.o
#	ar rcs $@ $^
	$(CXX) $(CFLAGS) -shared bin/compat.o bin/interface.o -o $@ $(LDFLAGS) -Lbin/joemat -ljoemat -lginac -lcln -lgmp
# Note that macOS's `ld` has no -Bstatic option,
# so the only way to force a static link is by
# removing all the shared versions of the libraries,
# wherever they might appear in the PATH

bin/compat.o: src/compat.cpp
	$(CXX) $(CFLAGS) -fPIC -c -o $@ $^ $(LDFLAGS)

bin/interface.o: src/interface.cpp
	$(CXX) $(CFLAGS) -fPIC -c -o $@ $^ $(LDFLAGS)

src/joemat/out/library.a:
	make -C src/joemat

bin/joemat/libjoemat.a: src/joemat/out/library.a
	cp $^ $@

bin/main.o: test/main.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

bin/test: bin/main.o
	$(CXX) $(CFLAGS) -Lbin -ljoemat -o $@ $^

test: $(LIBFILE) bin/main.o bin/test
all: bin/joemat/libjoemat.a bin/compat.o $(LIBFILE)
clean:
	rm -r bin/*
	mkdir bin/joemat
