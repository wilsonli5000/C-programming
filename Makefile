#for the BigInteger project

main.o: main.cpp BigInteger.h
	g++ -c $<

BigInteger.o: BigInteger.cpp BigInteger.h
	g++ -c $<
	
main: main.o BigInteger.o
	g++ $^ -o $@

clean: main.o BigInteger.o
	rm $^

.PHONY: main clean


