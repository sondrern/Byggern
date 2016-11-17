<?php
ob_start();
session_start();



if($_SESSION['pos']==0){
	$_SESSION['pos']=1;
}

if($_SESSION['playerpos']==0){
  $_SESSION['playerpos']=1;
}

if($_SESSION['score']==0){
  $_SESSION['score']=0;
}


if($_SESSION['player']!='Sondre' && $_SESSION['player']!='Jared' && $_SESSION['player']!='Player 1' && $_SESSION['player']!='Player 2'){
  $_SESSION['player']='Default';
}

$value=0;

$myfile = fopen("../test.txt", "r") or die("Unable to open file!");
while(!feof($myfile)) {
  $value = fgets($myfile);
}
fclose($myfile);
$myfile = fopen("../test.txt", "w+") or die("Unable to write to file!");
fclose($myfile);




/*
$myfile = fopen("topscore.txt", "w+") or die("Unable to write to file!");
fwrite($myfile,2);
fwrite($myfile,"\n");
fwrite($myfile,3);
fwrite($myfile,"\n");
fwrite($myfile,4);
fwrite($myfile,"\n");
fwrite($myfile,5);
fclose($myfile);
*/





if($value==5){
  $_SESSION['score']=$_SESSION['score']+1;
  $_SESSION['goalflag']=1;
  $topscore=array();

$myfile = fopen("topscore.txt", "r") or die("Unable to open topscore.txt!");
$i=0;
while(!feof($myfile)) {
  $topscore[$i] = fgets($myfile);
  $i++;
  
}
fclose($myfile);
  if($_SESSION['player']=='Sondre' && $_SESSION['score']>$topscore[0]){
    $myfile = fopen("topscore.txt", "w+") or die("Unable to write to file!");
    fwrite($myfile, $_SESSION['score']);
    fwrite($myfile,"\n");
    fwrite($myfile, $topscore[1]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[2]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[3]);
   
    fclose($myfile);
    /*
    $myfile = fopen("topscore.txt", "r") or die("Unable to open topscore.txt!");
    $i=0;
    while(!feof($myfile)) {
      $topscore[$i] = fgets($myfile);
      $i++;
    }
    fclose($myfile);
  */
  }
  else if($_SESSION['player']=='Jared' && $_SESSION['score']>$topscore[1]){
    $myfile = fopen("topscore.txt", "w+") or die("Unable to write to file!");
    fwrite($myfile, $topscore[0]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $_SESSION['score']);
    fwrite($myfile,"\n");
    fwrite($myfile, $topscore[2]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[3]);
   
    fclose($myfile);
    
  }
  else if($_SESSION['player']=='Player 1' && $_SESSION['score']>$topscore[2]){
    $myfile = fopen("topscore.txt", "w+") or die("Unable to write to file!");
    fwrite($myfile, $topscore[0]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[1]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $_SESSION['score']);
    fwrite($myfile,"\n");
    fwrite($myfile, $topscore[3]);
   
    fclose($myfile);
    
  }
  else if($_SESSION['player']=='Player 2' && $_SESSION['score']>$topscore[3]){
    $myfile = fopen("topscore.txt", "w+") or die("Unable to write to file!");
    fwrite($myfile, $topscore[0]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[1]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $topscore[2]);
    //fwrite($myfile,"\n");
    fwrite($myfile, $_SESSION['score']);
   
    fclose($myfile);
    
  }
}

if($value==6){
  $_SESSION['goalflag']=0;
}

if($_SESSION['goalflag']==1){ ?>
  <div class="banner" style="background-color:#CEED9D">
    Goal! Press button a to continue <br>
  </div>
<?php }

$menupos=$_SESSION['pos'];

