/*
 * Program to convert the DB2 dump from Mainframe (OS/390) to 
 * Tab separated format. 
 * Read bytes from the dump and convert them to ASCII from EBCDIC, 
 * and write to a disk file.
 * 
 */

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>

# include "objectmap.h"
# include "ebc2asc.h"
/* # include <procdump.h> */

/* # define BUFLENGTH 428     replaced with recLength variable */

typedef unsigned char uchar;
//typedef unsigned short ushort;


void conv (uchar*, uchar *, const unsigned int, FIELD * ,unsigned int);
int  readRec (uchar *, FILE*, const unsigned int);
short char2short (uchar *);
int char2int(uchar *);
void decimal2char(uchar *input, short width, short precision, uchar *output);
static void zon2char(uchar*, short, short, uchar*);

int recLength = 0;

/** Reverse a string in place */
void
reverse(uchar *s)
{
  int len,i,j;
  char c;

  len = strlen(s);
  if (len == 1)
  {
    return;
  }
  if (len > 1)
  {
   i=0;
   j = len-1;
   while(i <j)
   {
     c = s[j];
     s[j] = s[i];
     s[i] = c;
     i++;
     j--;
   }
  }
}

/** convert an integer to character string */
char*
itoa(int n, uchar* s)
{
   int i=0;
   int sign = n < 0 ? -1 : 1;
   if(sign == -1)
     n *= -1;

   do
    {
        s[i++] = n%10 + '0';
    } while ((n /= 10) > 0);

   if(sign == -1)
     s[i++]='-';

   s[i] = '\0';

   reverse(s);
   return s;
}

/** convert an short to character string */
char*
stoa(short n, uchar* s)
{
   int i=0;
   int sign = n < 0 ? -1 : 1;
   if(sign == -1)
     n *= -1;

   do
    {
        s[i++] = n%10 + '0';
    } while ((n /= 10) > 0);

   if(sign == -1)
     s[i++]='-';

   s[i] = '\0';

   reverse(s);
   return s;
}

