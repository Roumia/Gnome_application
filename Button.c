#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
     gpointer   data)
{
  g_print ("Desktop application -----   :* \n");
}

 static void
open_image (GtkButton *button, gpointer user_data)
{
	GtkWidget *image ;
    GtkWidget *window;

    image = gtk_image_new_from_file ("logoURJC.png");

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_container_add (GTK_CONTAINER (window), image);

    gtk_widget_show_all (window);
}

int
main (int   argc,char *argv[])
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;


  gtk_init (&argc, &argv);  /* Called in all GTK applications */

  /* create a  window */

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "MSWL windows");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER (window), 100);

  
  grid = gtk_grid_new (); /*  container for buttons */

  gtk_container_add (GTK_CONTAINER (window), grid);

  button = gtk_button_new_with_label ("Try me ");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

 button = gtk_button_new_with_label ("URJC   logo");
 g_signal_connect (button, "clicked", G_CALLBACK (open_image), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 1, 1, 1);

  button = gtk_button_new_with_label ("Quit!");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);


  gtk_grid_attach (GTK_GRID (grid), button, 1, 2,1,1);
  gtk_widget_show_all (window);

  gtk_main ();

  return 0;
}

