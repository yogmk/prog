# include <gtk/gtk.h>

char * 
get_imgfile_name (void)
{
	GtkWidget *dilog;
	char *imgfile=NULL;

	dilog = gtk_file_chooser_dialog_new ("select bmp ...", NULL, 
	                                      GTK_FILE_CHOOSER_ACTION_OPEN,
										  GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
										  GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
										  NULL);
	
	/* set-up signal handler to call loadimg in dialog's destroy event 

	g_signal_connect (GTK_OBJECT (dilog), "destroy",
	                  G_CALLBACK (loadimg), (gpointer) imgfile);
	*/
	if (gtk_dialog_run (GTK_DIALOG (dilog)) == GTK_RESPONSE_ACCEPT)
	  {
	  	imgfile = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dilog));
		fprintf (stderr, "you chose %s\n", imgfile);
		gtk_widget_destroy (dilog);
	  }
	return imgfile;
}
