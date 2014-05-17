#include <gtk/gtk.h>
#include <libintl.h>

#define _(x) gettext (x)
#define N_(x) (x)

#define GETTEXT_PACKAGE "gtk-hello"
#define LOCALEDIR "mo"

static char *greetings[] = { "Hello World",
			     "Witaj .wiecie",
			     "......" };

static char* choose_greeting ()
{
  return greetings[g_random_int_range (0, G_N_ELEMENTS (greetings))];
}

static void cb_button_click(GtkButton *button, gpointer data)
{
  GtkWidget *label = GTK_WIDGET(data);

  g_assert(label != NULL);
  gtk_label_set_text(GTK_LABEL (label), choose_greeting());
}

static gboolean cb_delete(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
  return FALSE;
}

int main (int argc, char *argv[])
{
  GtkWidget* window, *button, *label, *vbox;
  
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);

  gtk_init(&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  button = gtk_button_new_with_label (_("Hello World"));
  label = gtk_label_new (choose_greeting());
  vbox = gtk_vbox_new(FALSE, 0);

  gtk_container_add(GTK_CONTAINER (window), vbox);
  gtk_container_add(GTK_CONTAINER (vbox), label);
  gtk_container_add(GTK_CONTAINER (vbox), button);

  g_signal_connect(G_OBJECT (window), "delete-event", 
		   G_CALLBACK(cb_delete), NULL);

  g_signal_connect (G_OBJECT (button), "clicked", 
		    G_CALLBACK (cb_button_click), label);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
