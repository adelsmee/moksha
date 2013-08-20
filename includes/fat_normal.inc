<?php 	
	$currentDir = SECTION_PATH.$section.'/'.$subsection;
	$handle = opendir($currentDir); 
	$imageCount = 0;
	$imageFilename = '';
	
	while (false !== ($file = readdir($handle))) 
	{
	    if ($file =="." | $file =="..") 
	    {
	        continue;
	    }
	    
	    $nextFilename = $file;
		$filePieces = explode('.', $nextFilename);
		
	    $filename = $filePieces[0];
	    $fileExtension = $filePieces[1];
	    
	    if($fileExtension === 'jpg')
	    {
	    	$imageCount++;
	    	$imageDescription = '';
	    }

	}
	
	if(isset($currentImageNumber))
	{
		$currentImage = $currentImageNumber . '.jpg';
		$showBoxes = true;

		//if the main image exists
		if(file_exists($currentDir . '/' . $currentImage))
		{
			//set image text if there is one
			$imageTextFile = $currentImageNumber . '.txt';
			if(file_exists($currentDir . '/' . $imageTextFile))
			{
				$imageText = nl2br(file_get_contents($currentDir . '/' . $imageTextFile));
			}
		}
		//otherwise display the intro text
		else
		{
			$introTextFile = $currentImageNumber . '.txt';
			if(file_exists($currentDir . '/' . $introTextFile))
			{
				$introText = nl2br(file_get_contents($currentDir . '/' . $introTextFile));
			}
		}
	}
	else
	{
		$currentImage = 'home.jpg';
		$showBoxes = false;
	}
	
	if(isset($introText))
	{
?>
		<div class="introText"><?php echo $introText; ?></div>
<?php
	}
	else
	{
?>
		<img src="<?php echo $currentDir. '/' . $currentImage; ?>" alt="<?php echo ''; ?>" width="990" height="560" />
<?php
	}
?>
	</div>
<div id="contentRight">
	<ul id="nav_box">
		<?php 
		if($showBoxes)
		{
		
	  		for($count = 1 ; $count <= $imageCount ; $count++)
	  		{
	  			if($count == $currentImage)
	  			{
	  				$currentSquare = 'current';
	  			}
	  			else
	  			{
	  				$currentSquare = '#';
	  			}
	  			
	    		echo '<li> <a href="' . PAGE . $section . SUBSECTION . $subsection . CURRENT_IMAGE . $count . '" class="' . $currentSquare . '"> <img src="' . COLOUR_PATH . '/square.jpg" alt="next picture"/> </a> </li>';
	  			
	  		}
		}
		?>
	</ul>
	<div id="contentBottomRight">
	    <div class="image_text"><?php echo $imageText; ?></div>
        <div class="up_down">
	    	<?php
	    		$href = PAGE . $section . SUBSECTION . $subsection . CURRENT_IMAGE;  
	    		$previous_href = $href . ($currentImage - 1);
	    		$next_href = $href . ($currentImage + 1);  
	    		$next_display = ($currentImage + 1 > $imageCount || !$showBoxes) ? 'hidden' : 'visible';
	    		$previous_display = ($currentImage - 1 <= 0 || !$showBoxes) ? 'hidden' : 'visible';
	    	?>
	    	<div class="up_arrow">
	    		<a href="<?php echo $previous_href; ?>" style="visibility: <?php echo $previous_display; ?>"></a>
	    	</div>
	    	<div class="down_arrow">
	    		<a href="<?php echo $next_href; ?>" style="visibility: <?php echo $next_display; ?>"></a>
	    	</div>
	    </div>
	</div>
</div>

