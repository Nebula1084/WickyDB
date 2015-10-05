main:WickyEngine ResultSet Parser Expression Optimizer Plan Evaluator
	g++ -c src/main.cpp -Iinclude
	g++ -o wickydb main.o WickyEngine.o ResultSet.o Parser.o Expression.o Optimizer.o Plan.o Evaluator.o 
WickyEngine:
	g++ -c src/WickyEngine.cpp -Iinclude
ResultSet:
	g++ -c src/Entity/ResultSet.cpp -Iinclude
Parser:
	g++ -c src/Parser/Parser.cpp -Iinclude
Expression:
	g++ -c src/Entity/Expression.cpp -Iinclude
Optimizer:
	g++ -c src/Optimizer/Optimizer.cpp -Iinclude
Plan:
	g++ -c src/Entity/Plan.cpp -Iinclude
Evaluator:
	g++ -c src/Evaluator/Evaluator.cpp -Iinclude