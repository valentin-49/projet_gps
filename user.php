<?php
class user{
    //propriétes:
    private $_user = "valentin";
    private $_passwd = "root";
    

    //méthodes:
   
/*public function Connexion($NDC, $MDP){//Fonction qui permet au utilisateur de se connecter

    try
        {
            $maBase=new PDO('mysql:host="localhost"; dbname="projet_tp_1";
            charset=utf8','root', '');
            $LesNVusers=$maBase->query('SELECT `ID`,`Mot_de_passe` FROM `Users` WHERE "'.$NDC.'"=`ID` && "'.$MDP.'"=`Mot_de_passe');
            $admin = $LesNVusers->fetch();
            $this->_user = $admin['ID'];
            $this->_passwd = $admin['Mot_de_passe'];
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
}
