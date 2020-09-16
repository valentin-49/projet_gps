<?php
class admin{
    //propriétes:
    private $_admin ="admin";
    private $_passwd="admin";
    

    //méthodes:
   
/*public function Connexion($NDC, $MDP){//Fonction qui permet au admin de se connecter

    try
        {
            $maBase=new PDO('mysql:host="localhost"; dbname="user_projet_radar"; charset=utf8','root','root');
            $LesNVusers=$maBase->query('SELECT `admin`,`Mdp` FROM `Admin` WHERE "'.$NDC.'"=`admin` && "'.$MDP.'"=`Mdp');
            $admin = $LesNVusers->fetch();
            $this->_admin = $admin['user'];
            $this->_passwd = $admin['Mdp'];
        }    

            catch (Exception $erreur){
                echo 'Erreur : '.$erreur ->getMessage();
        }
}
*/
public function Compar_passwd($NDC, $MDP){ //compare les id et mdp 
    if($NDC == $this->_admin){
        if($MDP == $this->_passwd){
            return true;
        }
    }
    return false;
}
}