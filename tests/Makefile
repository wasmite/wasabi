PROG = uevm_test
REPO_ROOT ?= ..
BUILD_DIR = .build

SOURCES = uevm_test.c \
          $(REPO_ROOT)/src/internal/math.c 

INCS = -I$(REPO_ROOT)/src \
       -I$(REPO_ROOT)/src/internal \
			 -I$(REPO_ROOT) \
       -I. \
       $(CFLAGS_EXTRA)

CFLAGS = -W -Wall -Werror -g -O0 -Wno-multichar -I$(BUILD_DIR) $(INCS)

$(BUILD_DIR):
	mkdir $@

all: $(BUILD_DIR) $(PROG)
	./$(PROG)

$(PROG): $(SOURCES)
	$(CC) -o $(PROG) $(SOURCES) $(CFLAGS)

clean:
	rm -rf $(PROG) $(BUILD_DIR)