YFLAGS = -d                             # force yacc to create y.tab.h
CFLAGS = -g -D_LEX_VER_                 # conditional compilation of yylex ()
OBJS = hoc.o init.o math.o symbol.o lex.o

hoc3:   $(OBJS)
		cc $(OBJS) -o hoc3 -lm -lfl
		cp hoc.c y.tab.c                # get back y.tab.c we need it for debugging

hoc.o:	hoc.h

lex.o init.o symbol.o:	hoc.h  y.tab.h

clean:
		rm -f $(OBJS) y.tab.[ch] hoc3
