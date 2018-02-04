<?php
$server="127.0.0.1";
$user="Tejas";
$pwd="teamsedra";

$conn = new mysqli($server, $user, $pwd,"Smart");

//select data
$sql = "SELECT id,Num_selected FROM Food";
$result = $conn->query($sql);

      if (isset($_GET['id']) && isset($_GET['num']))
      {
        $id=$_GET['id'];
        $id=intval($id);
        $num=$_GET['num'];
        $num=intval($num);
              $sql = "UPDATE Food SET Num_selected=$num WHERE id=$id";
                $conn->query($sql);
      }
      echo 'Data updated <br/>';
      echo 'Data audo raixa bhanne kuro bujhiyo nepal ma';
$conn->close();
?>
