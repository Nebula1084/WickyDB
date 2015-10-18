WICKYDB = wickydb
WICKY = main.o WickyEngine.o WickyPointer.o WickyFile.o WickyTuple.o Item.o ResultSet.o
BUFFER = BufferManager.o
CATALOG = CatalogManager.o
INDEX = Index.o Key.o IndexManager.o
INTERPRETOR = Parser.o Expression.o Optimizer.o Plan.o Evaluator.o  
ALOGRITHM = BTree.o
RECORD = RecordManager.o Table.o

WickyEngine: Buffer Catalog Index Interpretor Record Algorithm
	g++ -c src/main.cpp -Iinclude
	g++ -c src/WickyEngine.cpp -Iinclude
	g++ -c src/WickyPointer.cpp -Iinclude
	g++ -c src/WickyFile.cpp -Iinclude
	g++ -c src/WickyTuple.cpp -Iinclude
	g++ -c src/Item.cpp -Iinclude
	g++ -c src/ResultSet.cpp -Iinclude
	g++ -o $(WICKYDB) $(WICKY) $(BUFFER) $(CATALOG) $(INDEX) $(INTERPRETOR) $(ALOGRITHM) $(RECORD)
Buffer:
	g++ -c src/Buffer/BufferManager.cpp -Iinclude
Catalog:
	g++ -c src/Catalog/CatalogManager.cpp -Iinclude
Index:
	g++ -c src/Index/Index.cpp -Iinclude
	g++ -c src/Index/Key.cpp -Iinclude
	g++ -c src/Index/IndexManager.cpp -Iinclude
Interpretor:
	g++ -c src/Interpretor/Evaluator.cpp -Iinclude
	g++ -c src/Interpretor/Expression.cpp -Iinclude
	g++ -c src/Interpretor/Optimizer.cpp -Iinclude
	g++ -c src/Interpretor/Parser.cpp -Iinclude
	g++ -c src/Interpretor/Plan.cpp -Iinclude
Algorithm:
	g++ -c src/Algorithm/BTree.cpp -Iinclude
Record:
	g++ -c src/Record/RecordManager.cpp -Iinclude
	g++ -c src/Record/Table.cpp -Iinclude