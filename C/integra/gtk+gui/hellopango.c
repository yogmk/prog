 /* copy+pasted from tutorial */

 #include <gtk/gtk.h>
 #include <stdlib.h>
 #include <string.h>
 
 gint eventDelete(GtkWidget *widget, GdkEvent *event,gpointer data)
   {
     return(FALSE);
   }
 
 gint eventDestroy(GtkWidget *widget, GdkEvent *event,gpointer data)
   {
     gtk_main_quit();
     return(0);
   }
 
 
 int main(int argc, char *argv[])
   {
     GtkWidget *window;
     GtkWidget *label;
     gchar *str = "<u>abc </u><span foreground=\"blue\"><u>de </u>"
       ".. ...</span> fg hijklm";
     gchar *text;
     PangoAttrList *attrs;
 
     gtk_init(&argc,&argv);
 
     pango_parse_markup (str, -1,0, &attrs, &text, NULL, NULL);
 
     label = gtk_label_new(text);
     gtk_label_set_attributes(GTK_LABEL(label), attrs);
 
     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
     gtk_container_add(GTK_CONTAINER(window), label);
     gtk_window_set_title (GTK_WINDOW (window), "Pango Label");
     gtk_container_set_border_width(GTK_CONTAINER(window), 30);
     gtk_widget_show_all(window);
 
     gtk_signal_connect(GTK_OBJECT(window), "delete_event",
             GTK_SIGNAL_FUNC(eventDelete), NULL);
     gtk_signal_connect(GTK_OBJECT(window), "destroy",
             GTK_SIGNAL_FUNC(eventDestroy), NULL);
     
     gtk_main();
     exit(0);
   }
