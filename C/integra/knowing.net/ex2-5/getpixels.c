# ident "@(#) get a series of (8-bit) pixels in an array from an image."

# include <string.h>
# include <stdlib.h>

# include "bmp.h"


int
getpixels(FILE *img, Pixel *imagedata, int data_size)
{
    int i=0;
    int pix;
   /*
    if((i = fread(imagedata, 1, data_size, img))  < 1)
      {
         perror("fread");
         exit(EXIT_FAILURE);
      }
    */

    for (i=0; ((pix=fgetc(img)) != EOF) && i < data_size; i++)
      {
        imagedata[i] = (Pixel)pix;
      }
    if (imgdata_size % 2 == 0) 				/* i has to be even */
    	imagedata[data_size] = '\0';		
    else
    	imagedata[--data_size] = '\0';	        /* discard last (odd) number */

    return i;
}
