YFLAGS = -d                             # force yacc to create y.tab.h
CFLAGS = -g -D_LEX_VER_                 # conditional compilation of yylex ()
OBJS = hoc.o init.o math.o symbol.o code.o lex.o

hoc5:   $(OBJS)
		cc $(OBJS) -o hoc5 -lm -lfl
		if [ -f hoc.c ]; then cp hoc.c y.tab.c; fi  # recover y.tab.c we need it for debugging

lex.o hoc.o code.o symbol.o init.o:	hoc.h

# new rule: a dummy file x.tab.h depends on y.tab.h and gets updated
# only when y.tab.h gets changed. So files depending on y.tab.h need
# not be compiled everytime.

lex.o code.o init.o symbol.o:	x.tab.h

x.tab.h:	y.tab.h
		-cmp -s x.tab.h y.tab.h || cp y.tab.h x.tab.h

pr:		ABOUT code.c hoc.h hoc.y init.c math.c symbol.c
		@pr $?
		@touch pr

clean:
		rm -f $(OBJS) [xy].tab.[ch] hoc5

