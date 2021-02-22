#OBJS specifies which files to compile as part of the project
OBJS = main.o startup_utils.o
IDIR =/include
OBJS_DIR = .objs
CC = clang

_DEPS = startup_utils.h
DEPENDENCIES = $(game %,$(IDIR)/%,$(_DEPS))

$(OBJS_DIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS_COMMON)
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
CFLAGS_COMMON = -w
CFLAGS_DEBUG = $(CFLAGS_COMMON) -O0 -g -DDEBUG

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_ttf

# executable(s)
EXES = a


# first target is the one that gets run if just "make" is called
#$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS)
all: $(OBJS)
	$(CC) -o $(EXES) $^ $(CFLAGS_COMMON) $(LINKER_FLAGS)

#$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS)
debug: $(OBJS)
	$(CC) -o $(EXES) $^ $(CFLAGS_DEBUG) $(LINKER_FLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJS_DIR)/*.o $(EXES) *.o