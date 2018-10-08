All: BST

BST: TNode.o BST.o Lab6.o
	g++ TNode.o BST.o Lab6.o -o BST

TNode.o: TNode.cpp
	g++ -c TNode.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

Lab6.o: Lab6.cpp
	g++ -c Lab6.cpp

clean:
	rm -rf *o BST
