# So_long

Bienvenue sur le projet **So_long** ! Ce projet est un petit jeu 2D développé en C, utilisant la bibliothèque graphique **MiniLibX**. Le but du jeu est de collecter tous les objets présents sur la carte et de s'échapper par la sortie en effectuant le moins de mouvements possible.

## 📋 Prérequis

Ce projet a été développé pour fonctionner sous un environnement Unix/Linux. Il nécessite les dépendances suivantes :
- `gcc` ou `clang`
- `make`
- Les librairies X11 (incluses via la MiniLibX)

## 🛠️ Installation

Pour compiler le jeu, clonez ce dépôt et exécutez la commande `make` à la racine du projet. Cela compilera les bibliothèques nécessaires (`libft`, `ft_printf`, `minilibx`) et créera l'exécutable `so_long`.

```bash
make
```
puis lancer le jeu avec le level1 ou 2 .ber
```bash
./so_long src/level1.ber
```
