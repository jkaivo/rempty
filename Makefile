.POSIX:

# This Makefile was generated by maje
# See https://gitlab.com/jkaivo/maje/ for more information
# Do not edit this Makefile by hand

CC=c99
LD=$(CC)
CFLAGS=-Wall -Wextra -Wpedantic -Werror -g
LDFLAGS=
LDLIBS=
SRCDIR=.
OBJDIR=.
BINDIR=$(OBJDIR)

all: $(BINDIR)/rempty

clean:
	rm -f $(BINDIR)/rempty $(OBJDIR)/*.o

$(BINDIR)/rempty: $(OBJDIR)/rempty.o
$(OBJDIR)/rempty.o: $(SRCDIR)/rempty.c
	$(CC) $(CFLAGS) -o $@ -c $(SRCDIR)/rempty.c

$(BINDIR)/rempty:
	$(LD) $(LDFLAGS) -o $@ $(OBJDIR)/*.o $(LDLIBS)