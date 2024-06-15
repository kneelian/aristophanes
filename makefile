CXXFLAGS = -std=gnu++17
SOURCES  = ./src
LIBS     = ./include-libs
OUTDIR   = ./build

aristo: $(SOURCES)/main.cpp
	$(CXX) $(CXXFLAGS) -I$(LIBS) $(SOURCES)/*.cpp -o $(OUTDIR)/aristo

run:
	$(OUTDIR)/aristo

clean:
	rm -f $(OUTDIR)/*