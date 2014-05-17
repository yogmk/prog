# ident "@(#) function to calculate Haar transform on a series of numbers."

# include "bmp.h"
# define Abs(x) ((x) < 0 ? -(x) :(x))

void
Haar(Pixel *series, Pixel *Hseries, const int n, const float savg_)
{
    int i=0, j=0, k=0;
    float diff=0.0;
    
    static int recursion =0;
    printf("%d th recursion\n", ++recursion);

    /* can't test floats for equality, so check for approximation */
    //if ((diff=rltdiff(*series, savg_)) == 0.0 || diff <= TOLERANCE)
    diff = (float) series[0] - (float) savg_;
    if (diff <= TOLERANCE)
      {
         printf ("diff-> %f", diff);
         return ;
      }
    else
      {    /* apply transformation */    
        
        Hseries = malloc(n* sizeof(*Hseries));

        for (i=0, j=0; j < n; i++, j+=2)
            Hseries[i] = (series[j] + series[j+1]) / (Pixel) 2;

        for (i, j=0, k=0; i < n; i++, j+=2, k++)
            Hseries[i] = series[j] - Hseries[k];
        
        /* copy transformed series onto input array before next recursion */
        for (k=0; k<n; k++)
            series[k] = Hseries[k];

        free(Hseries);
        Haar(series, Hseries, n, savg_);
     }
}


float
average(Pixel *series, long n)
{
    int i=0;
    float sum = 0.0;
    
    for(i=0; i<n ; i++)
        sum = sum + series[i];
 
      printf ("average: sum = %f, n = %d\n", sum, n);
    return (sum/(float)n);
}


float
sum(Pixel *series, long n)
{ 
   long i = 0;
   float sum_ = 0.0;

    for(i=0; i<n ; i++)
        sum_ = sum_ + series[i];
 
      printf ("average: sum = %f\n", sum_);
    return (sum_);
}
