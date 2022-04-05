VPATH := ../include
CC := g++
OBJS := main.o AvlTree.o BST.o RedBlackTree.o SplayTree.o
INCLUDEFILE := AvlTree.h BST.h RedBlackTree.h SplayTree.h
OUTDIR := ../out

test: $(OBJS)
	$(CC) $(OBJS) -o $(OUTDIR)/$@ 

main.o :main.cpp $(INCLUDEFILE)
	$(CC) -c main.cpp 

AvlTree.o: AvlTree.c AvlTree.h 
	$(CC) -c AvlTree.c

BST.o: BST.c BST.h
	$(CC) -c BST.c

RedBlackTree.o: RedBlackTree.c RedBlackTree.h 
	$(CC) -c RedBlackTree.c

SplayTree.o: SplayTree.c SplayTree.h
	$(CC) -c SplayTree.c

clean:
	del $(OBJS)