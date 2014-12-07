<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier contient les réglages de configuration suivants : réglages MySQL,
 * préfixe de table, clefs secrètes, langue utilisée, et ABSPATH.
 * Vous pouvez en savoir plus à leur sujet en allant sur 
 * {@link http://codex.wordpress.org/fr:Modifier_wp-config.php Modifier
 * wp-config.php}. C'est votre hébergeur qui doit vous donner vos
 * codes MySQL.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d'installation. Vous n'avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en "wp-config.php" et remplir les
 * valeurs.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define('DB_NAME', 'db_database');

/** Utilisateur de la base de données MySQL. */
define('DB_USER', 'root');

/** Mot de passe de la base de données MySQL. */
define('DB_PASSWORD', 'cyberbob');

/** Adresse de l'hébergement MySQL. */
define('DB_HOST', 'localhost');

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define('DB_CHARSET', 'utf8');

/** Type de collation de la base de données. 
  * N'y touchez que si vous savez ce que vous faites. 
  */
define('DB_COLLATE', '');

/**#@+
 * Clefs uniques d'authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant 
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clefs secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n'importe quel moment, afin d'invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '@y>#ftRyZ-|^{tyO(oM>>-Wn)9_k_5Z{j2k9ffK!-iu%*8gl.)W%?pUXGx@lt._?');
define('SECURE_AUTH_KEY',  'vH,H|-gOxbK&59xu@XO3.+NEK#t]1ov+~m16[cy6u;fz#isID.wxCX5JyE/F%sz`');
define('LOGGED_IN_KEY',    'Pcf(|nX[9UW<8%m0x?rU-a~F]9{<FF8:fW=4-A#&--*fYWecx_QVANJ@/?2K3C,r');
define('NONCE_KEY',        '.2E(=)+!W+f2|vI&p2R2&N9NU,JTi1WkAPV{Z*JDK;>lmS:)DSO1/#4mj:!/ZgK{');
define('AUTH_SALT',        '(TAOg?bfXQR[h^^*@*-yZ*;v(^w4Zn8F,;!N#bu`U@ug:5a#)5zZ8h,v]Lvl0g&%');
define('SECURE_AUTH_SALT', 'FO)&GxiT9f_[8Cg4/fa1[^|&r~<cL:I)gQJsa^]}Sy&V|WpN#p5.(q[a1nn+6T/U');
define('LOGGED_IN_SALT',   '?b!-4g!Z4G+x.4;)[Y!F~78$.kCA yi3<_*9?(* u6*}+yCM,pf+!*Wm+d>wd@Bi');
define('NONCE_SALT',       'wdwNO_DC%a =R3[4&6b:a(szYxHM Jg-Jvfn9Q]`[?u::&Ft(Pm4j#b*NZ/>p=>=');
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique. 
 * N'utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés!
 */
$table_prefix  = 'wp_';

/** 
 * Pour les développeurs : le mode deboguage de WordPress.
 * 
 * En passant la valeur suivante à "true", vous activez l'affichage des
 * notifications d'erreurs pendant votre essais.
 * Il est fortemment recommandé que les développeurs d'extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de 
 * développement.
 */ 
define('WP_DEBUG', false); 

/* C'est tout, ne touchez pas à ce qui suit ! Bon blogging ! */

/** Chemin absolu vers le dossier de WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once(ABSPATH . 'wp-settings.php');