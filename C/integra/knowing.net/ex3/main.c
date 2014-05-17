# ident "@(#) program which opens an image file and applies Haar transform to it."

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

# include "bmp.h"

int
main (int argc, char **argv)
{
    FILE *i_img, *o_img;
    char ofname[256]={'\0'};

    if (argc < 2)
    {
    	puts("usage: imgproc image_file output_file");
    	return 0;
    }

    if (argc == 2)		/* output file name not provided */
    {
    	puts("  output file name: ");
        fgets(ofname, sizeof(ofname), stdin);
    }

    if((i_img=fopen(argv[1], "rb")) == NULL)
    {
    	perror("fopen");
    	exit(EXIT_FAILURE);
    }

    if((o_img=fopen(argv[2] ? argv[2] : ofname, "wb")) == NULL)
    {
    	perror("fopen");
    	close(i_img);
    	exit(EXIT_FAILURE);
    }

    procbmp(i_img, o_img);

    close(i_img);
    close(o_img);
    return 0;
}
