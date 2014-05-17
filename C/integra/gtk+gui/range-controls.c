# ident " Demo of GTK+ range control widgets."

GtkWidget *hscale, *vscale;

	/* set the value position on both widgets */
static void
cb_set_position (GtkWidget *wgt, GtkPositionType pos)
{
	gtk_scale_set_value_pos (GTK_SCALE(vscale), pos);
	gtk_scale_set_value_pos (GTK_SCALE(hscale), pos);
}


	/* set the update policy for both widgets */

static void
cb_set_update_policy (GtkWidget *wgt, GtkUpdateType policy)
{
	gtk_range_set_update_policy (GTK_RANGE(hscale), policy);
	gtk_range_set_update_policy (GTK_RANGE(vscale), policy);
}


static void cb_digits_scale( GtkAdjustment *adj )
{
    /* Set the number of decimal places to which adj->value is rounded */
    gtk_scale_set_digits (GTK_SCALE (hscale), (gint) adj->value);
    gtk_scale_set_digits (GTK_SCALE (vscale), (gint) adj->value);
}

static void cb_page_size( GtkAdjustment *get,
                          GtkAdjustment *set )
{
    /* Set the page size and page increment size of the sample
     * adjustment to the value specified by the "Page Size" scale */
    set->page_size = get->value;
    set->page_increment = get->value;

    /* This sets the adjustment and makes it emit the "changed" signal to 
       reconfigure all the widgets that are attached to this signal.  */
    gtk_adjustment_set_value (set, CLAMP (set->value,
					  set->lower,
					  (set->upper - set->page_size)));
    g_signal_emit_by_name(G_OBJECT(set), "changed");
}
