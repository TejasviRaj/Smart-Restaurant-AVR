<!DOCTYPE html>
<html>
<head>
<title>Smart Restaurant</title>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
<link href="layout/styles/layout.css" rel="stylesheet" type="text/css" media="all">
</head>
<body id="top">

<div class="wrapper bgded overlay" style="background-image:url('images/demo/backgrounds/01.png');">
  <div id="pageintro" class="hoc clear">
    <!-- ################################################################################################ -->
    <article>
      <p class="heading">The future of all restaurants</p>
      <h2 class="heading"><span class="block">Smart</span> Restaurant</h2>
      <footer>
        <ul class="nospace inline pushright">
          <li><a class="btn inverse" href="#table">View Table</a></li>
          <li><a class="btn" href="#change">Edit food item</a></li>
        </ul>
      </footer>
    </article>
    <!-- ################################################################################################ -->
  </div>
</div>


<!--- Selected Foods --->
<div class="wrapper row3" id="table">
  <main class="hoc container clear">
    <p class="heading"><h1> <b>Selected Foods </b></h1></p>

    <!-- main body -->
    <!-- ################################################################################################ -->
    <div class="center btmspace-80">
    <h1>  Table No. 1 </h1>
      <table>
        <?php
        $server="127.0.0.1";
        $user="Tejas";
        $pwd="teamsedra";

        $conn = new mysqli($server, $user, $pwd,"Smart");

        //select data
        $sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
        $result = $conn->query($sql);
        if ($result==TRUE)
        {
        //  echo "Data succesfully selected<br>";

        }
        else {
      //    echo "Error selecting data ".$conn->error;
        }
              if (isset($_POST['prep']))
              {
                $a=$_POST['prep'];
                if ($a=="Done")
                  {
                    while($row = $result->fetch_assoc()) {
                      $a=$row["id"];
                      $sql = "UPDATE Food SET Prepared=0 WHERE id=$a";
                        $conn->query($sql);
                      $sql = "UPDATE Food SET Num_selected=0 WHERE id=$a";
                          $conn->query($sql);

                    }
                  }
                else {
                  //echo "$a changed";
                  $a=intval($a);

                $sql = "UPDATE Food SET Prepared=1 WHERE id=$a";
                $conn->query($sql);
              }
                //    echo "Record updated successfully<br>";

            }

            $sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
            $result = $conn->query($sql);
            if ($result==TRUE)
            {
            //  echo "Data succesfully selected<br>";

            }
            else {
          //    echo "Error selecting data ".$conn->error;
            }

              echo "
              <tr>
              <th>id</th>
              <th>Food</th>
              <th>Price</th>
              <th>No Selected</th>
              <th>Prepared</th>
              </tr>";

          //  output data of each row
            while($row = $result->fetch_assoc()) {

              echo "
              <tr>
              <th>". $row["id"]."</th>
              <th>". $row["Food"]."</th>
              <th>". $row["Price"]."</th>
              <th>". $row["Num_selected"]."</th>
              <th>". $row["Prepared"].'</th>
              <td>
              <form name="f2" action="main.php#table" method="post" >
                    <input type="hidden" name="prep" value='.$row["id"].'/>
                    <input type="submit" value="Mark Prepared">
                  </form>
              </td>
                  </tr>

                  '

              ;

            }
            $sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
            $result = $conn->query($sql);
            $sum=0;
            while($row = $result->fetch_assoc()) {
              $sum=$sum+$row["Price"]*$row["Num_selected"];
            }
            echo " <tr>
                  <th colspan=4> Total </th>
                  <th>$sum</th>
                </tr>
                ";

            echo '

            </table>
    <!-- ################################################################################################ -->
    <!-- / main body -->


    <form name="f3" action="main.php#table" method="post" >
      <p align="center" width="400">
      <input type="hidden" name="prep" value="Done"/>
      <input type="submit" value="Price Paid">
 </p>

    </form>
    '
    ;
    $conn->close();
     ?>

    <h1>  Table No. 2 </h1>
      <table>
  <tr>
    <th>Sn.</th>
    <th>Food</th>
    <th>Price</th>
    <th>No. Selected</th>
    <th>Prepared</th>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
