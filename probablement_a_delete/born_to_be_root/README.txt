CHOSE SUR LESQUELLES JE DOIT FAIRE DES RECHERCHES
{
	interface graphique X.org c'est quoi ?
	je vais choisir le system d'exploitation debian
	c'est quoi Rocky (surement un system d'exploitation mais a verif et voir plus precisement)
	KDump c'est quoi ?
	SElinux ?
	Apparmor ?
	les partition chiffree ont l'air d'etre fait avec LVM ?
	difference entre aptitude et apt ? c'est quoi ?
	1 service SSH a avoir actif mais uniquement sur le port 4242 + pas le droit de pouvoir s'y connecter avec ROOT
	configuration a faire avec le pare-feu UFW ? ou pare-feu, ou firewalld pour rocky ? et ne laisser que le port 4242 ouvert
	pare-feu doit etre actif au lancement de la machine
	host-name = "login+42" en gros ---> lberthal42
	intalle et config de sudo de facon precise ;
	{
		3 trys max pour se mettre en sudo en cas de mdp errone
		je peux mettre le message que je veux en cas d'erreur de mdp
		chaques action sudo sera archive aussi bien les input* que le output* dans le dossier /var/log/sudo ?
		le mode TTY sera utilise par secu ?
		les paths utilisable par sudo seront restreints encore pour de la secu exemple ;
		/usr/local/sbin  ||  /usr/local/bin   ||   /usr/sbin  ||  /usr/bin ||  /sbin  ||  /bin  ||  /snap/bin
	}
	cree un user dont le nom sera mon login donc user == lberthal
	ce user sera dans les groupes [user42] & sudo
	politique de mot de passe :
	{
		politique de mot de passe == FORT
		mdp expire dans 30jours
		2 jours minimum avant de porvoir modifier un mdp
		avertissement 7 jours avant expiration du mdp
		mdp == 10 caractere minimum
		mdp == 1 MAJ minimum
		mdp == 1 minus minimum
		mdp == 1 chiffre minimum
		mdp == pas plus de 3 caractere identique consecutif
		mdp == interdit aux nom d'utilisateur
		mdp == doit avoir au moin 7 caractere qui ne sont pas dans l'ancien mdp sauf pour root
		le mdp root doit respecter ces regles
	}
	parti script ;
	{
		il doit etre en bash
		le scrpit ecrira des infos toutes les 10min sur tous les terminaux (chercher du cote de wall ?)
		{
			L’architecture de votre système d’exploitation ainsi que sa version de kernel.
			• Le nombre de processeurs physiques.
			• Le nombre de processeurs virtuels.
			• La mémoire vive disponible actuelle sur votre serveur ainsi que son taux d’utilisa-
			tion sous forme de pourcentage.
			• La mémoire disponible actuelle sur votre serveur ainsi que son taux d’utilisation
			sous forme de pourcentage.
			• Le taux d’utilisation actuel de vos processeurs sous forme de pourcentage.
			• La date et l’heure du dernier redémarrage.
			• Si LVM est actif ou pas.
			• Le nombre de connexions actives.
			• Le nombre d’utilisateurs utilisant le serveur.
			• L’adresse IPv4 de votre serveur, ainsi que son adresse MAC (Media Access Control).
			• Le nombre de commande executées avec le programme sudo.
		}
		pendant l'eval il faudra pouvoir l'arreter sans touche au code (chercher du cote de cron ?)
		exemple de se quid doit etre afficher ;
		{
			#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
			#CPU physical : 1
			#vCPU : 1
			#Memory Usage: 74/987MB (7.50%)
			#Disk Usage: 1009/2Gb (49%)
			#CPU load: 6.7%
			#Last boot: 2021-04-25 14:45
			#LVM use: yes
			#Connexions TCP : 1 ESTABLISHED
			#User log: 1
			#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
			#Sudo : 42 cmd
		}
	}
}
update du 23/02/24
nouveau groups fait
regles ssh fait
script lancer au demmarage fait
script ok usr/local/bin
reste a faire les regles de mdp
reste a voir
