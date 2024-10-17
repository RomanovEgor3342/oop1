CXX = g++

CXXFLAGS = -std=c++11 -Iincludes -mconsole


SRC_DIR = classes
INCLUDES_DIR = includes

SRCS = $(wildcard main.cpp $(SRC_DIR)/*.cpp)

OBJS = $(SRCS:.cpp=.o)

TARGET = sb

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o main.o $(TARGET)

