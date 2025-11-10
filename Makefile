CC := gcc
CFLAGS := -Wall -Wextra -O2
DEPFLAGS := -MMD -MP
LDFLAGS :=
LDLIBS :=

OUTDIR := out
SRCDIR := src
BINDIR := $(OUTDIR)/bin
OBJDIR := $(OUTDIR)/obj

TARGET := $(BINDIR)/simple-mnemonic

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(TARGET)

run: all
	@./$(TARGET)


$(BINDIR) $(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ -o $@
	
clean:
	rm -rf $(OUTDIR)

-include $(OBJS:.o=.d)
