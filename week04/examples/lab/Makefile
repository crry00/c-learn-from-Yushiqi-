# ## VERSION 1
# hello: main.cpp printhello.cpp  factorial.cpp
# 	g++ -o hello main.cpp printhello.cpp  factorial.cpp

# ## VERSION 2
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o


# $(TARGET): $(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)

# main.o: main.cpp
# 	$(CXX) -c main.cpp

# printhello.o: printhello.cpp
# 	$(CXX) -c printhello.cpp

# factorial.o: factorial.cpp
# 	$(CXX) -c factorial.cpp


# ## VERSION 3
# CXX = g++
# TARGET = hello
# OBJ = main.o printhello.o factorial.o

# CXXFLAGS = -c -Wall

# $(TARGET): $(OBJ)
# 	$(CXX) -o $@ $^
# #$^ like the OBJ(all),$< just the first one param
# #$@ target 

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) $< -o $@
# #This is a model rule, which indicates that all 
# #the .o objects depend on the .cpp files

# .PHONY: clean
# clean:
# 	rm -f *.o $(TARGET)
# #通过make clean 可一键删除！！
# .PHONY: cleano
# cleano:
# 	rm -f *.o

## VERSION 4
# CXX = g++
# TARGET = hello
# SRC = $(wildcard *.cpp)
# OBJ = $(patsubst %.cpp, %.o, $(SRC))

# CXXFLAGS = -c -Wall

# $(TARGET): $(OBJ)
# 	$(CXX) -o $@ $^

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) $< -o $@

# .PHONY: clean
# clean:
# 	rm -f *.o $(TARGET)


CXX=g++
#指定编译器
TARGET=hello
#指定目标变量
SRC=$(wildcard ./*.cpp)
#指定源文件变量
OBJ=$(patsubst %.cpp,%.o,$(SRC))
#指定目标文件变量
# target:
# 	@echo $(SRC)
# 	@echo $(OBJ)

CXXFLAGS= -c -Wall
#指定编译参数
$(TARGET):$(OBJ)
	$(CXX) -o $@ $(OBJ)
#指定顶层链接编译
%.o:%.cpp
	$(CXX) $< &(CXXFLAGS)
#指定底层源文件编译


.PHONY:clean
clean:
	rm -r  $(OBJ) $(TARGET)
#编写清理命令


