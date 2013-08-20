<?php

	//declare constants
	define(PAGE, 'index.php?pageId=');
	define(SECTION, '&section=');
	define(SUBSECTION, '&subsection=');
	define(INCLUDE_PATH, 'includes/');
	define(IMAGES_PATH, 'images/');
	define();

	//declare page variables
	$pages = array();

	//homepage
	$page = array('pageTitle' => 'MOKSHA - Home', 
				  'bodyColour' => 'whiteBody', 
				  'logo' => 'moksha_white_sml.jpg', 
				  'imageFilename' => COMMERCIAL_PATH.'com_home.jpg',
				  'imageDescription' => 'Moksha home page image',
				  'numberOfImageNavBoxes' => '',
				  'imageNavSelection' => '');
	//add to pages array
	array_push($pages, $page);

	//documentary home
	$page = array('pageTitle' => 'MOKSHA - Documentary', 
				  'bodyColour' => 'blackBody', 
				  'logo' => 'moksha_black_sml.jpg', 
				  'documentaryLink' => 'current_section', 
				  'subNav' => '',
				  'subNavSelection' => '',
				  'imageFilename' => DOCUMENTARY_PATH.'doc_home.jpg',
				  'imageDescription' => 'Moksha documentary home page');
	//add to pages array
	array_push($pages, $page);
	define(DOCUMENTARY_HOME_ID, count($pages)-1);

	//commercial home
	$page = array('pageTitle' => 'MOKSHA - Commercial', 
				  'bodyColour' => 'whiteBody', 
				  'logo' => 'moksha_white_sml.jpg', 
				  'commercialLink' => 'current_section', 
				  'subNav' => '',
				  'subNavSelection' => '',
				  'imageFilename' => COMMERCIAL_PATH.'com_home.jpg',
				  'imageDescription' => 'Moksha commercial home page',
				  'numberOfImageNavBoxes' => '',
				  'imageNavSelection' => '');
	//add to pages array
	array_push($pages, $page);
	define(COMMERICAL_HOME_ID, count($pages)-1);

	//contact page
	$page = array('pageTitle' => 'MOKSHA - Contact', 
				  'logo' => 'moksha_white_sml.jpg', 
				  'bodyColour' => 'whiteBody', 
				  'contactLink' => 'current_section');
	//add to pages array
	array_push($pages, $page);
	define(CONTACT_ID, count($pages)-1);
?>