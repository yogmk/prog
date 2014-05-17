# include <gtk/gtk.h>

static void callback(GtkWidget*, gpointer);
static gboolean delete_event (GtkWidget*, GdkEvent*, gpointer);


int 
main(int argc, char*argv[])
{
	GtkWidget *window, *button, *box;	

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hello GTK+");
	gtk_container_set_border_width(GTK_CONTAINER(window), 6);

	g_signal_connect(G_OBJECT(window), "delete_event",
	                 G_CALLBACK(delete_event), NULL);
	
	box = gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), box);
	
	button = gtk_button_new_with_label("Button #1");
	g_signal_connect(G_OBJECT(button), "clicked",
	                 G_CALLBACK(callback), (gpointer) "button #1");
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
	gtk_widget_show(button);


	button = gtk_button_new_with_label("Button #2");
	g_signal_connect(G_OBJECT(button), "clicked",
	                 G_CALLBACK(callback), (gpointer) "button #2");
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
	gtk_widget_show(button);

	button = gtk_button_new_with_label("<close>");
	g_signal_connect(G_OBJECT(button), "clicked",
	                 G_CALLBACK(callback), (gpointer) "<close>");
	g_signal_connect(G_OBJECT(button), "clicked",
	                 G_CALLBACK(delete_event), NULL);
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);
	gtk_widget_show(button);

    gtk_widget_show(box);
	gtk_widget_show(window);

	gtk_main();

	return 0;
}




static void
callback(GtkWidget *w, gpointer data)
{
	g_print("Hello again... %s was pressed.\n", (char*) data);
}

static gboolean
delete_event(GtkWidget *w, GdkEvent *e, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}
