# This Makefile is the output of a template Makefile that was
# processed by the m4 macro preprocessor. It is not intended
# to be human readable.

CC=cc
PREFIX=/usr/local
CFLAGS=
OBJS=src/replace.o src/reverse.o src/starts.o src/strip.o src/count.o 
TESTS=tests/test_snprintf.out tests/test_strstarts.out tests/test_strrev.out tests/test_strrepl.out tests/test_strcount.out tests/test_strstrip.out 
DOCS=./doc/strstrip.cware ./doc/strstarts.cware ./doc/strrev.cware ./doc/strrepl.cware ./doc/strcount.cware ./doc/libstring.cware 
MANNAMES=strstrip.cware strstarts.cware strrev.cware strrepl.cware strcount.cware libstring.cware 
DEBUGGER=

all: $(OBJS) $(TESTS)

clean:
	rm -f $(TESTS)
	rm -f $(OBJS)

check:
	./scripts/check.sh $(DEBUGGER)

install:
	for manual in $(MANNAMES); do					  \
		cp doc/$$manual $(PREFIX)/share/man/mancware; \
	done

uninstall:
	for manual in $(MANNAMES); do					 \
		rm -f $(PREFIX)/share/man/mancware/$$manual; \
    done

.c.out:
	$(CC) $< $(OBJS) $(CFLAGS) -o $@