if($_SESSION['menu']==0){
  if($value==1){
  if($_SESSION['pos']>1){
    $_SESSION['pos']=$_SESSION['pos']-1; 
  }
}

else if($value==2){
  if($_SESSION['pos']<3){
    $_SESSION['pos']=$_SESSION['pos']+1;
  }
}



else if($value==3){
  //echo "Enter from ble";
  if($_SESSION['pos']==1){
    $_SESSION['score']=0;
  }
  else if($_SESSION['pos']==2){
    $_SESSION['menu']=1;
  }
  else if($_SESSION['pos']==3){
    $_SESSION['menu']=2;
  }
  
}

?>
  
  <?php if($_SESSION['player']=='Default'){ ?>
  <div class="banner">
    Choose player! 
  <br><br>
  </div> <?php } 
  
  else{ ?>
  <div class="banner"> <?php
    echo $_SESSION['player'] ?> Score = <?php echo $_SESSION['score']; ?>
  <br><br>
  </div> 
  <?php } ?>
  
  
  <?php if($menupos==1){ ?>
  <div class="banner" style="background-color:#CEED9D">
  New game
  </div>
  <?php } else{ ?>
  <div class="banner">
  New game
  </div>
  <?php } if($menupos==2){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Choose player
  </div>
  <?php } else{ ?>
  <div class="banner">
  Choose player
  </div>
  <?php } if($menupos==3){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Top score list
  </div>
  <?php } else{ ?>
  <div class="banner">
  Top score list
  </div>
  <?php }

} else if($_SESSION['menu']==1){ 

  if($value==4){
    $_SESSION['menu']=0;
  } 
 
  else if($value==1){
    if($_SESSION['playerpos']>1){
      $_SESSION['playerpos']=$_SESSION['playerpos']-1; 
    }
  }

  else if($value==2){
    if($_SESSION['playerpos']<4){
      $_SESSION['playerpos']=$_SESSION['playerpos']+1;
    }
  }

  else if($value==3){
  // Enter //
    $_SESSION['score']=0;
    if($_SESSION['playerpos']==1){
      $_SESSION['player']='Sondre';
    }
    else if($_SESSION['playerpos']==2){
      $_SESSION['player']='Jared';
    }
    else if($_SESSION['playerpos']==3){
      $_SESSION['player']='Player 1';
    }
    else if($_SESSION['playerpos']==4){
      $_SESSION['player']='Player 2';
    }
    $_SESSION['menu']=0;
  }

  ?>
  <div class="banner">
    Choose player menu <br><br>
  </div>
   <?php if($_SESSION['playerpos']==1){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Sondre
  </div>
  <?php } else{ ?>
  <div class="banner">
  Sondre
  </div>
  <?php } if($_SESSION['playerpos']==2){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Jared
  </div>
  <?php } else{ ?>
  <div class="banner">
  Jared
  </div>
  <?php } if($_SESSION['playerpos']==3){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Player 1
  </div>
  <?php } else{ ?>
  <div class="banner">
  Player 1
  </div>
  <?php }
  if($_SESSION['playerpos']==4){ ?>
  <div class="banner" style="background-color:#CEED9D">
  Player 2
  </div>
  <?php } else{ ?>
  <div class="banner">
  Player 2
  </div>
  <?php } ?>
<?php } 

else if($_SESSION['menu']==2){ ?>
  <?php
  $topscore=array();

$myfile = fopen("topscore.txt", "r") or die("Unable to open topscore.txt!");
$i=0;
while(!feof($myfile)) {
  $topscore[$i] = fgets($myfile);
  $i++;
  
}
fclose($myfile);
  if($value==4){
    $_SESSION['menu']=0;
  } ?>
  <div class="banner">
    Top score menu
    <br><br>
  </div>
  <div class="banner">
    Sondre &nbsp&nbsp= &nbsp<?php echo $topscore[0] ?><br>
    Jared &nbsp&nbsp&nbsp&nbsp = &nbsp<?php echo $topscore[1] ?><br>
    Player 1 = &nbsp<?php echo $topscore[2] ?><br>
    Player 2 = &nbsp<?php echo $topscore[3] ?><br>
  </div>
<?php } ?> 