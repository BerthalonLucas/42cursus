---
titre: So Long, Et Merci Pour le Poisson
créé: <% tp.file.creation_date() %>
---

# Description du Jeu - So Long

## Introduction

"So Long, Et Merci Pour le Poisson" est un jeu 2D développé pour initier les étudiants à la gestion de fenêtres, aux événements clavier et à la manipulation simple de graphiques via la bibliothèque MiniLibX. Inspiré par le concept de Douglas Adams, le jeu met en scène un dauphin qui doit échapper à la destruction de la Terre en collectant tous les poissons qu'il peut avant de trouver la sortie.

## Objectifs

Le jeu a pour but de :
- Initier les étudiants à la programmation graphique basique.
- Développer des compétences en programmation C utilisant la bibliothèque MiniLibX.
- Comprendre et appliquer les concepts de gestion de fenêtres et d'événements.
- Encourager la créativité dans le développement de jeux vidéo simples.

## Règles du Jeu

### Gameplay

- **Objectif :** Le joueur doit naviguer sur un plateau de jeu pour collecter des items (poissons) et atteindre la sortie le plus rapidement possible.
- **Contrôles :** Utiliser les touches W (haut), A (gauche), S (bas), et D (droite) pour déplacer le personnage à travers le plateau.
- **Défis :** Le plateau contient des obstacles (murs) et des ennemis qui doivent être évités.

### Conditions de Victoire

- Le joueur gagne la partie en collectant tous les items et en atteignant la sortie sans être touché par les ennemis.

### Interface Utilisateur

- **Affichage des Mouvements :** Chaque déplacement du joueur est compté et affiché dans la console.
- **Fenêtre de Jeu :** Le jeu se joue dans une fenêtre graphique où les éléments interactifs sont clairement visibles.

## Conception Graphique

- **Sprites :** Utilisation de sprites pour le personnage, les items, et les ennemis.
- **Textures :** Les textures pour le fond, les murs, et les autres éléments statiques du jeu.
- **Animations :** Simples animations pour les mouvements du personnage et des ennemis.

## Architecture Technique

- **Fichiers :** Le jeu utilise un fichier de configuration (.ber) pour définir le plateau de jeu.
- **Librairies Externes :** 
  - MiniLibX pour la gestion des fenêtres et des événements.
  - Bibliothèque mathématique (option `-lm` lors de la compilation) pour certaines calculs.

## Développement

- **Environnement de Développement :** Le jeu est développé en C sous un environnement Unix/Linux.
- **Compilation :** Utilisation d'un Makefile pour la compilation du jeu. Les commandes principales sont `make all`, `make clean`, `make fclean`, et `make re`.

## Conclusion

"So Long" est plus qu'un simple projet éducatif; il est une introduction à la programmation de jeux vidéo et offre une plateforme pour explorer les graphiques, l'audio, et la logique de jeu dans un environnement de développement C/Linux.

