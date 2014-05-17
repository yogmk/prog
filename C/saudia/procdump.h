
/*
 * Program to convert the DB2 dump from Mainframe (OS/360?) to 
 * Oracle friendly format. 
 * Read bytes from the dump and convert them to ASCII from EBCDIC, 
 * and write to a disk file.
 * 
 */

# include "TBCADDR.h"
# include "TBCCUST.h"
# include "TEFVLAN.h"
# include "TFDASST.h"
# include "TFDASSTU.h"
# include "TPYEROOT.h"
# include "TYPEPYTO.h"

unsigned int RecLength;

ushort char2short (uchar *);

