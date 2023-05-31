#include <stdio.h>
#include <gtk/gtk.h>

// Função para exibir a temperatura do sistema
void exibirTemperaturaSistema(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;

    // Comando 'sensors' para obter a temperatura do sistema
    FILE *cmd = popen("sensors", "r");
    if (cmd == NULL) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Erro ao obter a temperatura do sistema.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), cmd) != NULL) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", buffer);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }

    pclose(cmd);
    gtk_widget_destroy(widget);  // <--- Linha corrigida
    g_free(data);  // <--- Linha corrigida
}
