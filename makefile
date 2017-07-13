#File names
EXECUTABLE := TextRPG.exe

#Just add the filename without file descriptor here
FIL := main action item character stat

#File Directories
SRC_DIR := src/
OBJ_DIR := build/
DES_DIR := test/
INC_DIR := include/

#Compiler
CXX:= g++

#Compiler Flags
CXXFLAGS := -I$(INC_DIR) -Wall -std=c++11

#Add the necessary path information and file descriptors
SRC := $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FIL)))
OBJ := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FIL)))
EXE_FIL := $(addprefix $(DES_DIR), $(EXECUTABLE))

DEP := $(OBJ:%.o=%.d)

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) 
	@echo Creating executable $@
	@$(CXX) $(OBJ) $(CXXFLAGS)  -o $(EXE_FIL)

-include $(DEP)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo Compiling $(notdir $<)
	@$(CXX) -MMD -c $(CXXFLAGS) -o $@ $<

clean:
	@echo Removing $(notdir $(OBJ) $(EXE_FIL))
	@rm -f $(EXE_FIL) $(OBJ) $(DEP)
