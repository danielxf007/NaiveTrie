EXE = app

all: $(EXE)
	@echo Build complete 

$(EXE): trie.cpp main.cpp
	g++ main.cpp trie.cpp -o $(EXE)

clean:
	rm -f $(EXE)