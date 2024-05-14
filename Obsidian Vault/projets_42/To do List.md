---
titre: To-Do List pour le Projet So Long
créé: <% tp.file.creation_date() %>
---

# To-Do List - Projet So Long

## Configuration Initiale

- [x] **Installer les Prérequis** :
  - [x] Installer GCC pour la compilation du C.
  - [x] Installer MiniLibX si ce n'est pas déjà fait.
  - [x] S'assurer que toutes les bibliothèques nécessaires sont installées (X11, etc.).

- [x] **Cloner le dépôt Git** :
  - [x] Initialiser un nouveau dépôt Git pour le projet.
  - [x] Cloner le dépôt sur l'environnement de développement local.

- [x] **Créer l'Arborescence de Dossiers** :
  - [x] `src/` pour les fichiers sources du jeu.
  - [x] `include/` pour les fichiers d'en-têtes.
  - [x] `assets/` pour les sprites et textures.
  - [x] `maps/` pour les cartes de jeu (.ber).

## Rédaction des Documents

- [x] **Créer la Description du Jeu** :
  - [x] Rédiger et sauvegarder `Description du Jeu.md` dans le dossier `Documentation`.

- [ ] **Établir les Spécifications Techniques** :
  - [ ] Définir et documenter l'architecture technique et les spécifications détaillées.

- [ ] **Définir les Fonctionnalités du Jeu** :
  - [ ] Lister toutes les fonctionnalités attendues et les règles du jeu dans `Fonctionnalités.md`.

## Développement

- [ ] **Setup Initial de MiniLibX** :
  - [ ] Configurer un exemple basique pour ouvrir une fenêtre et gérer un événement.

- [ ] **Créer le Makefile** :
  - [ ] Définir les règles `all`, `clean`, `fclean`, `re`.
  - [ ] Assurer la compilation des fichiers sources avec les flags appropriés (-Wall, -Wextra, -Werror).

- [ ] **Développer les Fonctionnalités Basiques** :
  - [ ] Gestion de la fenêtre et des événements clavier.
  - [ ] Affichage et mouvement des sprites sur la carte.

- [ ] **Implémenter la Logique du Jeu** :
  - [ ] Gestion des collisions.
  - [ ] Collecte des items.
  - [ ] Conditions de victoire et de défaite.

## Tests

- [ ] **Créer des Tests Unitaires** :
  - [ ] Tester individuellement les fonctions critiques.
  - [ ] Utiliser un framework de test si nécessaire (e.g., CUnit).

- [ ] **Tests d'Intégration** :
  - [ ] Assurer que tous les composants du jeu fonctionnent bien ensemble.

## Versioning

- [ ] **Commits Réguliers** :
  - [ ] Faire des commits après chaque avancement significatif.
  - [ ] Push les changements sur le dépôt Git régulièrement.

## Préparation pour la Rendition

- [ ] **Peaufiner le Jeu** :
  - [ ] Réviser le code pour optimiser et corriger les bugs.
  - [ ] Finaliser la documentation.

- [ ] **Préparer le Rendu** :
  - [ ] S'assurer que tous les fichiers nécessaires sont présents et corrects.
  - [ ] Vérifier que le Makefile produit le bon exécutable sans erreurs ni warnings.

## Révision et Backup

- [ ] **Backup Régulier** :
  - [ ] Mettre en place une stratégie de backup régulier pour ne pas perdre de travail.

- [ ] **Révision par les Pairs** :
  - [ ] Organiser des sessions de révision du code avec des collègues pour améliorer la qualité.

