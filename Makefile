.SUFFIXES : .cpp .o
CXX = g++

CPPFLAGS = -g  # Removed -std=c++11 flag

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = a.out

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS)

clean :
	rm -rf $(OBJS) $(TARGET)

