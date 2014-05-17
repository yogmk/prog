# include <stdio.h>
# include <stdlib.h>
# include <gtk/gtk.h>

/* prototypes */

void loadimg (GtkWidget*);
void clrimg (GtkWidget*);
void get_imgfile_name (char*);

GtkWidget * win, *clsbtn, *lodbtn, *clrbtn, *sep, *vbox, *btnbox, *fme;
/*GtkImage *img = NULL; */
GtkWidget *img = NULL; 

int
main (int argc, char *argv[])
{
	/* 
	char *imgfile;
	GdkDrawable *drawable; 
	GdkPixbuf *pixbuf=NULL;
    */

	gtk_init (&argc, &argv);
	win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (win), argv[1]);
	g_signal_connect (G_OBJECT (win), "delete_event", G_CALLBACK (gtk_main_quit), NULL);
	gtk_container_set_border_width (GTK_CONTAINER (win), 15);
	
	vbox = gtk_vbox_new (FALSE, 20);   /* do not allocate equal space for all */

    fme = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME (fme), GTK_SHADOW_NONE);

	sep = gtk_hseparator_new ();

    btnbox = gtk_hbox_new (TRUE, 20);

    clsbtn = gtk_button_new_with_label ("close");
	g_signal_connect (G_OBJECT (clsbtn), "clicked", G_CALLBACK (gtk_main_quit), NULL);
	gtk_box_pack_start (GTK_BOX (btnbox), clsbtn, FALSE, FALSE, 0);
	
    lodbtn = gtk_button_new_with_label ("Load");   
	g_signal_connect (G_OBJECT (lodbtn), "clicked", G_CALLBACK (loadimg), img);
	gtk_box_pack_start (GTK_BOX (btnbox), lodbtn, FALSE, FALSE, 0);

    clrbtn = gtk_button_new_with_label ("clear");   
	g_signal_connect (G_OBJECT (clrbtn), "clicked", G_CALLBACK (clrimg), img);
	gtk_box_pack_start (GTK_BOX (btnbox), clrbtn, FALSE, FALSE, 0);

	/*
	img = gtk_image_new_from_file ("gtk-logo-rgb.gif");
	gtk_container_add (GTK_CONTAINER (fme), GTK_WIDGET (img));
    */

	gtk_box_pack_end (GTK_BOX (vbox), btnbox, FALSE, FALSE, 0);
	gtk_box_pack_end (GTK_BOX (vbox), sep, FALSE, FALSE, 0);
	gtk_box_pack_end (GTK_BOX (vbox), fme, FALSE, FALSE, 0);

	gtk_container_add (GTK_CONTAINER (win), vbox);
	
	gtk_widget_show_all (win);
	gtk_main ();

	return 0;
}
