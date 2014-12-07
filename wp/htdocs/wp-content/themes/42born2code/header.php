<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" <?php language_attributes() ?>>
<head profile="http://gmpg.org/xfn/11">

<meta http-equiv="content-type" content="<?php bloginfo('html_type') ?>; charset=<?php bloginfo('charset') ?>" />
<meta name="description" content="" />
<meta name="keywords" content="" />
<title><?php wp_title( '-', true, 'right' ); echo wp_specialchars( get_bloginfo('name'), 1 ) ?></title>
<link rel="stylesheet" href="<?php bloginfo('stylesheet_directory'); ?>/style.css" type="text/css" media="screen" />

	<!--[if lte IE 6]><script type="text/javascript" src="<?php bloginfo('template_url'); ?>/js/supersleight-min.js"></script><![endif]-->
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/jquery.js'); ?>
<?php wp_enqueue_script('superfish', get_bloginfo('template_directory').'/js/superfish.js', array('jquery'), '1.7'); ?>
<?php wp_enqueue_script(get_bloginfo('template_directory').'/js/nav.js'); ?>
<?php if (trim(get_option('ft_header_code')) <> "") { echo stripslashes(get_option('ft_header_code')); } ?>
<?php if (is_singular()) wp_enqueue_script('comment-reply'); ?>

<?php wp_head(); ?> <!-- #NE PAS SUPPRIMER cf. codex wp_head() -->
</head>
<body <?php body_class() ?>>
	<div id="header" class="header_ft">
		<a class="logo_airbnb">
			<img class="site-logo" src="<?php bloginfo('template_directory'); ?>/images/logo_airbnb.png" alt="<?php bloginfo('name'); ?>" />
		</a>
		<div class="box_btn_header">
		<?php if ( !is_user_logged_in() ) { ?>
    	<a class="button_ft" href="">Se connecter</a>
		<?php ;}else {?>
    	<a class="button_ft" href="">Se deconnecter</a>
    	<?php ;} ?>	
		<a class="button_ft" href="#">S'enregistrer</a>
		<a class="publication href="#"">Publiez votre annonce</a>
		</div>
	</div>
	<div class="hero_wrapper_ft">
		<div class="hero_ft">
		</div>
		<div class="search_area_ft">
			<div class="page_container_ft">
				<div class="intro_area_ft">
					<div class=col_ft>
						<h1 class="uppercase_ft">Bienvenue à la maison</h1>
						<div class="subtitle_ft">Louez des logements uniques auprès d'hôtes locaux dans 190+ pays.</div>
						<a class="btn btn_manual" href="#">Mode d'emploi</a>
					</div>
					<div class=bottom_search_area_ft>
						<div class="col_12_ft">
							<div class="searchbox"><?php include('searchform.php'); ?></div>
						</div>
					</div>
					</div>
				</div>
			</div >
		</div>
	</div>
				<!-- my class -->
	<div id="container">
	</div>
	<div class="pads clearfix">
	</div>
</div>
