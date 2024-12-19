#include <gtk/gtk.h>


void
on_treeviewServiceHome_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonRechercheService_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonAjouterServiceW_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonModifierServiceW_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonSupprimerServiceW_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonActualiserServiceW_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonStatistiqueServiceW_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnAjoutService_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelAjoutService_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radioTypeBaseAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioTypePremiumAjoutService_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkDispoOuiAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkDispoNonAjoutService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btnModifService_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelModifService_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_radioTypeBaseModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioTypePremiumModifService_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkDispoNonModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkDispoOuiModifService_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btnRechercheModifService_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelSupService_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnSupService_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnAffecService_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnCancelAffecService_clicked       (GtkButton       *button,
                                        gpointer         user_data);
