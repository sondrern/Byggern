<?php
ob_start();
session_start();

if($_SESSION['pos']==0){
	$_SESSION['pos']=1;
}

$value=0;
$myfile = fopen("../test.txt", "r");

while(!feof($myfile)) {
  $value = fgets($myfile);
}

fclose($myfile);

 
 $myfile = fopen("../test.txt", "w+");
 fclose($myfile);


if($value==1){
  if($_SESSION['pos']>1){
    $_SESSION['pos']=$_SESSION['pos']-1; 
  }
}

else if($value==2){
  if($_SESSION['pos']<4){
    $_SESSION['pos']=$_SESSION['pos']+1;
  }
}

else if($value==3){
  echo "Enter from ble";
}

else if($value==4){
  echo "Back from ble";
}
$menupos=$_SESSION['pos'];
?>


<?php if($menupos==1){ ?>
<div class="banner" style="background-color:#CEED9D">
Option 1
</div>
<?php } else{ ?>
<div class="banner">
Option 1
</div>
<?php } if($menupos==2){ ?>
<div class="banner" style="background-color:#CEED9D">
Option 2
</div>
<?php } else{ ?>
<div class="banner">
Option 2
</div>
<?php } if($menupos==3){ ?>
<div class="banner" style="background-color:#CEED9D">
Option 3
</div>
<?php } else{ ?>
<div class="banner">
Option 3
</div>
<?php } if($menupos==4){ ?>
<div class="banner" style="background-color:#CEED9D">
Option 4
</div>
<?php } else{ ?>
<div class="banner">
Option 4
</div>
<?php } ?>
