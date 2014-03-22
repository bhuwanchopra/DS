CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -I../gtest/include

OBJS = BitVector.o BitVectorTest.o 

LIBS = -L. -lgtest

TARGET = BitVector

GTEST_DIR = ../gtest
  
$(TARGET):	$(OBJS) compile-gtest lib-gtest
	$(CXX) $(CXXFLAGS) $(LIBS) -o $(TARGET) $(OBJS)
	
compile-gtest:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	
lib-gtest:
	ar -rv libgtest.a gtest-all.o

all:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)