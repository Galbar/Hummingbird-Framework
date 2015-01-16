CC        := g++-4.8
ARCH      := $(shell getconf LONG_BIT)

IDIR      := HEADERS
SDIR      := SOURCES
BDIR      := BUILD
DEPS_IDIR := DEPENDENCIES/INCLUDE

CFLAGS_32 := -LDEPENDENCIES/lib/x86
CFLAGS_64 := -LDEPENDENCIES/lib/x86_64
CFLAGS    := -I$(IDIR) -I$(DEPS_IDIR) -L$(CFLAGS_$(ARCH)) -std=c++11 -Wall
LIBS      := -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window

EXEC      := exec

SOURCES   := $(shell find $(SDIR) -name '*.cpp')
INCLUDES  := $(shell find $(IDIR) -name '*.h') $(shell find $(IDIR) -name '*.hpp')

OBJ       := $(addprefix $(BDIR)/,$(SOURCES:$(SDIR)/%.cpp=%.o))

all: $(BDIR)/$(EXEC)

$(BDIR)/%.o: $(SDIR)/%.cpp $(DEPS) $(BDIR)/.done
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/.done:
	mkdir $(BDIR)
	echo "file for checking if $(BDIR) exists" >$(BDIR)/.done

$(BDIR)/$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean run

run: all
	$(BDIR)/$(EXEC)

clean:
	rm -rf $(BDIR) *~ $(IDIR)/*~ $(SDIR)/*~
