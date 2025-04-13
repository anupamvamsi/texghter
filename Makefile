CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -Werror

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp | $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

$(BIN):
	mkdir -p $(BIN)

clean:
	-rm $(BIN)/*
