<?php
session_start();
//$_SESSION["isconnectUS"];

?> 
<?php require("user.php");?>
<?php
    if(empty($_POST['ID_1']) && empty($_POST['MDP_1'])){ //suite du formulaire de connexion de la condition 2

    }else{
                    
        $user = new user();
        $_SESSION["isconnectUS"] = $user->Compar_passwd($_POST['ID_1'],$_POST['MDP_1']);
        $_SESSION["isconnectAD"] = $user->isAdmin();
       
        if($_SESSION["isconnectUS"]){

        $_SESSION["isconnectUS"]=true; //passe la variable isconnectUS a true ce qui permet de rentrer dans la condition 1 et de faire disparaitre le formulaire 

    }elseif($_SESSION["isconnectAD"]){ //message d'erreur si les Id et Mdp sont incorrects
                            
        $_SESSION["isconnectAD"]=true;

    }else{
        echo"<p><h3>Identifiants ou mot de passe incorrects, veuillez reessayer.</h3></p></div>"; 
        }
    }
?>
<?php
 if(isset($_POST['deco2'])){ //bouton de deconnexion qui retourne à la dondition 2
    session_unset();
    session_destroy();

 } if(isset($_POST['deco'])){ //bouton de deconnexion qui retourne à la dondition 2
    session_unset();
    session_destroy();

}  if(isset($_POST['deco3'])){ //bouton de deconnexion qui retourne à la dondition 2
    session_unset();
    session_destroy();

} 
if(isset($_SESSION["isconnectUS"]) && $_SESSION["isconnectUS"]==true && $_SESSION["isconnectAD"]==false ){ //condition 1) si l'utilisateur est deja connecter, affiche les redirections vers d'autres pages.
?>
 <html>
    <head><!-- fichier css et js de mise en page-->
        <title>GeoGuessBoat</title>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="bootstrap-4.4.1-dist/css/bootstrap.css">
        <link rel="stylesheet" type="text/css" href="index.css">
        <link rel="shortcut icon" href="image/unnamed.png" />
        <script type="text/javascript" src="index.js"></script>
    </head>
                    
    <body onload="heure()">
            <div class="row">
                <div class="col-2"></div>
                <div class="col-8 en-tete" align="center">
                    <h1>Vous etes connectez</h1>
                </div>
                <div class="col-2"></div>
                <div class="col-4" align="center"></div>
                <div class="col-4 en-tete " align="center">
                    <h2 id="time" style="text-decoration: underline;"></h2>
                </div>
                <div class="col-4" align="center"></div>
            </div>
        <div class="row">
            <div class="col-12"></div>
            <div class="col-2 " align="center"></div>
            <div class="col-8" align="center">
        <?php
                    
            if($_SESSION["isconnectUS"]){
        ?>
            <div class="col-12 redirection" align="center">
                
                <form action="index.php" method="POST">
                    <div class="row">
                        <div class="col-6" align="center"><p><input type="button" name="Valider" value="Accés à mon compte" onclick="self.location.href='acces_mon_compte/compte.php'" class="bouton_redirect"/></p></div>                                      
                        <div class="col-6" align="center"><p><input type="button" name="Valider" value="Accés aux donnée" onclick=" self.location.href='acces_donnee/data.php'" class="bouton_redirect"/></p></div>
                    </div>
                    <div class="row">
                        <div class="col-12" align="center"> <p><input type="button" name="Valider" value="Position des bateaux" onclick="self.location.href='position_bateaux/traceur.php'" class="bouton_redirect"/></p></div>
                    </div>
                        <div class="col-12" align="center"><form method="POST"><p><input type="submit" name="deco2" value="deconnexion" class="bouton_redirect"/></p></form>
                    </div>
                </form>
            </div>
        <?php      
        }
        ?>
        </div>
            <div class="col-2 " align="center">
                                                
                    </div>
                </div>
            </div>
    </body>
</html>
<?php 

}elseif(!isset($_SESSION["isconnectUS"]) || $_SESSION["isconnectUS"]==false || !isset($_SESSION["isconnectAD"]) || $_SESSION["isconnectAD"]==false){ // condition 2) si l'utilisateur n'est pas deja connecter, affiche un formulaire de connexion

?>
<html>
    <head><!-- fichier css et js de mise en page-->
        <title>GeoGuessBoat</title>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="bootstrap-4.4.1-dist/css/bootstrap.css"> 
        <link rel="stylesheet" type="text/css" href="index.css">
        <link rel="shortcut icon" href="image/unnamed.png" />
        <script type="text/javascript" src="index.js"></script>
    </head>

    <body onload="heure()">
            <div class="container">
                <div class="row">
                    <div class="col-12 en-tete" align="center">
                        <h1>GeoGuessBoat</h1>
                    </div>
                    <div class="col-4" align="center">
                        
                    </div>
                    <div class="col-4 en-tete " align="center">
                        <h2 id="time" style="text-decoration: underline;"></h2>
                    </div>
                    <div class="col-4" align="center">
                        
                    </div>
                    <div class="col-2 coterG" align="center">
                        
                    </div>
                    <div class="col-1" align="center">
                        
                    </div>
                    <div class="col-6 formulaire_de_connexion" align="center"><!-- formulaire de connexion -->
                        <form action="index.php" method="POST">
                            <label><h3>Se Connecter</h3></label>
                            <p><input type="text" value="root" name="ID_1" width="auto" class="text" required/></p>
                            <label><h3>Mot De Passe</h3></label>
                            <p><input type="password" value="root" name="MDP_1" class="text" required/></p>
                            <p><input type="submit" name="Valider" value="Valider" class="bouton"/></p>
                        </form>
                    </div>
                    <div class="col-1" align="center">
                        
                    </div>
                    <div class="col-2 coterDr" align="center">
                        
                    </div>         
                </div> 
            </div>
            
    </body>
</html>
<?php
    }elseif(isset($_SESSION["isconnectAD"]) || $_SESSION["isconnectAD"]==true ){
?>
<html>
    <head><!-- fichier css et js de mise en page-->
        <title>GeoGuessBoat</title>
        <meta charset="utf-8">
        <link rel="stylesheet" type="text/css" href="bootstrap-4.4.1-dist/css/bootstrap.css">
        <link rel="stylesheet" type="text/css" href="index.css">
        <link rel="shortcut icon" href="image/unnamed.png" />
        <script type="text/javascript" src="index.js"></script>
    </head>
                    
    <body onload="heure()">
            <div class="row">
                <div class="col-2"></div>
                <div class="col-8 en-tete" align="center">
                    <h1>Vous etes connectez</h1>
                </div>
                <div class="col-2"></div>
                <div class="col-4" align="center"></div>
                <div class="col-4 en-tete " align="center">
                    <h2 id="time" style="text-decoration: underline;"></h2>
                </div>
                <div class="col-4" align="center"></div>
            </div>
        <div class="row">
            <div class="col-12"></div>
            <div class="col-2 " align="center"></div>
            <div class="col-8" align="center">
        <?php
                    
            if($_SESSION["isconnectAD"]){
        ?>
            <div class="col-12 redirection" align="center">
                
                <form action="index.php" method="POST">
                    <div class="row">
                        <div class="col-12" align="center"><p><input type="button" name="Valider" value="Accées administrateur" onclick="self.location.href='acces_admin/admin.php'" class="bouton_redirect"/></p></div>
                    </div>
                        <div class="col-12" align="center"><form method="POST"><p><input type="submit" name="deco2" value="deconnexion" class="bouton_redirect"/></p></form>
                    
                    </div>
                </form>
            </div>
        <?php      
        }
        ?>
        </div>
            <div class="col-2 " align="center">
                                                
                    </div>
                </div>
            </div>
    </body>
</html>

<?php
}
?>

<!-- $user = new user();
                        $_SESSION["isconnectUS"] = $user->Compar_passwd($_POST['ID_1'],$_POST['MDP_1']);
                        if($_SESSION["isconnectUS"]){

$user = new user();
                    $user->connexion($_POST['ID_1'] , $_POST['MDP_1']);
                    $isconnectUS = $user->Compar_passwd($_POST['ID_1'],$_POST['MDP_1']);
                    if($isconnectUS){
                        