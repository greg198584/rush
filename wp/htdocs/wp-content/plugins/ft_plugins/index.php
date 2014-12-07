<?php

/*
 * 	Plugin Name: mon super plugin de fou
 * Description:	description du plugin
 * License:		GPL ...
 * 	Author		GLAFITTE
 * 	Version		1.0
 * */
function fb_add_custom_user_profile_fields( $user ) { //on ajoute les donnees ici
?>
    <h3><?php _e('MORE INFOS', 'your_textdomain'); ?></h3>
    <table class="form-table">
        <tr>
        <th>
        <label for="address"><?php _e('Address', 'your_textdomain'); ?></label>
        </th>
        <td>
        <input type="text" name="address" id="address" value="<?php echo esc_attr( get_the_author_meta( 'address', $user->ID ) ); ?>" class="regular-text" /><br />
        <span class="description">
        <?php _e('DECRIPTION DU CHAMP', 'your_textdomain'); ?>
        </span>
        </td>
        </tr>
    </table>
<?php }

function fb_save_custom_user_profile_fields( $user_id ) { //on sauvegarde les donnees ici

	    if ( !current_user_can( 'edit_user', $user_id ) )
			        return FALSE;

		update_usermeta( $user_id, 'address', $_POST['address'] );
}

	add_action( 'show_user_profile', 'fb_add_custom_user_profile_fields' );
	add_action( 'edit_user_profile', 'fb_add_custom_user_profile_fields' );

	add_action( 'personal_options_update', 'fb_save_custom_user_profile_fields' );
	add_action( 'edit_user_profile_update', 'fb_save_custom_user_profile_fields' );
?>
