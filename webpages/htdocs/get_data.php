<?php
$server="127.0.0.1";
$user="Tejas";
$pwd="teamsedra";

$conn = new mysqli($server, $user, $pwd,"Smart");
$sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
$result = $conn->query($sql);
if (isset($_GET['id']) && isset($_GET['num']))
{

}
  echo "\r";
  echo "The data are"."\r";
  echo $result->num_rows."\r";
    while($row = $result->fetch_assoc()) {

      echo
       $row["id"]."\r".
      $row["Food"]."\r".
      $row["Price"]."\r".
      $row["Num_selected"]."\r".
      $row["Prepared"]."\r"
      ;
    }
$conn->close();
?>
