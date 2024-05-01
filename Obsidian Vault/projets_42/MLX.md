# **Manuel Complet MiniLibX**

Ce document résume les fonctions principales de la bibliothèque MiniLibX, utilisée pour le développement de projets graphiques en C sous environnements Unix/Linux. Il détaille l'utilisation et les particularités de chaque fonction ainsi que leurs prototypes.

## **Introduction**

MiniLibX est une bibliothèque graphique simplifiée utilisée principalement dans l'éducation pour enseigner les bases de la programmation graphique en C. Elle permet la création et la manipulation de fenêtres et d'images, ainsi que la gestion des événements liés à la souris et au clavier.

## **Fonctions de Base**

### **`mlx_init`**

#### *Description*
Initialise la connexion avec le système graphique. Cette fonction doit être appelée avant toute autre fonction de la MiniLibX et retourne un pointeur vers l'environnement MiniLibX, nécessaire pour les autres fonctions.

#### *Prototype*
```c
void *mlx_init();
```
### **`mlx_new_window`**

#### *Description*
Crée une nouvelle fenêtre sur l'écran avec les dimensions spécifiées et un titre. Elle retourne un pointeur vers la nouvelle fenêtre créée.

#### *Prototype*
```c
void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);
```

### **`mlx_pixel_put`**

#### *Description*
Permet de colorer un pixel spécifique dans une fenêtre donnée. Cette fonction est essentielle pour le dessin direct et les modifications d'images à la volée.

#### *Prototype*
```c
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
```

### **`mlx_new_image`**

#### *Description*
Crée une nouvelle image en mémoire de la taille spécifiée. Cette image peut être manipulée directement par d'autres fonctions MiniLibX pour dessiner avant d'être affichée.

#### *Prototype*
```c
void *mlx_new_image(void *mlx_ptr, int width, int height);
```

### **`mlx_loop`**

#### *Description*
Lance la boucle principale de gestion des événements pour une application MiniLibX. Cette boucle attend les événements (comme les pressions de touches ou les clics de souris) et les traite à mesure qu'ils surviennent.

#### *Prototype*
```c
int mlx_loop(void *mlx_ptr);
```

## **Gestion des Images**

### **`mlx_xpm_file_to_image`**

#### *Description*
Convertit un fichier XPM en une image utilisable dans MiniLibX. Cette fonction est pratique pour charger des images qui seront utilisées comme textures ou sprites.

#### *Prototype*
```c
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
```

### **`mlx_put_image_to_window`**

#### *Description*
Affiche une image à la position spécifiée dans la fenêtre donnée. Cette fonction est utilisée après avoir modifié l'image (par exemple, après avoir dessiné dessus).

#### *Prototype*
```c
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
```

## **Gestion des Événements**

### **`mlx_key_hook`**

#### *Description*
Permet de définir une fonction à appeler lorsqu'une touche est pressée. Cette fonction de rappel peut être utilisée pour ajouter des interactions clavier à l'application.

#### *Prototype*
```c
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```
### **`mlx_mouse_hook`**

#### *Description*
Définit une fonction à appeler lorsqu'un événement de souris est détecté, permettant d'intégrer des interactions basées sur la souris dans l'application.

#### *Prototype*
```c
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```

### **`mlx_expose_hook`**

#### *Description*
Définit une fonction à appeler lorsque la fenêtre doit être redessinée, par exemple après avoir été cachée puis montrée à nouveau.

#### *Prototype*
```c
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
```

## **Conclusion**

Le manuel MiniLibX offre une introduction concise et des explications sur les fonctions essentielles pour créer des applications graphiques simples. Les prototypes et exemples donnés ici sont essentiels pour comprendre comment créer et manipuler des fenêtres et des images, gérer des événements, et dessiner des pixels directement à l'écran.
