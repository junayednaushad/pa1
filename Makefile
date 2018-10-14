blockchainTest: blockchain.o blockchainTest.o
	g++ -g blockchain.o blockchainTest.o -o blockchainTest

blockchainTest.o: blockchainTest.cpp blockchain.h
	g++ -g blockchainTest.cpp -c

blockchain.o: blockchain.h blockchain.cpp
	g++ -g blockchain.cpp -c

clean:
	rm blockchainTest blockchain.o blockchainTest.o
