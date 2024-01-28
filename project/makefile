output: main.o Option.o VanillaOption.o CallOption.o PutOption.o BlackScholesPricer.o DigitalOption.o DigitalCallOption.o DigitalPutOption.o CRRPricer.o AsianCallOption.o AsianPutOption.o AsianOption.o BlackScholesMCPricer.o MT.o AmericanOption.o AmericanPutOption.o AmericanCallOption.o
	g++ main.o Option.o VanillaOption.o CallOption.o PutOption.o BlackScholesPricer.o DigitalOption.o DigitalCallOption.o DigitalPutOption.o CRRPricer.o AsianCallOption.o AsianPutOption.o AsianOption.o BlackScholesMCPricer.o MT.o AmericanOption.o AmericanPutOption.o AmericanCallOption.o -o output -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Option.o: Option.cpp Option.h
	g++ -c Option.cpp -std=c++11

VanillaOption.o: VanillaOption.cpp VanillaOption.h
	g++ -c VanillaOption.cpp -std=c++11

CallOption.o: CallOption.cpp CallOption.h
	g++ -c CallOption.cpp -std=c++11

PutOption.o: PutOption.cpp PutOption.h
	g++ -c PutOption.cpp -std=c++11

BlackScholesPricer.o: BlackScholesPricer.cpp BlackScholesPricer.h
	g++ -c BlackScholesPricer.cpp -std=c++11

DigitalOption.o: DigitalOption.cpp DigitalOption.h
	g++ -c DigitalOption.cpp -std=c++11

DigitalCallOption.o: DigitalCallOption.cpp DigitalCallOption.h
	g++ -c DigitalCallOption.cpp -std=c++11

DigitalPutOption.o: DigitalPutOption.cpp DigitalPutOption.h
	g++ -c DigitalPutOption.cpp -std=c++11

CRRPricer.o: CRRPricer.cpp CRRPricer.h
	g++ -c CRRPricer.cpp -std=c++11

AsianCallOption.o: AsianCallOption.cpp AsianCallOption.h
	g++ -c AsianCallOption.cpp -std=c++11

AsianPutOption.o: AsianPutOption.cpp AsianPutOption.h
	g++ -c AsianPutOption.cpp -std=c++11

AsianOption.o: AsianOption.cpp AsianOption.h
	g++ -c AsianOption.cpp -std=c++11

BlackScholesMCPricer.o: BlackScholesMCPricer.cpp BlackScholesMCPricer.h
	g++ -c BlackScholesMCPricer.cpp -std=c++11

MT.o: MT.cpp MT.h
	g++ -c MT.cpp -std=c++11

AmericanOption.o: AmericanOption.cpp AmericanOption.h
	g++ -c AmericanOption.cpp -std=c++11

AmericanPutOption.o : AmericanPutOption.cpp AmericanPutOption.h
	g++ -c AmericanPutOption.cpp -std=c++11

AmericanCallOption.o: AmericanCallOption.cpp AmericanCallOption.h
	g++ -c AmericanCallOption.cpp -std=c++11