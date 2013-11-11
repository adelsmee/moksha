
<?php
	require_once('includes/variables.inc');

	//get page id
	if(isset($_GET['section']))
	{
		$section = $_GET['section'];
		$subsection = $_GET['subsection'];
		$currentImageNumber = $_GET['currentImageNumber'];

		$sectionArray = explode(' ', $section);
		$sectionColour = $sectionArray[COLOUR];
		
		$pageTitle = $sectionArray[NAME];
		if(isset($subsection))
		{
			$subsectionArrayForTitle = explode(' ', $subsection);
			$subsectionArrayForTitle = str_replace('_', ' ', $subsectionArrayForTitle);
			$pageTitle .= ' - ' . $subsectionArrayForTitle[NAME];
		}
	}
	else
	{
		$section = 0;
		$sectionColour = "white";
		$pageTitle = "moksha";
	}
	
	define(COLOUR_PATH, SITE_IMAGES_PATH . $sectionColour);
	
	include_once(INCLUDE_PATH.'header.inc');

	include_once(INCLUDE_PATH.'index-navigation.inc');
	
	include_once(INCLUDE_PATH.'content.inc');

	include_once(INCLUDE_PATH.'footer.inc');
?>