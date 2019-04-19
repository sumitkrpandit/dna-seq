all:
	g++ -o bin/seq src/config.cpp src/utils.cpp src/simulation.cpp src/levensthein.cpp src/basic_graph.cpp src/main.cpp -std=c++17
	g++ -o bin/gen src/generator.cpp -std=c++17

