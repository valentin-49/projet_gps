<?php
session_start();
//$_SESSION["isconnectUS"];

?>
<?php
 if(isset($_POST['deco'])){ 
    session_unset();
    session_destroy();
} 
if(isset($_SESSION["isconnectUS"]) && $_SESSION["isconnectUS"]==true){ //condition 1) si l'utilisateur est deja connecter et n'est pas un admin, affiche les redirections vers d'autres pages.
?>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="../bootstrap-4.4.1-dist/css/bootstrap.css">
        <link rel="stylesheet" type="text/css" href="compte.css">
    </head>
        <body>
            <div class="container">
                <div class="row">
                    <div class="col-1"></div>
                    <div class="col-8 en-tete" align="center">
                        <h1>Votre compte</h1>
                    </div>
                    <div class="col-3"><form method="POST"><p><input type="submit" name="deco" value="deconnexion" class="bouton"/></p></form></div>
                </div>
            </div>
            
        </body>
</html>

<?php
}elseif(!isset($_SESSION["isconnectUS"]) && $_SESSION["isconnectUS"]==false){
?>
<html>
    <head>
        <script type="text/javascript" src="compte.js"></script>
        <link rel="stylesheet" type="text/css" href="../bootstrap-4.4.1-dist/css/bootstrap.css">
    </head>
    <body onload="redirect()">
        <div class="container">
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