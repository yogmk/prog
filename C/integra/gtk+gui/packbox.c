# ident "demo of usin Box container in GTK+"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <gtk/gtk.h>


static gboolean
delete_event(GtkWidget *w, GdkEvent *e, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}

static GtkWidget*
make_box(gboolean homogeneous, gint spacing,
         gboolean expand, gboolean fill, gint padding)
{
	GtkWidget *box, *button;
	char padstr[80];
	char lbl[15];

	box = gtk_hbox_new(homogeneous, spacing);     /* creats Box */

	button = gtk_button_new_with_label("box_pack_start");
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);


	button = gtk_button_new_with_label("(box, ");
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	
	button = gtk_button_new_with_label("button, ");
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	if (expand == TRUE)
		strcpy(lbl, "expand=<T>");
	else
		strcpy(lbl, "expand=<F>");
	button = gtk_button_new_with_label(lbl);
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	button = gtk_button_new_with_label(fill? "FILL=<T>, " : "FILL=<F>, ");
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

    sprintf(padstr, "%d", padding);
	button = gtk_button_new_with_label(padstr);
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	return box;
}



int
main(int argc, char *argv[])
{
	GtkWidget *win, *btn, *sep, *vbox, *hbox, *qbox, *lbl;
	int which;

	if (argc !=2)
	  {
	  	fprintf(stderr, "usage: packbox num, where num is 1, 2, or 3.\n");
		exit(1);
	  }
    which = atoi(argv[1]);
	
	gtk_init(&argc, &argv);
	
	/* set-up window */
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width(GTK_CONTAINER(win), 15);
	g_signal_connect(G_OBJECT(win), "delete_event",
	                 G_CALLBACK(delete_event), NULL);

	/*vbox = gtk_vbox_new(FALSE, 0); */
	vbox = gtk_vbox_new(TRUE, 0);

	switch(which)
		{
	  	case 1:
			lbl = gtk_label_new("gtk_hbox_new (FALSE, 0);");
			gtk_misc_set_alignment(GTK_MISC(lbl), 0, 0);
			gtk_box_pack_start(GTK_BOX(vbox), lbl, FALSE, FALSE, 0);
			gtk_widget_show(lbl);
			hbox = make_box (FALSE, 0, FALSE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);

			hbox = make_box (FALSE, 0, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
	
			hbox = make_box (FALSE, 0, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
	
			sep= gtk_hseparator_new ();
	
			gtk_box_pack_start (GTK_BOX (vbox), sep, FALSE, TRUE, 5);
			gtk_widget_show (sep);
	
			lbl = gtk_label_new ("gtk_hbox_new (TRUE, 0);");
			gtk_misc_set_alignment (GTK_MISC (lbl), 0, 0);
			gtk_box_pack_start (GTK_BOX (vbox), lbl, FALSE, FALSE, 0);
			gtk_widget_show (lbl);
	
			hbox = make_box (TRUE, 0, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
	
			hbox = make_box (TRUE, 0, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
	
			sep= gtk_hseparator_new ();

			gtk_box_pack_start (GTK_BOX (vbox), sep, FALSE, TRUE, 5);
			gtk_widget_show (sep);
				
			break;

		case 2:
			
			lbl = gtk_label_new ("gtk_hbox_new (FALSE, 10);");
			gtk_misc_set_alignment (GTK_MISC (lbl), 0, 0);
			gtk_box_pack_start (GTK_BOX (vbox), lbl, FALSE, FALSE, 0);
			gtk_widget_show (lbl);
			
			hbox = make_box (FALSE, 10, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
			
			hbox = make_box (FALSE, 10, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
			
			sep= gtk_hseparator_new ();
			gtk_box_pack_start (GTK_BOX (vbox), sep, FALSE, TRUE, 5);
			gtk_widget_show (sep);
			
			lbl = gtk_label_new ("gtk_hbox_new (FALSE, 0);");
			gtk_misc_set_alignment (GTK_MISC (lbl), 0, 0);
			gtk_box_pack_start (GTK_BOX (vbox), lbl, FALSE, FALSE, 0);
			gtk_widget_show (lbl);
			
			hbox = make_box (FALSE, 0, TRUE, FALSE, 10);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
			
			hbox = make_box (FALSE, 0, TRUE, TRUE, 10);
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
			
			sep= gtk_hseparator_new ();
			gtk_box_pack_start (GTK_BOX (vbox), sep, FALSE, TRUE, 5);
			gtk_widget_show (sep);
			break;

		case 3:
			hbox = make_box (FALSE, 0, FALSE, FALSE, 0);

			lbl = gtk_label_new ("end-|");
			gtk_box_pack_end (GTK_BOX (hbox), lbl, FALSE, FALSE, 0);
			gtk_widget_show (lbl);
			
			gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
			gtk_widget_show (hbox);
			
			sep= gtk_hseparator_new ();
	/* This explicitly sets the separator to 400 pixels wide by 5 pixels
	 * high. This is so the hbox we created will also be 400 pixels wide,
	 * and the "end" label will be separated from the other labels in the
	 * hbox. Otherwise, all the widgets in the hbox would be packed as
	 * close together as possible. */
			gtk_widget_set_size_request (sep, 400, 5);
			gtk_box_pack_start (GTK_BOX (vbox), sep, FALSE, TRUE, 5);
			gtk_widget_show (sep);    			
			break;
		}
	
	qbox = gtk_hbox_new(FALSE, 0);
	btn = gtk_button_new_with_label("Quit");

	g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(gtk_main_quit), G_OBJECT(win));
	
	gtk_box_pack_start(GTK_BOX(qbox), btn, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), qbox, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(win), vbox);

	gtk_widget_show_all(win);

	gtk_main();

	return 0;
}
