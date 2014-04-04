CXX = g++

CXXFLAGS = -O2 -g -Wall -fmessage-length=0 -fwhole-program -ffunction-sections -fdata-sections -std=c++11 -I../gtest/include -I.

OBJS = SingleLinkedList.o SingleLinkedListTest.o gtest-all.o

LIBS = -lpthread

TARGET = SingleLinkedList

GTEST_DIR = ../gtest

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

gtest-all.o:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc

SingleLinkedList.o:	SingleLinkedList.h

SingleLinkedListTraversal.o:	SingleLinkedList.h

SingleLinkedListTest.o: SingleLinkedList.h

all:
	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
