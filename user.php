<?php
class user{
    //propriétes:
    private $_user;
    private $_passwd;
    

    //méthodes:
   
public function Connexion($NDC, $MDP){//Fonction qui permet au utilisateur de se connecter

    try
        {
            $maBase=new PDO('mysql:host="localhost"; dbname="user_projet_radar";
            charset=utf8','root', '');
            $LesNVusers=$maBase->query('SELECT `user`,`Mdp` FROM `Users` WHERE "'.$NDC.'"=`user` && "'.$MDP.'"=`Mdp');
            $admin = $LesNVusers->fetch();
            $this->_user = $admin['user'];
            $this->_passwd = $admin['Mdp'];
        }    

            catch (Exception $erreur){
                echo 'Erreur : '.$erreur ->getMessage();
        }
}

public function Compar_passwd($NDC, $MDP){ //compare les id et mdp 
    if($NDC == $this->_user){
        if($MDP == $this->_passwd){
            return true;
        }
    }
    return false;
}
}
