	</div>
</div><!-- #container -->
<div id="footer">
	<div class="pads">
		<ul id="menu-bottom" class="clearfix">
			<?php wp_nav_menu( array( 'theme_location' => 'primary-menu', 'sort_column' => 'menu_order', 'container_class' => 'nav' ) ); ?>
		</ul>
	</div>
	<div class="footerlinks">
<!-- #ici code -->
	</div>
</div><!-- #footer -->
<?php wp_footer() ?> <!-- #NE PAS SUPPRIMER cf. codex wp_footer() -->
</body>
</html>