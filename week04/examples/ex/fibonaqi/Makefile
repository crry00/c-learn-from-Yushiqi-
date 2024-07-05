CXX=g++
TARGET=fib
SRC=$(wildcard ./*.cpp)#wildcard 通配符
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CXXFLAGS=-c -Wall

$(TARGET):$(OBJ)
	$(CXX) -o $@ $^

%.o:%.cpp
	$(CXX)  $< $(CXXFLAGS) 

.PHONY:clean
clean:
	rm -f *.o $(TARGET) $(OBJ)
#-f 强制删除
