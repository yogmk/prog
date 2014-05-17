# ident "@(#) functions, structures and data types for reading a bmp image."

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>


//const float TOLERANCE 0.00001
# define TOLERANCE 0.1

# define COLOUR256 1

# ifdef MONOCHROME              /* monochrome bmp: 1 bit per pixel */
# elif COLOUR16                 /* 16 colour bmp: 1 nibble (4 bits) per pixel */
# elif COLOUR256
  //typedef signed char Pixel;          /* 256 colour bmp: 1 byte (8 bits) per pixel */
  typedef short Pixel;         /* but short is easy for numeric calculations */

# elif TRUECOLOUR               /* 24 bit colour bmp: 3 bytes per pixel */
   typedef struct
     {
        char red;
        char green;
        char blue;
     } Pixel;
# endif


/* bmp file header as per BMP file format specs. */

unsigned short BmpType;    

struct BitmapFileHeader
  {
   /* unsigned short BmpType;    here is a memory hole between this short & next int */
     unsigned int  BmpSize;    
     unsigned short Reserved1;
     unsigned short Reserved2;
     unsigned int  Offsetbits;
  };

/* bmp info 
 * because of 2 shorts in succession, 
 * this structure does not have a memory hole
 */

struct BitmapInfo
  {
     unsigned int  BmpInfoSize;
     int           Width;
     int           Height;
     unsigned short Planes;
     unsigned short BitCount;
     unsigned int  Compression;
     unsigned int  ImageSize;
     int           XPelsPerMeter;
     int           YPelsPerMeter;
     unsigned int  ColoursUsed;
     unsigned int  ColorusImportant;
  };

extern int getpixels(FILE*, Pixel*, int);
extern float average(Pixel*, long);
extern float sum(Pixel*, long);
extern void Haar(Pixel*, Pixel*, const int, const float);
extern void revHaar(Pixel*, Pixel*, const int, const float);
extern float rltdiff(Pixel, Pixel);
int imgdata_size;