</tr>

  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk2" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk3" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
      <th colspan=4> Total </th>
      <th>600</th>
    </tr>
</table>
    <!-- ################################################################################################ -->
    <!-- / main body -->


    <form name="f2" action="#" >
      <p align="center" width="400">
   <input id="edit" type="submit" name="Done" value="Price Paid" width="200" align="center"/>
 </p>

    </form>

    <h1>  Table No. 3 </h1>
      <table>
  <tr>
    <th>Sn.</th>
    <th>Food</th>
    <th>Price</th>
    <th>No. Selected</th>
    <th>Prepared</th>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
</tr>

  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk2" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk3" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
      <th colspan=4> Total </th>
      <th>600</th>
    </tr>
</table>
    <!-- ################################################################################################ -->
    <!-- / main body -->


    <form name="f2" action="#" >
      <p align="center" width="400">
   <input id="edit" type="submit" name="Done" value="Price Paid" width="200" align="center"/>
 </p>

    </form>

    <h1>  Table No. 4 </h1>
      <table>
  <tr>
    <th>Sn.</th>
    <th>Food</th>
    <th>Price</th>
    <th>No. Selected</th>
    <th>Prepared</th>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
</tr>

  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk2" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk3" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
    <th>1</th>
    <th>Momo</th>
    <th>100</th>
    <th>2</th>
    <th>1</th>
    <td>
                  <form name="f2" action="#" >
                   <input id="edit" type="submit" name="pk1" value="Mark Prepared" />
                  </form>
              </td>
  </tr>
  <tr>
      <th colspan=4> Total </th>
      <th>600</th>
    </tr>
</table>
    <!-- ################################################################################################ -->
    <!-- / main body -->

    <form name="f2" action="#" >
      <p align="center" width="400">
   <input id="edit" type="submit" name="Done" value="Price Paid" width="200" align="center"/>
 </p>

    </form>

    <p id="change"> <h1> <b> All Food List <b> </h1> </p>
      <table>

        <?php
        $server="127.0.0.1";
        $user="Tejas";
        $pwd="teamsedra";

        $conn = new mysqli($server, $user, $pwd,"Smart");

        //select data
        $sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
        $result = $conn->query($sql);
        if ($result==TRUE)
        {
        //  echo "Data succesfully selected<br>";

        }
        else {
      //    echo "Error selecting data ".$conn->error;
        }



          //  output data of each row
            while($row = $result->fetch_assoc()) {

    echo "
    <tr>
    <th>". $row["id"]."</th>
    <th>". $row["Food"]."</th>
    <th>". $row["Price"]."</th>
    </tr>";

    }
    $conn->close();
     ?>
    </table>
    <!-- ################################################################################################ -->
    <!-- / main body -->

<!-- ################################################################################################ -->
<!-- ################################################################################################ -->
<!-- ################################################################################################ -->

<!-- ################################################################################################ -->
<!-- ################################################################################################ -->
<!-- ################################################################################################ -->
<div class="wrapper row5">
  <div id="copyright" class="hoc clear">
    <!-- ################################################################################################ -->
    <p class="fl_left">Copyright &copy; 2018 - All Rights Reserved - <a href="#">Team Harkabahadur</a></p>
    <p class="fl_right">Designed by <a target="_blank" href="http://www.os-templates.com/" title="Free Website Templates">TRP</a></p>


    <!-- ################################################################################################ -->
  </div>
</div>
<!-- ################################################################################################ -->
<!-- ################################################################################################ -->
<!-- ################################################################################################ -->
<a id="backtotop" href="#top"><i class="fa fa-chevron-up"></i></a>
<!-- JAVASCRIPTS -->
<script src="layout/scripts/jquery.min.js"></script>
<script src="layout/scripts/jquery.backtotop.js"></script>
<script src="layout/scripts/jquery.mobilemenu.js"></script>
</body>
</html>
