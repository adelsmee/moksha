<ul id="nav_text_right">
	<?php 
		if(is_dir(SECTION_PATH.$section))
		{
			$handle = opendir(SECTION_PATH.$section); 
			
			while (false !== ($file = readdir($handle))) 
			{
	    		if ($file =="." | $file =="..") 
	    		{			    
	    			continue;
	    		}
	    	
	    		$subsectionFromDir = $file;
			    $subsectionData = explode(' ', $subsectionFromDir);
				$subsectionOrder = $subsectionData[ORDER];
			    $subsectionName = $subsectionData[NAME];
			    $subsectionName = str_replace('_', ' ', $subsectionName);
	
			    if(ctype_digit($subsectionOrder))
				{
					if($subsectionFromDir == $subsection)
					{
						$currentSubsection = "current_section";
					}
					else
					{
						$currentSubsection = "#";
					}
					
		            echo '<li><a href="'. PAGE . $section . SUBSECTION . $subsectionFromDir . CURRENT_IMAGE.'1" class="'.$currentSubsection.'">'.$subsectionName.'</a></li>';
				}
			}
		}
	?>
</ul>
 