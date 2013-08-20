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
		$imageLink = '';
		
		if($currentImageNumber == 1)
		{
			$imageLink = 'haitiproject';
		}
		elseif($currentImageNumber == 2 || $currentImageNumber == 3 || $currentImageNumber == 4)
		{
			$imageLink = $currentImageNumber.'.pdf';
			$imageLinkHref = '<a href="' . $currentDir . '/' . $imageLink . '">';
		}
		else
		{
			$imageLinkHref = '';
			$hideImageLink = true;
		}
		
		//if the main image doesn't exist get the text instead
		if(!file_exists($currentDir . '/' . $currentImage))
		{
			$introTextFile = $currentImageNumber . '.txt';
			if(file_exists($currentDir . '/' . $introTextFile))
			{
				$introText = nl2br(file_get_contents($currentDir . '/' . $introTextFile));
			}
		}
		$showBoxes = true;
	}
	else
	{
		$currentImage = 'home.jpg';
		$showBoxes = false;
	}
	
	echo $imageLinkHref;

	if(isset($introText))
	{
?>
		<div class="introText"><?php echo $introText; ?></div>
<?php
	}
	else
	{
?>
	<img src="<?php echo $currentDir. '/' . $currentImage; ?>" alt="<?php echo ''; ?>" width="500" height="500" />
	<?php echo ($hideImageLink ? '':'</a>'); ?>
<?php
	}
?>
	</div><!-- end contentCentre div -->
	<div id="contentRight">
      <ul id="nav_box">
      	<?php 
			if($showBoxes)
			{
				if($currentImageNumber == 1)
				{
	        		echo '<li> <a href="' . $currentDir. '/' . $imageLink . '"> <img src="' . COLOUR_PATH . '/square.jpg" alt="next picture"/> </a> </li>';
				}
				else
				{
	        		echo '<li> <a href="' . PAGE . $section . SUBSECTION . $subsection . CURRENT_IMAGE . '1" class="' . $currentSquare . '"> <img src="' . COLOUR_PATH . '/square.jpg" alt="next picture"/> </a> </li>';
				}
				
	      		for($count = 2 ; $count <= $imageCount ; $count++)
	      		{
	      			if($count == $currentImage)
	      			{
	      				$currentSquare = 'current';
	      			}
	      			else
	      			{
	      				$currentSquare = '';
	      			}
	      			
	        		echo '<li> <a href="' . PAGE . $section . SUBSECTION . $subsection . CURRENT_IMAGE . $count . '" class="' . $currentSquare . '"> <img src="' . COLOUR_PATH . '/square.jpg" alt="next picture"/> </a> </li>';
	      			
	      		}
			}
      	?>
      </ul>
<!--   <div id="contentBottomRight"> Text will go here</div> -->
  </div>
  