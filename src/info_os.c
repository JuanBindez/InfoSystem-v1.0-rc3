#include <stdio.h>
#include <gtk/gtk.h>

void exibirInformacoesSO(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;

    FILE *cmd = popen("uname -a", "r");
    if (cmd == NULL) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Erro ao obter informações do sistema operacional.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
        return;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), cmd);

    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Informações do Sistema Operacional:\n%s", buffer);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    pclose(cmd);
}
