<?php
$server="127.0.0.1";
$user="Tejas";
$pwd="teamsedra";

$conn = new mysqli($server, $user, $pwd,"Smart");
$sql = "SELECT id,Food,Price,Num_selected,Prepared FROM Food";
$result = $conn->query($sql);

  echo $result->num_rows."<br>";
    while($row = $result->fetch_assoc()) {

      echo
       $row["id"]." ".
      $row["Food"]." ".
      $row["Price"]." ".
      $row["Num_selected"]." ".
      $row["Prepared"]."<br>"
      ;
    }
$conn->close();
?>
