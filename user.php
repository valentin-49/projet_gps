<?php
class user{
    //propriétes:
    private $_user ="root";  //log et mot de passe de co pour la page d'acceuil
    private $_passwd="root";

    private $_admin =false; //false=Non-admin , true=admin
    // private $_logadmin;


    //méthodes:
   
/*public function Connexion($NDC, $MDP){//Fonction qui permet au utilisateur de se connecter

    try
        {
            $maBase=new PDO('mysql:host="localhost"; dbname="user_projet_radar"; charset=utf8','root','root');
            $LesNVusers=$maBase->query('SELECT `User`,`Mdp`,`admin` FROM `user` WHERE "'.$NDC.'"=`user` && "'.$MDP.'"=`Mdp');
            $admin = $LesNVusers->fetch();
            $this->_user = $admin['user'];
            $this->_passwd = $admin['Mdp'];
            $this->_admin = $admin[`admin`];
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
/*public function compar_admin(){
    if(($this->_admin)==1){
        $_logadmin = true;
    }
   
}*/
public function isAdmin(){ //verifie si c un admin
    
    return $this->_admin;
}
}
