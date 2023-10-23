/* premier argument est la longueur de la ligne , second argument est le nombre de ligne */


/* on decoupe en 4 cas peut etre à regrouper ensuite */


/* cas 1,1 */
if (argv[1] = 1 and argv[2] = 1) /* si l'arg 1 est = 1 et aussi l'arg 2 est = 1 on affiche juste A */
{
	print ("A"); /* donc on affiche un A */
	exit (0);
}


/* cas N,1 */
if (argv[1] >= 2 and argv[2] = 1) /* si l'arg 2 est = 1 on doit faire un affichage en ligne */
{

	        print ("A"); /* on affiche le A de gauche */
		        caractereBenligne=argv(2) - 2; /* on initialise la variable de fin de boucle pour afficher tous les B en colonne a hauteur de argv(2) - 2 cad on enleve 2 pour enlever les 2 lignes A et C */
			i=1
			while i < caractereBenligne /* on fait une boucle pour afficher tous les B a hauteur de argv(1) - 2 cad on enleve 2 pour enlever les 2 lignes A et C */
	                {
                        	print ("B") ;
			        i=i+1 ;
	        print ("A"); /* on reaffiche A pour la fin de la colonne */
	        print ("\n"); /* on fait un retour à la ligne */

	exit (0);
}


/* cas 1,N */
if (argv[1] = 1 and argv[2] >= 2) /* si l'arg 1 est = 1 on doit faire un affichage en colonne */
{

	        print ("A"); /* on affiche le A de gauche */
		print ("\n"); /* on fait un retour à la ligne */
		        caractereBencolonne=argv(2) - 2; /* on initialise la variable de fin de boucle pour afficher tous les B en colonne a hauteur de argv(2) - 2 cad on enleve 2 pour enlever les 2 lignes A et C */
			i=1
			while i < caractereBencolonne /* on fait une boucle pour afficher tous les B a hauteur de argv(1) - 2 cad on enleve 2 pour enlever les 2 lignes A et C */
	                {
                        	print ("B") ;
			        print ("\n"); /* on fait un retour à la ligne */
			        i=i+1 ;
	        print ("A"); /* on reaffiche A pour la fin de la colonne */
	        print ("\n"); /* on fait un retour à la ligne */

	exit (0);
}



/* cas N,N */
if (argv(1) >= 2 and  argv(2) >=2 ) /* la on est dans le cas general de si premier argument supérieur ou egal à (>=) 2  et second arg superieur ou egal a 2 */
{ 

/* ligne du haut debut */ /* avec des "B" */
	print ("A"); /* on affiche le A de gauche */
	caractereBsurlaligne=argv(1) - 2; /* on initialise la varialbe de fin de boucle pour afficher tous les B a hauteur de argv(2) - 2 cad on enleve 2 pour enlever les 2 bord A et A */
	i=1
		while i < caractereBsurlaligne /* on fait une boucle pour afficher tous les B a hauteur de argv(2) - 2 cad on enleve 2 pour enlever les 2 bord A et A */
		{ 
			print ("B") ;
			i=i+1 ;
		}
	print ("A"); /* on reaffiche A de droite pour la fin de la ligne */
	print ("\n"); /* on fait un retour à la ligne */
/* ligne du haut fin */ 

/* ligne milieu debut */ /* presque meme code des " " au milieu mais avec un while supplémentaire qui inclue le while de la ligne */
	nombredeligneblanche=argv(2)-2;

	l=1
	while ( l <= nombredeligneblanche )
	{
	print ("A");
	caracterespacesurlaligne=argv(1) - 2;
	i=1
		while i < caractereBsurlaligne
		{ 
			print (" ") ;
			i=i+1 ;
		}
	print ("A");
	print ("\n");
	l=l+1;
	}
/* ligne milieu fin */

/* ligne bas debut */ /* meme code que pour le haut avec des "B" au milieu mais des C avant et apres */
	print ("C");
	caractereBsurlaligne=argv(1) - 2;
	i=1
		while i < caractereBsurlaligne
		{ 
			print ("B") ;
			i=i+1 ;
		}
	print ("C");
	print ("\n");
/* ligne bas fin */

}
