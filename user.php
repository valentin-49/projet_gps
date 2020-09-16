<?php
class user{
    //propriétes:
    private $_user ="root";  //log et mot de passe de co pour la page d'acceuil
    private $_passwd="root";

    private $_admin =true; //false = Non-admin , tru=admin
    

    //méthodes:
   
/*public function Connexion($NDC, $MDP){//Fonction qui permet au utilisateur de se connecter

    try
        {
            $maBase=new PDO('mysql:host="localhost"; dbname="user_projet_radar"; charset=utf8','root','root');
            $LesNVusers=$maBase->query('SELECT `User`,`Mdp` FROM `user` WHERE "'.$NDC.'"=`user` && "'.$MDP.'"=`Mdp');
            $admin = $LesNVusers->fetch();
            $this->_user = $admin['user'];
            $this->_passwd = $admin['Mdp'];
        }    

            catch (Exception $erreur){
                echo 'Erreur : '.$erreur ->getMessage();
        }
}
*/
public function Compar_passwd($NDC, $MDP){ //compare les id et mdp 
    if($NDC == $this->_user){
        if($MDP == $this->_passwd){
            return true;
        }
    }
    return false;
}

public function isAdmin(){ //verifie si c un admin
    
    return $this->_admin;
}
}
