CC = g++
CXXFLAGS = -Wall -O2
LDFLAGS = 

SRC_DIR = ./src
OBJ_DIR = ./obj

TARGET = main

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cc))
OBJS = $(SRCS:.cc=.o)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
		$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
		$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)


.PHONY : clean all
clean :
		rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)