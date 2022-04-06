VPATH := ../include
CC := g++
OBJS := main.o BinaryHeap.o BinomialHeap.o FibHeap.o LeftistHeap.o SkewHeap.o Dijkstra.o
INCLUDEFILE :=  BinaryHeap.h BinomialHeap.h FibHeap.h LeftistHeap.h SkewHeap.h Dijkstra.h HeapElement.h
OUTDIR := ../out

test: $(OBJS)
	$(CC) $(OBJS) -o $(OUTDIR)/$@ 

main.o :main.cpp $(INCLUDEFILE)
	$(CC) -c main.cpp 

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h 
	$(CC) -c BinaryHeap.cpp

BinomialHeap.o: BinomialHeap.cpp BinomialHeap.h
	$(CC) -c BinomialHeap.cpp

FibHeap.o: FibHeap.cpp FibHeap.h 
	$(CC) -c FibHeap.cpp

LeftistHeap.o: LeftistHeap.cpp LeftistHeap.h
	$(CC) -c LeftistHeap.cpp

SkewHeap.o: SkewHeap.cpp SkewHeap.h
	$(CC) -c SkewHeap.cpp

Dijkstra.o: Dijkstra.cpp Dijkstra.h
	$(CC) -c Dijkstra.cpp

clean:
	del $(OBJS)

delete:
	del *.exe