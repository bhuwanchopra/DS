CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -std=c++11 -I../gtest/include -I.

OBJS = BitVector.o BitVectorTest.o gtest-all.o

LIBS = -lpthread

TARGET = BitVector

GTEST_DIR = ../gtest

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

gtest-all.o:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

BitVector.o:	BitVector.h

BitVectorTest.o:	BitVector.h

all:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
