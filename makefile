run: output
	./project2 $(file)

output: proj2.cpp graph.cpp fileParse.cpp header.h
	g++ proj2.cpp graph.cpp fileParse.cpp -o project2

