# include <stdio.h>
# include <stdlib.h>
# include <gtk/gtk.h>

char *get_imgfile_name(void);

extern GtkWidget *win, *vbox, *fme;

void
loadimg (GtkWidget *img)
{
	/* 
	GtkImage *img; 
	GtkWidget *vbox;
	*/
	
	GdkPixbuf *pixbuf;
	GError *error=NULL;
	char *imgfile = NULL;

	if ((imgfile = get_imgfile_name ()) == NULL)
	  {
	  	perror ("get_imgfile_name");
		fputs("error getting file name", stderr);
	  }

    if ((pixbuf = gdk_pixbuf_new_from_file (imgfile,  &error)) != NULL)
	  {
		img = gtk_image_new_from_pixbuf (pixbuf);
	    gtk_container_add (GTK_CONTAINER (fme), img); 
		gtk_object_sink (GTK_OBJECT (img));
		gtk_widget_show_all (fme);        /* very important, I wasted 2 days over this!! */
	  }
	else
	  {
	  	fprintf(stderr, (error->message));      /* pixbuf is null */
	  }
	free (imgfile);
}


void
clrimg (GtkImage *img)
{
    GtkImageType itype;
	//if ((itype = gtk_image_get_storage_type (img)) == GTK_IMAGE_PIXBUF )
	if (img != NULL) 
	  {
		gtk_object_ref (GTK_OBJECT (img));
		gtk_container_remove (GTK_CONTAINER (fme), GTK_WIDGET (img));
		//gtk_image_clear (img);
	  }
	fprintf (stderr, "GTK_IMAGE_TYPE = %d\n", itype);
}
