a.out: compiler.o Variable.o Function.o
	g++ -std=c++17 Function.o compiler.o Variable.o -o a.out

compiler.o: compiler.cpp
	g++ -std=c++17 -c compiler.cpp

Variable.o: Variable.cpp 
	g++ -std=c++17 -c Variable.cpp

Function.o: Function.cpp
    g++ -std=c++17 -c Function.cpp

clean:
    rm *.o *.out
