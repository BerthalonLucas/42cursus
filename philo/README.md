# Projet Philosophers - To-Do List

## Étapes Préparatoires

- [ ] Lire et comprendre le sujet du projet :
  - [ ] Prendre des notes sur les contraintes : interdiction des variables globales, gestion des erreurs, etc.
  - [ ] Analyser les règles du projet : gestion des états des philosophes, conditions d'arrêt de la simulation, etc.

## Concepts et Compétences à Maîtriser

### Threads en C
- [x] Apprendre à créer des threads avec `pthread_create`.
- [ ] Apprendre à joindre des threads avec `pthread_join`.
- [ ] Comprendre la détachement des threads avec `pthread_detach`.

### Mutexes
- [ ] Initialiser un mutex avec `pthread_mutex_init`.
- [ ] Détruire un mutex avec `pthread_mutex_destroy`.
- [ ] Verrouiller un mutex avec `pthread_mutex_lock`.
- [ ] Déverrouiller un mutex avec `pthread_mutex_unlock`.

### Gestion de la Mémoire
- [ ] Utiliser `malloc` pour allouer de la mémoire dynamiquement.
- [ ] Utiliser `free` pour libérer la mémoire allouée.

### Temps et Synchronisation
- [ ] Mesurer le temps avec `gettimeofday`.
- [ ] Introduire des délais avec `usleep`.

## Plan de Développement

### Initialisation du Projet
- [ ] Créer les fichiers de base :
  - [ ] `Makefile`
  - [ ] `main.c`
  - [ ] `philo.h`
- [ ] Configurer le `Makefile` :
  - [ ] Inclure les règles `NAME`, `all`, `clean`, `fclean`, `re`.
  - [ ] Utiliser les flags `-Wall`, `-Wextra`, `-Werror`.

### Modélisation des Philosophes et des Fourchettes
- [ ] Définir les structures de données dans `philo.h` :
  - [ ] Structure pour les philosophes.
  - [ ] Structure pour les fourchettes (avec mutex).

### Implémentation des États des Philosophes
- [ ] Écrire des fonctions pour les états :
  - [x] `void philosopher_eat(t_philosopher *philo)`
  - [ ] `void philosopher_sleep(t_philosopher *philo)`
  - [ ] `void philosopher_think(t_philosopher *philo)`
- [ ] Gérer les transitions d'état et les affichages :
  - [ ] `timestamp_in_ms X has taken a fork`
  - [ ] `timestamp_in_ms X is eating`
  - [ ] `timestamp_in_ms X is sleeping`
  - [ ] `timestamp_in_ms X is thinking`
  - [ ] `timestamp_in_ms X died`

### Gestion des Concurrences
- [ ] Utiliser des mutexes pour protéger l'accès aux fourchettes.
- [ ] Vérifier l'absence de conditions de concurrence (data races).

### Gestion des Conditions de Fin
- [ ] Implémenter la condition d'arrêt :
  - [ ] Lorsque tous les philosophes ont mangé suffisamment de fois.
  - [ ] Lorsqu'un philosophe meurt de faim.

### Test et Débogage
- [ ] Créer des programmes de test pour vérifier chaque fonctionnalité.
- [ ] Utiliser `valgrind` pour détecter les fuites de mémoire et les erreurs de concurrence.

## Conseils Pratiques

- [ ] Diviser le code en fonctions claires et modulaires (max 25 lignes par fonction).
- [ ] Commenter le code de manière concise et utile, en anglais.
- [ ] Passer régulièrement le code à la Norminette pour vérifier qu'il respecte la norme 42.

## Ressources Supplémentaires

- [ ] [Documentation pthread](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [ ] [Tutoriels sur la gestion des threads en C](https://www.geeksforgeeks.org/multithreading-c-2/)
- [ ] [Utilisation des mutexes](https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/)