int 
main (int ac, char** av)
{

/* 
   USAGE:
   
   %Executable-Name% %input-file% %object-name% %output-file% 
   
*/

    FIELD * object_structure = NULL;
    int object_number = -1;
    int NUM_OBJECTS;
    unsigned int no_fields =0;
    char object_name[15];
    uchar *buf;
    uchar *ascii_buf;
    int ret = 0;
    unsigned int j=0;
    FILE *istream = 0, *ostream = 0;
    NUM_OBJECTS = sizeof(objects)/15;

    if (ac < 2)
    {
	puts ("input filename required.");
        puts (" \n Usage :Executable-Name input-file object-name output-file"); 
        puts ("  where object-name can be one of the following ");
        for (j=0; j<NUM_OBJECTS; j++)
          printf("  %s \n", objects[j]);
	exit (EXIT_FAILURE);
    }

    if (NULL == (istream = fopen (av[1], "r")))
    {
	perror (av[1]);
	exit (EXIT_FAILURE);
    }

    if( ac < 3)
    {
        puts (" Object name required.");
        puts (" \n Usage :Executable-Name input-file object-name output-file"); 
        puts ("  where object-name can be one of the following ");
        for (j=0; j<NUM_OBJECTS; j++)
          printf("  %s \n", objects[j]);
        exit (EXIT_FAILURE);
    }

    strcpy(object_name, av[2]);


    if (ac == 3)      
    {
	puts ("out file name not provided. Will write to stdout.");
	ostream = stdout;      
    }
    else if(NULL == (ostream = fopen (av[3], "w")))
    {
	perror (av[3]);
	exit (EXIT_FAILURE);
    }
    

    for( j=0; j<NUM_OBJECTS; j++)
    {
      if(strcmp(object_name, objects[j]) ==0)
      {
        object_number = j;
        recLength = recLengths[object_number];
        no_fields = noFields[object_number];
        object_structure = (FIELD *)malloc(sizeof(FIELD)*no_fields);
	if( object_structure == NULL)
        {
              printf("ERROR : \n");
              exit(EXIT_FAILURE);
        }

        for (j=0; j<no_fields; j++)
        {
              object_structure[j].datatype = (objectArray[object_number])[j].datatype;
              object_structure[j].width = (objectArray[object_number])[j].width;
              object_structure[j].precision = (objectArray[object_number])[j].precision;
        }
        break;
      }
    }
    if(object_number == -1)
    {
      printf ("Error: Invalid Object \n");
      exit (EXIT_FAILURE);
    }


    j =0;

/*
    switch(object_number)
    {
       case 0:  recLength = L_OBJ24;
	        object_structure = (FIELD *)malloc(sizeof(struOBJ24));	
		if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ24)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ24[j].datatype;
                        object_structure[j].width = struOBJ24[j].width;
                        object_structure[j].precision = struOBJ24[j].precision;

                }
		break;

       case 1:
                recLength = L_OBJ33PL;
	        object_structure = (FIELD *)malloc(sizeof(struOBJ33PL));	
		if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ33PL)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ33PL[j].datatype;
                        object_structure[j].width = struOBJ33PL[j].width;
                        object_structure[j].precision = struOBJ33PL[j].precision;

                }
		break;

       case 2:  recLength = L_OBJ33BAL;
	        object_structure = (FIELD *)malloc(sizeof(struOBJ33BAL));	
		if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ33BAL)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ33BAL[j].datatype;
                        object_structure[j].width = struOBJ33BAL[j].width;
                        object_structure[j].precision = struOBJ33BAL[j].precision;

                }
		break;

       case 3:
                recLength = L_OBJ53;
	        object_structure = (FIELD *)malloc(sizeof(struOBJ53));	
		if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ53)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ53[j].datatype;
                        object_structure[j].width = struOBJ53[j].width;
                        object_structure[j].precision = struOBJ53[j].precision;

                }
		break;

       case 4:
		recLength = L_OBJ67;
	        object_structure = (FIELD *)malloc(sizeof(struOBJ67));	
		if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ67)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ67[j].datatype;
                        object_structure[j].width = struOBJ67[j].width;
                        object_structure[j].precision = struOBJ67[j].precision;

                }
		break;

       case 5:
		recLength = L_INTRORD;
	        object_structure = (FIELD *)malloc(sizeof(struINTRORD));	
		if( object_structure == NULL)
		{
			printf("ERROR : \n");
			exit(EXIT_FAILURE);
		}	
                no_fields = sizeof(struINTRORD)/sizeof(FIELD);
		for (j=0; j<no_fields; j++)
		{
			object_structure[j].datatype = struINTRORD[j].datatype;
			object_structure[j].width = struINTRORD[j].width;
			object_structure[j].precision = struINTRORD[j].precision;
			
		}
		break;
       case 6: 
		recLength = L_OBJ22OPN;
                object_structure = (FIELD *)malloc(sizeof(struOBJ22OPN));
                if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struOBJ22OPN)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struOBJ22OPN[j].datatype;
                        object_structure[j].width = struOBJ22OPN[j].width;
                        object_structure[j].precision = struOBJ22OPN[j].precision;

                }
                break;
       case 7:
		recLength = L_CCMAST;
                object_structure = (FIELD *)malloc(sizeof(struCCMAST));
                if( object_structure == NULL)
                {
                        printf("ERROR : \n");
                        exit(EXIT_FAILURE);
                }
                no_fields = sizeof(struCCMAST)/sizeof(FIELD);
                for (j=0; j<no_fields; j++)
                {
                        object_structure[j].datatype = struCCMAST[j].datatype;
                        object_structure[j].width = struCCMAST[j].width;
                        object_structure[j].precision = struCCMAST[j].precision;

                }
                break;
        

       default:
                printf(" Invalid Object \n");
                exit (EXIT_FAILURE);
    }
*/

    buf = malloc (recLength +1);
    ascii_buf = malloc ( recLength + 50);



    while ((ret = readRec(buf, istream, (unsigned int)recLength)) > 0)
    {
       ret = 0;
       memset(ascii_buf, (unsigned char)0, (unsigned int)recLength);
       conv (buf, ascii_buf, (unsigned int)recLength, object_structure, no_fields); 

/*
       if ((ret = fwrite(ascii_buf, recLength, 1, ostream)) < 1)
       {
	  perror ("fwrite");
	  exit (1);
       }
*/
       fprintf(ostream, "%s\n", ascii_buf);
/*
       for(j=0; j<recLength; j++)
       {
         fputc(ascii_buf[j], ostream);
       }
       fputc( '\n', ostream);
*/
    }


    close (istream);
    close (ostream);
    free(buf);
    free(ascii_buf);
    return 0;
}


