# include <gtk/gtk.h>

static int cb_delete_event(GtkWidget*, GdkEventAny*, gpointer);
static void cb_button_clicked(GtkWidget*, gpointer);


int
main(int argc, char *argv[])
{
	GtkWidget *w, *b1, *b2, *l1, *l2;		/* window, button & label */

	gtk_init(&argc, &argv);

	w = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	b1 = gtk_button_new ();
	//b2 = gtk_button_new ();
	l1 = gtk_label_new ("Hello world");
	//l2 = gtk_label_new ("Close");


	gtk_container_add(GTK_CONTAINER(b1), l1);
	//gtk_container_add(GTK_CONTAINER(b2), l2);
	gtk_container_add(GTK_CONTAINER(w), b1);
	//gtk_container_add(GTK_CONTAINER(w), b2);

    gtk_window_set_title(GTK_WINDOW(w), "hello");
	gtk_container_set_border_width(GTK_CONTAINER(b1), 10);
	//gtk_container_set_border_width(GTK_CONTAINER(b2), 10);

	gtk_signal_connect(G_OBJECT(w), "delete_event",
	                   GTK_SIGNAL_FUNC(cb_delete_event),
					   NULL);
	
	gtk_signal_connect(G_OBJECT(b1), "clicked",
	                   GTK_SIGNAL_FUNC(cb_button_clicked),
					   l1);
	
	//gtk_signal_connect(G_OBJECT(b2), "clicked",	    /* when b2 is clicked, "Exit" */
	//                   GTK_SIGNAL_FUNC(cb_delete_event),
//					   NULL);

	gtk_widget_show_all(w);

	gtk_main();

	return 0;
}



static int
cb_delete_event(GtkWidget *w, GdkEventAny *e, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}


static void
cb_button_clicked(GtkWidget *w, gpointer data)
{
	GtkWidget * label;
	gchar *text, *temp;

	label = GTK_WIDGET(data);

	gtk_label_get(GTK_LABEL(label), &text);

	temp = g_strdup(text);
	g_strreverse(temp);
	gtk_label_set_text(GTK_LABEL(label), temp);

	g_free(temp);
}
