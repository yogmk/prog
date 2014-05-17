# ident "@(#) function to reverse Haar transform on a series of numbers."

/*
 * Haar function calculates the average of original serieand recurses
 * till the first element of transformedseries is = average.
 *
 * Here we start with the sum of the (transformed) series and
 * calculate back the original series by recursing till the sum
 * equals the first element of the series we started from originally.
 */

# include "bmp.h"

void
revHaar(Pixel *series, Pixel *Hseries, const int n, const float sum_)
{
    int i=0, j=0, k=0;
    float diff=0.0;
    
    static int recursion =0;
    printf("%d th recursion\n", ++recursion);

    if ((diff=rltdiff(series[0], sum_)) == 0.0 || diff <= TOLERANCE)      /* we're there */
      {
         return ;
      }
    else
      {    /* reverse the transformation */    
        
        /*
         * in a series, add  1st + 3rd elem to get the 1st elem of new series,
         * subtract 1st - 3rd to get the second elem of new series, and so on ...
         */

        Hseries = malloc(n * sizeof(Pixel));
        for (i=0, j=0, k=2; j < n; ++i, ++j, ++k)
          {
             Hseries[i]   = series[j] + series[k];
             Hseries[++i] = series[j] - series[k];
          }

        /* copy transformed series onto input array before next recursion */
        for (k=0; k<n; k++)
             series[k] = Hseries[k];

        free(Hseries);
        revHaar(series, Hseries, n, sum_);
     }
}