void 
decimal2char(uchar *input, short width, short precision, uchar *fin_output)
{
 uchar byte, nibble;
 short i=0, j=0, k=0;
 short negative =0;
 short last ;
 char *output;
 output = malloc(width+2);
 for (i=0; i<(width+1)/2 ; i++)
 {
   if (precision > 0)
   {
       if ( (i == ceil((width-precision+1)/2.0) -1)&& ((width-precision+1)%2) )  /* When Width-Precision is even */
       {
         output[j] = '.';
         j++;
       }
   }

   byte =input[i];
   nibble = byte& 0xf0;
   nibble =nibble>>4;
   nibble+=48;
   output[j]= nibble;
   j++;

   if (precision > 0)
   {
       if ( (i == ceil((width-precision+1)/2.0) -1)&& ((width-precision)%2) )  /* When Width-Precision is odd */
       {
         output[j] = '.';
         j++;
       }
   }

   if( i <  (width+1)/2 - 1)   /** Checking for sign nibble */
   {
     nibble = byte & 0x0f;
     nibble+=48;
     output[j]= nibble;
     j++;
   }
  }

  //Handling for negative numbers
  last = (width +1)/2 -1;
  if ( (input[last] & 0x0f) == 0x0d )
   negative = 1;
  i =0;
  if(negative)
  {
    fin_output[0]='-';
    i=1;
  }

  //Handling Leading Zeros
  k =0;
  while (output[k] == '0' && k <width)
   k++;
  if (output[k] == '.')
   k--;
  for (j=k; j<width+1; j++)
  {
    fin_output[i] = output[j];
    i++;
  }
  fin_output[i] = '\0';

}
  
int
readRec (uchar buf[], FILE *is, const unsigned int len)
{
    int i = 0, c = 0;
    memset (buf, (unsigned char)0, len);
    for (i=0; (i<len) && (EOF != (c=getc(is))); i++)
    {
        buf[i] = c;
    }
    return i;
}

void
conv (uchar *buf, uchar *ascii_buff, const unsigned int len, FIELD * object_structure, unsigned int no_fields)
{
    unsigned int c = 0;
    short s;
    int intgr;
    unsigned int i, j = 0,k=0;
   // unsigned int no_fields = sizeof(object_structure)/ sizeof(FIELD);            /** TODO: change as per the object*/

    int index =0;
    //printf(" No. of fileds :%d\n", no_fields);
    fflush(stdout);

    for (i=0; i<no_fields; i++)
    {
      FIELD curr_field = object_structure[i];            /** TODO: */
      int datatype = curr_field.datatype;
      short width = curr_field.width;
      short precision = curr_field.precision;
      uchar short_input[2], intgr_input[4], *decimal_input, *char_input; 
      uchar short_output[8], intgr_output[12], *decimal_output, *char_output;
      uchar *temp;
      int max; 
      //printf(" Data Type :%d\n", datatype);
      fflush(stdout);

      max = width > 12 ? (width + 3) : 12;
      temp = malloc(max);

      switch(datatype)
      {
        case E_SKIP:                  /** ignore the 'width' number of bytes. Not written to output */
                        j += width;   /** TODO: but this will add a \t in the output. How to avoid? */
                        break;

        case E_VARCHAR: 
                        j+=2;  /*skip the length bytes */

                        /** TODO: remove these lines. case E_CHAR does the same thing 
			char_output =  malloc(width+1);
                        for(k=0; k<width; k++)
                        {
                           c = buf[j+k];
                           char_output[k]= EBC2ASC[c];
                        }
                        j += width;
			char_output[k]='\0';
                        strcpy(temp, char_output);
			break; */

                        /* DO NOT break. Let fall through */
        case E_DATE:
        case E_TIME:
        case E_CHAR:
                        char_output =  malloc(width+1);
                        for(k=0; k<width; k++)
			{
      			   c = buf[j+k];
      			   char_output[k]= EBC2ASC[c]; 
                        }
			char_output[k]='\0';
                        j += width;
			strcpy(temp, char_output);

			break;
        case E_SMALLINT:
                        short_input[0]= buf[j]; 
                        j++;
                        short_input[1]= buf[j]; 
                        j++;
                        s = char2short(short_input);
                        stoa(s, short_output);
			strcpy(temp, short_output);
                        break;
        case E_INT:
                        intgr_input[0]= buf[j];
                        j++;
                        intgr_input[1]= buf[j];
                        j++;
                        intgr_input[2]= buf[j];
                        j++;
                        intgr_input[3]= buf[j];
                        j++;
                        intgr = char2int(intgr_input);
                        itoa(intgr, intgr_output);
			strcpy(temp, intgr_output);
                        break;
        case E_DECIMAL:
                        decimal_input = malloc((width+1)/2);
                        decimal_output= malloc(width + 3);
			for(k=0; k<(width+1)/2; k++)
			  decimal_input[k] = buf[j+k];
                        decimal2char(decimal_input, width, precision, decimal_output);
                        j += (width+1)/2;
			strcpy(temp, decimal_output);
			break;
	case E_ZONED:
                        char_input = malloc (width+1);   
                        char_output =  malloc(width+3); /** one each for '\0', sign and '.' */
                        for (k = 0; k < width; k++)
                        {
                           char_input[k] = buf[j+k];
                        }
                        char_input[k] = '\0';
                       
                        zon2char(char_input, width, precision, char_output);
                        j += width;
                        strcpy(temp, char_output);
                        break;
      }

      if(datatype != E_SKIP )
      {	
      	for (k=0; k<strlen(temp); k++)
      	{
        	ascii_buff[index] = temp[k];
        	index++;
      	}

      	if ( i < no_fields -1 )
      	{
      		ascii_buff[index] = '\t';
        	index++;
      	}
      }

/*
      free(decimal_input);
      free(char_output);
      free(intgr_output);
      free(short_output);
      free(decimal_output);
*/

    }
    ascii_buff[index] ='\0';
}


