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
			echo '<img src="' . COLOUR_PATH . '/home.jpg" alt="Moksha Home" width="500" height="500" />';
			exit;
		}
		elseif($sectionName == 'contact')
		{
			include('contact.inc');
		}
		elseif($subsectionNameFromURL == 'haiti_project')
		{
			include('haiti_project.inc');
		}
		else
		{
			include('normal.inc');
		}
	?>

