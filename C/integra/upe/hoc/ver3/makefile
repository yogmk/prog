YFLAGS = -d                             # force yacc to create y.tab.h
CFLAGS = -g
OBJS = hoc.o init.o math.o symbol.o 

hoc3:   $(OBJS)
		cc $(OBJS) -o hoc3 -lm 
		if [ -f hoc.c ]; then cp hoc.c y.tab.c; fi  # recover y.tab.c we need it for debugging

hoc.o:	hoc.h

init.o symbol.o:	hoc.h  y.tab.h

clean:
		rm -f $(OBJS) y.tab.[ch] hoc3