short
char2short (uchar arr[])
{
/* assume: short is 2 bytes and BIG Endian */
    short i=0, j=0;
    i = arr[0];
    j = arr[1];
    i <<= 8;
    i |= j;
    return i;
}

int
char2int(uchar arr[])
{
 /* assume int is 4 bytes and BIG Endian */
    int i=0, j=0, k=0, l=0;
    i = arr[0];
    j = arr[1];
    k = arr[2];
    l = arr[3];
    i <<= 24;
    j <<= 16;
    k <<= 8;
    i |=j|k|l;
    return i;
}

/**
 *  zon2char: convert a EBCDIC zoned decimal (e.g. PIC S9(4)V99 USAGE DISPLAY)
 *  sign trailing overpunched) to an ASCII char string. (this does *not* apply
 *  to COMP numbers.
 *  note: the digit is first converted to ASCII, then we separate the sign &
 *  number, though reverse is also possible.
 *
 *  this code based on info at:
 *  http://www.3480-3590-data-conversion.com/article-signed-fields.html
 *  and..
 *  http://en.wikipedia.org/wiki/Signed_overpunch
 */

static void
zon2char(uchar *input, short width, short precision, uchar *output)
{
    uchar byte = 0, last_byte = 0;
    int i = 0, j=0 , sign = 0;

    /** separate the sign & number from the last byte now
     *  and save trouble later
     */

    byte = EBC2ASC[input[width-1]];
    switch (byte)
    {
        case 0x7B:                     /** EBCDIC 0xC0,  ASCII '{' */
                 byte = '0'; break;
        case 0x41:
                 byte = '1'; break;
        case 0x42:
                 byte = '2'; break;
        case 0x43:
                 byte = '3'; break;
        case 0x44:
                 byte = '4'; break;
        case 0x45:
                 byte = '5'; break;
        case 0x46:
                 byte = '6'; break;
        case 0x47:
                 byte = '7'; break;
        case 0x48:
                 byte = '8'; break;
        case 0x49:
                 byte = '9'; break;
        case 0x7D:                                  /** EBCDIC 0xD0,  ASCII '}' */
                 sign = -1; byte = '0'; break;
        case 0x4A:                                  /** EBCDIC 0xD1, ASCII 'A' */
                 sign = -1; byte = '1'; break;
        case 0x4B:
                 sign = -1; byte = '2'; break;
        case 0x4C:
                 sign = -1; byte = '3'; break;
        case 0x4D:
                 sign = -1; byte = '4'; break;
        case 0x4E:
                 sign = -1; byte = '5'; break;
        case 0x4F:
                 sign = -1; byte = '6'; break;
        case 0x50:
                 sign = -1; byte = '7'; break;
        case 0x51:
                 sign = -1; byte = '8'; break;
        case 0x52:
                 sign = -1; byte = '9'; break;
        default:
                 break;
    }
    last_byte = byte;

    output[j] =  (sign < 0) ? '-' : '+';

    for (i=0, j=1; i < (width - 1); j++, i++ )   /** i for comparision, j for array subscript */
    {
        byte = EBC2ASC[input[i]];

        if ( i == (width-precision))   /** time for a '.' */
        {
            output[j++] = '.';
        }
        output[j] = byte;
    }

    if (i == (width-1))
    {
        output[j++] = last_byte;
    }

    output[j] = '\0';

}
 
