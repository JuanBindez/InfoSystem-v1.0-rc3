/*
 * InfoSystem: show informations of the operation system.
 * Release: v1.0-rc1
 * 
 * Copyright © 2023  Juan Bindez  <juanbindez780@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "src/info_so.h"
#include "src/info_cpu.h"
#include "src/info_gpu.h"
#include "src/temp_system.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Informações do Sistema");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(window, 400, 300);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    button = gtk_button_new_with_label("Informações do Sistema Operacional");
    g_signal_connect(button, "clicked", G_CALLBACK(exibirInformacoesSO), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

    button = gtk_button_new_with_label("Informações da CPU");
    g_signal_connect(button, "clicked", G_CALLBACK(exibirInformacoesCPU), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("Informações da GPU");
    g_signal_connect(button, "clicked", G_CALLBACK(exibirInformacoesGPU), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    button = gtk_button_new_with_label("Temperatura do Sistema");
    g_signal_connect(button, "clicked", G_CALLBACK(exibirTemperaturaSistema), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
