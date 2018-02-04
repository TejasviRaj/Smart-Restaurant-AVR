<?php


echo '<form action="test.php" method="post">
 <p>Enter a number <input type="text" name="num" /></p>
 <p>

 Choose action-<br/>
 <input type="radio" name="act" value="mult" /> Multiplication Table <br/>
 <input type="radio" name="act" value="fact" /> Factors <br/>


 </p>
 <p><input type="submit" /></p>
</form> ';


 if (isset($_POST['num']))
{
  if (isset($_POST['act']))
  {
    $b=$_POST['act'];
    $a=$_POST['num'];

    if ($b=="mult")
    {

      for ($i=1;$i<=10;$i++)
      {
         $c=$a*$i;
         echo "$a * $i = $c<br/>";
         //echo "$b";
      }
    }
    elseif ($b=="fact")
    {
        for ($i=1;$i<=$a;$i++)
        {
          if ($a % $i==0)
          {
            $d=$a/$i;
            echo "$a/$i=$d<br/>";

          }
        }

    }
  }



  else
  { echo "Choose an action";
  }



}

// connecting to sql server


//a table
echo '
<table align="center" border =2 width=200>
   <tr>
      <td>a</td>
      <td>b</td>
      <td>c</td>
   </tr>
</table>
';
?>
