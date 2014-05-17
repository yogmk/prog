# ident "@(#) function to calculate Haar transform on a series of numbers."

typedef float Pixel;
float average(Pixel*, int);

# define TOLERANCE 0.00001

void
Haar(Pixel *series, Pixel *Hseries, const int n, const float savg_)
{
    int i=0, j=0, k=0;
    float avg=0.0;
    float diff=0.0;
    
    if ((diff =series[0] - savg_) == 0.0 || diff <= TOLERANCE)      /* we're there */
        return ;
    else
    {    /* apply transformation */    
        
        Hseries = malloc(n * sizeof(Pixel));

        for (i=0, j=0; j < n; i++, j+=2)
            Hseries[i] = (series[j]+series[j+1]) / 2.0;

        for (i, j=0, k=0; i < n; i++, j+=2, k++)
            Hseries[i] = series[j] - Hseries[k];
        
        /* copy transformed seriesto original array before next recursion */
        for (k=0; k<n; k++)
            series[k] = Hseries[k];

        free(Hseries);
        Haar(series, Hseries, n, savg_);
    }
}



float
average(Pixel *series, int n)
{
    int i=0;
    float retval = 0.0;
    
    for(i=0; i<n ; i++)
        retval = retval + series[i];

    return (retval/(float)n);
}
