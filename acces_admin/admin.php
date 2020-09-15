<?php require("admin_co.php");?>
<?php
session_start();
//$_SESSION["isconnectUS"];
?>
<?php
  if(isset($_POST['deco'])){
    session_unset();
    session_destroy();
}  
if(isset($_SESSION["isconnectUS"]) && $_SESSION["isconnectUS"]==true){
?>
<html>
    <head>
    <title>admin</title>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="admin.css">
        <link rel="shortcut icon" href="../image/unnamed.png" />
        <link rel="stylesheet" type="text/css" href="../bootstrap-4.4.1-dist/css/bootstrap.css">
    </head>
        <body>
            <div class="container">
                <div class="row">
                    <div class="col-12 en-tete" align="center">
                        <h1>Page Admin</h1>
                    </div>
                    <form method="POST" class="col-2"><p><input type="submit" name="deco" value="Deconnexion" class="bouton-deco"/></p></form>
                    <div class="col-1"></div>
                    <div class="col-6 formulaire_de_connexion" align="center">
                        <form action="admin.php" method="$_POST">
                            <label><h3>Se Connecter en tant qu'admin</h3></label>
                                <p><input type="text" name="ID_1" width="auto" class="text" required/></p>
                                <label><h3>Mot De Passe</h3></label>
                                <p><input type="password" name="MDP_1" class="text" required/></p>
                                <p><input type="submit" name="Valider" value="Valider" class="bouton"/></p>
                            <?php
                            if(empty($_POST['ID_1']) && empty($_POST['MDP_1'])){

                            }else{
                            
                            $user = new admin();
                            $_SESSION["isconnectad"] = $user->Compar_passwd($_POST['ID_1'],$_POST['MDP_1']);
                            if($_SESSION["isconnectad"]){
        
                                echo"<p><h3>Connexion à la BDD effectuer</h3></p>";
                                $_SESSION["isconnectad"]=true;
        
                            }else{ //meesage d'erreur si les Id et Mdp sont incorrects   
        
                                echo"<p><h3>Identifiants ou mot de passe incorrects, veuillez reessayer.</h3></p>";
                            }
                            }
                            ?>
                        </form>
                    </div>
                    <div class="col-3"></div>
                </div>
            </div>
        </body>
</html>
<?php
}elseif(!isset($_SESSION["isconnectUS"]) || $_SESSION["isconnectUS"]==false ){   
?>
<html>
    <head>
        <script type="text/javascript" src="admin.js"></script>
        <link rel="stylesheet" type="text/css" href="../bootstrap-4.4.1-dist/css/bootstrap.css">
    </head>
    <body onload="redirect()">
        <div class="congtainer">
            <div class="row">
                <div class="col-12" align="center">
                    <h1>Vous etes deconnetez, vous allez etre rediriger vers l'acceuil dans 3 secondes</h1>
                </div>
            </div>
        </div>
    </body>
</html>
<?php
}
?>