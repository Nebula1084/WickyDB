main:WickyEngine ResultSet Parser Expression Optimizer Plan Evaluator
	g++ -c main.cpp
	g++ -o wickydb main.o WickyEngine.o ResultSet.o Parser.o Expression.o Optimizer.o Plan.o Evaluator.o 
WickyEngine:
	g++ -c WickyEngine.cpp
ResultSet:
	g++ -c ResultSet.cpp
Parser:
	g++ -c Parser.cpp
Expression:
	g++ -c Expression.cpp
Optimizer:
	g++ -c Optimizer.cpp
Plan:
	g++ -c Plan.cpp
Evaluator:
	g++ -c Evaluator.cpp