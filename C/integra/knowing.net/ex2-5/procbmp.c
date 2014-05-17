# include <stdio.h>
# include <stdlib.h>

# include "bmp.h"

void
procbmp (FILE *i_img, FILE *o_img)
{
    int retval;
    Pixel *imagedata = NULL;
    Pixel *transform = NULL;
    float av = 0.0;
    float sum_ = 0.0;
    long n = 0;
    struct BitmapFileHeader bfh;
    struct BitmapInfo bfi;
    Pixel *colourmap = NULL;          /* store colour map. typically no of colours x 4 */
    int colourmap_size = 0;

    /* read bit map header */

    if((retval=fread(&BmpType, sizeof(BmpType), 1, i_img)) == 1) 
      {
         if (BmpType != 19778)
           {
             fprintf(stderr, "not a valid bitmap image.");
             exit (EXIT_FAILURE);
           }
      }
    else
      {
        perror("fread");
	exit(EXIT_FAILURE);
      }

    if((retval=fread(&bfh, sizeof(bfh), 1, i_img)) != 1) 
      {
        perror("fread");
	exit(EXIT_FAILURE);
      }

   /* read bitmap info */
    if((retval = fread(&bfi, sizeof(bfi), 1, i_img)) == 1)
      {
         if (bfi.BitCount != 8)
           {
             fprintf(stderr, "Not a 256 colour bitmap.");
	     exit(EXIT_FAILURE);
           }
      }
    else
      {
        perror("fread");
	exit(EXIT_FAILURE);
      }
    
    if (bfi.ColoursUsed == 0)	bfi.ColoursUsed = 256;
    colourmap_size = bfi.ColoursUsed * 4;

  /* read the colour map table 
    if((colourmap = malloc(colourmap_size)) != NULL)
      {
         retval = getpixels(i_img, colourmap, colourmap_size);
      }
    else
      {
         perror("malloc(colourmap)");
	 exit (EXIT_FAILURE);
      }
  */

   /* read the actual image pixels */
    imgdata_size = bfi.ImageSize + colourmap_size;
   printf("Image size = %d bytes\n", imgdata_size);
    if ((imagedata = malloc(imgdata_size * sizeof(Pixel))) != NULL)
      {
         n = getpixels(i_img, imagedata, imgdata_size);
      }
    else
      {
         perror("malloc(imagedata)");
	 exit (EXIT_FAILURE);
      }
    if (n > 0)
    	av = average(imagedata, n);

    if (av > 0)
    	Haar(imagedata, transform, n, av);
    
    /* 
     * we now have the transformed series.
     * write to a file.
     */
    
    sum_ = sum (imagedata, n);
    revHaar (imagedata, transform, n, sum_);

    fwrite(&BmpType, sizeof(BmpType), 1, o_img);
    fwrite(&bfh, sizeof(bfh), 1, o_img);
    fwrite(&bfi, sizeof(bfi), 1, o_img);
 /*
    for (n=0; n< colourmap_size; n++)
      {
        fputc((char)colourmap[n], o_img);
      }
    free(colourmap);
 */
    for (n=0; n< imgdata_size; n++)
      {
        fputc((char)imagedata[n], o_img);
      }
    free(imagedata);

    printf("%d bytes written\n", n); 
}
