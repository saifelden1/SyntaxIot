# Compilers & Flags
CC ?= gcc
CXX ?= g++
CFLAGS ?= -Wall -Wextra -O2
CXXFLAGS ?= -Wall -Wextra -O2

# Extract goals ending in .c or .cpp
C_GOALS := $(filter %.c,$(MAKECMDGOALS))
CPP_GOALS := $(filter %.cpp,$(MAKECMDGOALS))

.PHONY: all clean run $(C_GOALS) $(CPP_GOALS)

all: app

# Compile file.c when user runs 'make file.c'
ifneq ($(C_GOALS),)
$(C_GOALS):
	$(CC) $(CFLAGS) $@ -o $(basename $@)
endif

# Compile file.cpp when user runs 'make file.cpp'
ifneq ($(CPP_GOALS),)
$(CPP_GOALS):
	$(CXX) $(CXXFLAGS) $@ -o $(basename $@)
endif

# Compile file.c when user runs 'make file'
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Compile file.cpp when user runs 'make file'
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean built executables
clean:
	rm -f *.o *.exe app
