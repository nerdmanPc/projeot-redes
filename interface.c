#include <stdio.h>
#include <gtk/gtk.h>

static void enviar_arquivo();
static void receber_arquivo();

static void abrir_window_menu(GtkWidget *dummy, gpointer widget);
static void abrir_window_enviar(GtkWidget *dummy, gpointer widget);
static void abrir_window_receber(GtkWidget *dummy, gpointer widget);
gboolean destroy (GtkWidget *window);
GtkBuilder *builder; 


int main (int argc, char *argv[]){
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    gtk_builder_add_from_file (builder, "main.glade", NULL);
    abrir_window_menu(NULL, NULL);

    gtk_main ();
    return 0;
}

static void abrir_window_menu(GtkWidget *dummy, gpointer widget) {
    if (widget != NULL) {
        destroy(widget);
    }

    GtkWidget *window, *button;

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_menu_enviar"));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (abrir_window_enviar), (gpointer) window);
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_menu_receber"));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (abrir_window_receber), (gpointer) window);

    gtk_widget_show(window);
}

static void abrir_window_enviar(GtkWidget *dummy, gpointer widget) {
    destroy(widget);

    GtkWidget *window, *button;

    gtk_builder_add_from_file (builder, "main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_enviar"));

    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_enviar"));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (enviar_arquivo), (gpointer) window);
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_voltar"));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (abrir_window_menu), (gpointer) window);

    gtk_widget_show(window);

}

static void abrir_window_receber(GtkWidget *dummy, gpointer widget) {
    destroy(widget);

    GtkWidget *window, *button;

    gtk_builder_add_from_file (builder, "main.glade", NULL);

    // TO DO
    // window = GTK_WIDGET(gtk_builder_get_object(builder, "window_receber"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_enviar"));

    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_enviar"));
    // TO DO
    // g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (receber_arquivo), (gpointer) window);
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (enviar_arquivo), (gpointer) window);
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btn_voltar"));
    g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (abrir_window_menu), (gpointer) window);

    gtk_widget_show(window);

}

gboolean destroy (GtkWidget *widget){
    gtk_widget_destroy (widget);
    return TRUE;
}

static void enviar_arquivo(){ 
    // TO DO
    g_print("ENVIAR ARQUIVO\n");
}

static void receber_arquivo(){ 
    // TO DO
    g_print("ENVIAR ARQUIVO\n");
}
