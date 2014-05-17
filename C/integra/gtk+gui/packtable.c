# ident "demo of packing widgets with a table widget."

# include <stdio.h>
# include <stdlib.h>
# include <gtk/gtk.h>


static gboolean
delete_event(GtkWidget *w, GdkEvent *e, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}

static void 
callback( GtkWidget *widget, gpointer   data )
{
   g_print ("Hello again - %s was pressed\n", (char *) data);
}


int
main(int argc, char **argv)
{
	GtkWidget *win, *btn, *tbl;

	gtk_init(&argc, &argv);

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "packing with table widget");
	gtk_container_set_border_width(GTK_CONTAINER(win), 20);

	g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(delete_event), NULL);

	/* a 2x2 table */

	tbl = gtk_table_new(2, 2, TRUE);
	gtk_container_add(GTK_CONTAINER(win), tbl);

	btn = gtk_button_new_with_label("<1>");
	g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(callback), (gpointer) "button 1");
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 0, 1);
	gtk_widget_show(btn);

	btn = gtk_button_new_with_label("<2>");
	g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(callback), (gpointer) "button 2");
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 1, 2, 0, 1);
	gtk_widget_show(btn);


	btn = gtk_button_new_with_label("Quit");
	g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(delete_event), NULL);
	gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 2, 1, 2);
	gtk_widget_show(btn);

	gtk_widget_show_all(win);

	gtk_main();

	return 0;
}
