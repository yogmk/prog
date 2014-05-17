# ident "Demp of pixmapped button widget"

# include <stdio.h>
# include <gtk/gtk.h>

static void
callback(GtkWidget *w, gpointer data)
{
	g_print("Hello there...%s pressed\n", (char*) data);
}


static GtkWidget*
pix_label_box(char* file_name, char* label_text)
{
	GtkWidget *box, *lbl, *img;

	/* create box for image & label */

	box = gtk_hbox_new(FALSE, 0);
	gtk_container_set_border_width(GTK_CONTAINER(box), 2);

	img = gtk_image_new_from_file(file_name);
	lbl = gtk_label_new(label_text);

	gtk_box_pack_start(GTK_BOX(box), img, FALSE, FALSE, 3);
	gtk_box_pack_start(GTK_BOX(box), lbl, FALSE, FALSE, 3);

	gtk_widget_show(lbl);
	gtk_widget_show(img);

	return box;
}

int
main (int argc, char **argv)
{
	GtkWidget *win, *box, *btn;

	gtk_init(&argc, &argv);

	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(win), "Cool pix button");
	gtk_container_set_border_width(GTK_CONTAINER(win), 30);
	g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	
 	btn = gtk_button_new();
	g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(callback), (gpointer) "Cool button");

	box = pix_label_box("3DRings.xpm", "cool button");
	
	gtk_container_add(GTK_CONTAINER(btn), box);
	gtk_container_add(GTK_CONTAINER(win), btn);

	gtk_widget_show_all(win);

	gtk_main();

	return 0;

}
