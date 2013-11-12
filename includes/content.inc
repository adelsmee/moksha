	<div id="contentCentre">
	<?php
	    $sectionFromURL = $section;
	    $sectionData = explode(' ', $sectionFromURL);
	    $sectionName = $sectionData[NAME];
	    $subsectionFromURL = $subsection;
	    $subsectionData = explode(' ', $subsectionFromURL);
	    $subsectionNameFromURL = $subsectionData[NAME];
	    
	    if($section == 0)
		{
			echo '<img src="' . COLOUR_PATH . '/home.jpg" alt="Moksha Home" width="990px" height="560px" />';
			exit;
		}
		elseif($sectionName == 'Contact')
		{
			include('contact.inc');
		}
		else
		{
			include('normal.inc');
		}
	?>

