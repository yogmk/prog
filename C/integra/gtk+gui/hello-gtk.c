# include <gtk/gtk.h>

static void hello(GtkWidget*, gpointer);
static gboolean delete_event(GtkWidget*, GdkEvent*, gpointer);
static void destroy(GtkWidget*, gpointer);

int
main (int argc, char **argv)
{
	GtkWidget *window, *button;

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	/*
	 * events are handled in the order they are attached 
	 * to a widget. If first signal returns FALSE only then
	 * subsequent signal handler is invoked, otehrwise not.
	*/
	g_signal_connect(G_OBJECT(window), "delete_event",
	                 G_CALLBACK(delete_event), NULL);

	g_signal_connect(G_OBJECT(window), "destroy",
	                 G_CALLBACK(destroy), NULL);

	button = gtk_button_new_with_label("Hello GTK+");

	g_signal_connect(G_OBJECT(button), "clicked",
	                 G_CALLBACK(hello), NULL);

	//g_signal_connect_swapped (G_OBJECT(button), "clicked", \
	                          G_CALLBACK(gtk_widget_destroy),\
							  G_OBJECT(window));

	gtk_container_add (GTK_CONTAINER(window), button);

	gtk_widget_show(window);
	gtk_widget_show(button);

	gtk_main();

	return 0;

}


static void
hello (GtkWidget *wind, gpointer data)
{
	g_print("Hello GTK+ world!");
	//fprintf(stderr, "Hello GTK+ world!\n");
}


static gboolean 
delete_event(GtkWidget *win, GdkEvent *event, gpointer data)
{
	g_print("delete event occurred!");
	//fprintf(stderr, "delete event occurred!\n");
	return FALSE;
}


static void
destroy(GtkWidget *win, gpointer data)
{
	g_print("destroying window..");
	//fprintf(stderr, "destroying window..\n");
	gtk_main_quit();
}
