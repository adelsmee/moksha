

	<div id="contentLeft"> 
		<a href="index.php" id="logo_nav"> 
			<img src="<?php echo COLOUR_PATH.'/logo.jpg'; ?>" alt="moksha logo" /> 
		</a> 
		photography by <br />
        <span class="<?php echo $sectionColour; ?>Shadow">christina simons</span>
        <ul id="nav_text_commercial">
		<?php 
			$sectionHandle = opendir(SECTION_PATH); 
			$sectionDirNames = array();	
			while (false !== ($sectionFile = readdir($sectionHandle))) 
			{
	    		if (strpos($sectionFile, '.') === 0) 
	    		{	
					continue;
			    }
			    
			    $sectionDirNames[] = $sectionFile;
			}


			asort($sectionDirNames);

			foreach ($sectionDirNames as $sectionFromDir) 
			{
			    $sectionData = explode(' ', $sectionFromDir);
			    $sectionName = $sectionData[NAME];
				$sectionOrder = $sectionData[ORDER];
			    if($sectionFromDir == $section)
				{
					$currentSection = 'current_section';
				}
				else
				{
					$currentSection = '#';
				}
			    
        		echo '<li><a href="'. PAGE . $sectionFromDir . '" class="' . $currentSection . '">'. $sectionName . '</a>';
        		
				if($sectionFromDir == $section)
				{
	        		if(strlen($section) > 1)
	        		{
	        			include('section-navigation.inc');
	        		}
				}
				
				echo '</li>';
			}
		?>
        </ul>
    </div><!-- end contentLeft div -->