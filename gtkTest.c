#include <gtk/gtk.h>

GtkWidget	*btTest;
GtkWidget	*drawTest;

int flag = 0;
void on_btTest_clicked(void)
{

	flag = 1;
	gtk_widget_queue_draw(drawTest);
	printf("Redraw\n");

}
gboolean on_drawTest_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
	guint width, height;
	GdkRGBA color;
	GtkStyleContext *context;

	context = gtk_widget_get_style_context (widget);

	width = gtk_widget_get_allocated_width (widget);
	height = gtk_widget_get_allocated_height (widget);

	gtk_render_background (context, cr, 0, 0, width, height);

	//cairo_image_surface_create_from_p

	if(flag)
		cairo_rectangle(cr, 0.0, 0.0, 159.0, 127.0);

	cairo_arc (cr,
			width / 2.0, height / 2.0,
			MIN (width, height) / 2.0,
			0, 2 * G_PI);
	//cairo_rectangle(cr, 0.0, 0.0, 159.0, 127.0);

	cairo_move_to(cr, 0, 0);
	cairo_line_to(cr, 159, 0);

	gtk_style_context_get_color (context,
			gtk_style_context_get_state (context),
			&color);
	color.red = 255;
	gdk_cairo_set_source_rgba (cr, &color);

	cairo_fill (cr);

	return FALSE;
}

int main (int argc, char **argv)
{

	GtkBuilder      *builder;
	GtkWidget       *window;


	GtkApplication *app;
	int status;

  	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "gtkTest.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "wndMain"));
	gtk_builder_connect_signals(builder, NULL);

	drawTest = GTK_WIDGET(gtk_builder_get_object(builder, "drawTest"));
      // get pointers to the two labels
      /*g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
      g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));*/

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}
