sl-list_SRC=examples/sl-list.cpp

sl-list: TARGET=sl-list
sl-list: all

ifeq ($(shell echo "check_quotes"),"check_quotes")
	WINDOWS=yes
else
	WINDOWS=no
endif

ifeq ($(WINDOWS),yes)
	mkdir = mkdir $(subst /,\,$(1)) > nul 2>&1 || (exit 0)
	rm = $(wordlist 2,65535,$(foreach FILE,$(subst /,\,$(1)),& del $(FILE) > nul 2>&1)) || (exit 0)
    rmdir = rmdir $(subst /,\,$(1)) > nul 2>&1 || (exit 0)
    echo = echo $(1)
else
    mkdir = mkdir -p $(1)
    rm = rm $(1) > /dev/null 2>&1 || true
    rmdir = rmdir $(1) > /dev/null 2>&1 || true
    echo = echo "$(1)"
endif

CC=gcc
CXX=g++
RM=rm -f
CXXFLAGS=-g
LDFLAGS=-g
LDLIBS=

all:
	$(call mkdir,obj)
	$(call mkdir,bin)
	$(CXX) $(CXXFLAGS) -Iheader -o bin/$(TARGET) $($(TARGET)_SRC)
