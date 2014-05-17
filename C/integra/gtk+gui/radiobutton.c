# ident "demo of GTK Radio buttons."

# include <gtk/gtk.h>
# include <glib.h>


static gboolean
close_application(GtkWidget *w, GdkEvent *e, gpointer data)
{
   gtk_main_quit ();
   return FALSE;
}



int 
main (int argc, char **argv)
{
	GtkWidget *win, *btn, *vbox1, *vbox2, *sep;
	GSList *group;

	gtk_init (&argc, &argv);

	win = g_object_connect (gtk_widget_new (GTK_TYPE_WINDOW, 
	                        "title", "Radio buttons",
							"border_width", 20,
							"allow_grow", TRUE,
							"allow_shrink", TRUE,
							NULL),
							"signal::destroy", close_application,
							NULL, NULL);
	
	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER(win), vbox1);
	gtk_widget_show (vbox1);


	vbox2 = gtk_vbox_new (FALSE, 0);
	gtk_container_set_border_width (GTK_CONTAINER(vbox2), 10);
	gtk_box_pack_start (GTK_BOX(vbox1), vbox2, TRUE, TRUE, 0);
	gtk_widget_show (vbox2);

    btn = gtk_radio_button_new_with_label (NULL, "option 1");
	gtk_box_pack_start (GTK_BOX(vbox2), btn, TRUE, TRUE, 0);
	gtk_widget_show (btn);

	group = gtk_radio_button_get_group (GTK_RADIO_BUTTON(btn));
	btn = gtk_radio_button_new_with_label (group, "option 2");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(btn), TRUE);
	gtk_box_pack_start (GTK_BOX(vbox2), btn, TRUE, TRUE, 0);
	gtk_widget_show (btn);

	btn = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON(btn), "option 3");
	gtk_box_pack_start (GTK_BOX(vbox2), btn, TRUE, TRUE, 0);
	gtk_widget_show (btn);


    sep = gtk_hseparator_new ();
	gtk_box_pack_start (GTK_BOX(vbox1), sep, FALSE, TRUE, 0);
	gtk_widget_show (sep);

    vbox2 = gtk_vbox_new (FALSE, 10);
	gtk_container_set_border_width (GTK_CONTAINER(vbox2), 10);
	gtk_box_pack_start (GTK_BOX(vbox1), vbox2, FALSE, TRUE, 0);
	gtk_widget_show (vbox2);
	
    btn = gtk_button_new_with_label ("Close");
	g_signal_connect_swapped (G_OBJECT(btn), "clicked",
	                          G_CALLBACK(close_application), 
							  G_OBJECT(win));
	gtk_box_pack_start (GTK_BOX(vbox2), btn, TRUE, TRUE ,0);
	GTK_WIDGET_SET_FLAGS (btn, GTK_CAN_DEFAULT);
	gtk_widget_grab_default (btn);
	gtk_widget_show_all (win);

	gtk_main ();

	return 0;

}
