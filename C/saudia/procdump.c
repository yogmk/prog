/*
 * Program to convert the DB2 dump from Mainframe (OS/360?) to 
 * Oracle friendly format. 
 * Read bytes from the dump and convert them to ASCII from EBCDIC, 
 * and write to a disk file.
 * 
 */

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

# define BUFLENGTH 32708

typedef unsigned char uchar;


static const uchar
EBC2ASC [] = {
 0x0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x25, 0x20, 0x20, 0x0d, 0x20, 0x20,     /* 00-14 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 15-29 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 30-44 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 45-59 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2e,    /* 60-74 */
 0x3c, 0x28, 0x2b, 0x20, 0x26, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 75-89 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21,    /* 90-104*/
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 105-119*/
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,    /* 120-134*/
 0x67, 0x68, 0x69, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,    /* 135-149 */
 0x6f, 0x70, 0x71, 0x72, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x73, 0x74, 0x75,    /* 150-164 */ 
 0x76, 0x77, 0x78, 0x79, 0x7a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 165-179 */
 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x41, 0x42,    /* 180-194 */
 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4a,    /* 195-209 */
 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 210-224 */
 0x20, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 225-239 */
 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x20, 0x20, 0x20, 0x20, 0x20,    /* 240-254 */
 0x0                                                                                          /* 255 */
};


void conv (char*, Col1to3);
int  readRec (char *, FILE*, const unsigned int);
void proclongvar (uchar[], unsigned short);
ushort char2short (uchar *);

enum {
     E_TBCADDR = 0,
     E_TBCCUST,
     E_TEFVALN,
     E_TFDASST,
     E_TFDASSTU,
     E_TPYEROOT,
     E_TPYEPYTO,
     };

unsigned const char* 
tables[] = { "TBCADDR", "TBCCUST", "TEFVALN", "TFDASST", "TFDASSTU", "TPYEROOT", "TPYEPYTO" };

enum DATATYPE {
    E_CHAR = 0,
    E_SMALLINT,
    E_INT,
    E_DECIMAL,
    E_DATE,
    E_TIME,
    E_VARCHAR
};

typedef struct {
    DATATYPE dt;
    short width;    
}FIELD;

const FIELD struTFDASST [] = { };
const FIELD struTFDASSTU [] = { };
const FIELD struTFDEVALN [] = { };
const FIELD struTBCCUST [] = { };
const FIELD struTBCADDR [] = { };
const FIELD struTPYEROOT [] = { };
const FIELD struTPYEPYTO [] = { };
 
const FIELD* allStructs [] = {struTFDASST, struTFDASSTU, struTFDEVALN, struTBCCUST, struTBCADDR, struTPYEROOT, struTPYEPYTO};


int 
main (int ac, char** av)
{
    uchar buf [BUFLENGTH+1];
    int ret = 0;
    FILE *istream = 0, *ostream = 0;
    Col1to3 columns1to3;

    if (ac < 2)
    {
	puts ("input filename required.");
	exit (EXIT_FAILURE);
    }


    if (NULL == (istream = fopen (av[1], "r")))
    {
	perror (av[1]);
	exit (EXIT_FAILURE);
    }

    if (ac == 2)      
    {
	puts ("out file name not provided. Will write to stdout.");
	ostream = stdout;      
    }
    else if(NULL == (istream = fopen (av[2], "w")))
    {
	perror (av[2]);
	exit (EXIT_FAILURE);
    }

    while ((ret = readRec(buf, istream, (unsigned int)BUFLENGTH)) > 0)
    {
       ret = 0;
       conv (buf, columns1to3); 
# ifdef DEBUG
       /*
# endif
       if ((ret = fwrite(buf, BUFLENGTH, 1, ostream)) < 1)
       {
	  perror ("fwrite");
	  exit (1);
       }
# ifdef DEBUG
       */
# endif
    }


    close (istream);
    close (ostream);
    return 0;
}



int
readRec (char buf[], FILE *is, const unsigned int len)
{
    int i = 0, c = 0;
    memset (buf, (unsigned char)0, len);
    for (i=0; EOF != (c=getc(is)) && (i<len); i++)
    {
        buf[i] = c;
    }

    return i;
}


void
conv (char *buf, Col1to3 col1to3)
{
    unsigned char c = 0;
    short i, j = 0;

    /* first 2 bytes are markers, ignore them */
    buf = buf+2;

    /* next 6 bytes are char, so convert them to ASCII */

    for (i=0; i<4; i++) /* PROD_YR */
    {
	c = (short) buf[i];
        col1to3.prod_yr[i] = EBC2ASC[c];
    }
    col1to3.prod_yr[i] = '\0';

    for (i, j=0; j<2; i++, j++) /* PROD_LINE_CDE */
    {
	c = (short) buf[i];
        col1to3.prod_line_cd[j] = EBC2ASC[c];
    }
    col1to3.prod_line_cd[j] = '\0';

    /* next 2 bytes are numeric */
    unsigned short int seqno = 0;

    seqno = buf[i++];
    seqno = seqno << 8;        /* char has 8 bits, right shift the short */
    seqno = seqno | buf[i];
    col1to3.seq = seqno;

# ifdef DEBUG 
    puts (col1to3.prod_yr);
    puts (col1to3.prod_line_cd);
    printf ("seq no = %d\n", col1to3.seq);
# endif
    
    buf = buf + 8;       /* seek to the begining of LONGVAR data */

    proclongvar (buf, seqno);
}


void 
proclongvar (uchar buf[], unsigned short seq)
{
    seq1Rec rec1;
    int i=0, c=0;
 
    rec1.models_lim_ref = char2short(buf);
    buf = buf + 2;
    rec1.option_lim_ref = char2short(buf);
    buf = buf + 2;
    /*
    rec1.t62501_len = char2short(buf);
    buf = buf + 2;
    */
    rec1.mod_table_size = char2short(buf);
    buf = buf + 2;
    rec1.fam_table_size = char2short(buf);
    buf = buf + 2;

    for (i=0; i < 7; i++)
    {
        c = buf[i];
        rec1.model_desig[i] = EBC2ASC[c];
    }
    rec1.model_desig[i] = '\0';

# ifdef DEBUG 
    printf ("rec1.models_lim_ref = %d\n", rec1.models_lim_ref);
    printf ("rec1.option_lim_ref = %d\n", rec1.option_lim_ref);
    /*printf ("rec1.t62501_len = %d\n", rec1.t62501_len);*/
    printf ("rec1.mod_table_size = %d\n", rec1.mod_table_size);
    printf ("rec1.fam_table_size = %d\n", rec1.fam_table_size);
    printf ("rec1.model_desig = %s\n", rec1.model_desig);
# endif
   
/* increament buffer pointer */
    /* initialise the variable portion for x 
    famOption *seq1data;
    */

    /* for now, just convert the data to ASCii & dump */
    c=0;
    while ('\0' != buf[c])
    {
	putchar (EBC2ASC[buf[c++]]);
    }

}


ushort
char2short (uchar arr[])
{
/* assume: short is 2 bytes and BIG Endian */
    ushort i=0, j=0;
    i = arr[0];
    j = arr[1];
    i <<= 8;
    i |= j;
    return i;
}
