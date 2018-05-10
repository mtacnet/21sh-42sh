## 21sh-42sh
Projet 42 - Langage C - 21sh-42sh
------

Objectif des projets *21sh* et *42sh*

- écrire un shell UNIX le plus stable et le plus complet possible.
- Lecture et édition de ligne avancée avec Termcaps.
- Analyse lexicale ("Lexing").
- Analyse syntaxique ("Parsing") / Parsing avancé.
- Analyse sémantique.
- Gestion des processus et de leurs interactions.

## Sujets

Les sujets des projets sont à dispositions, au format PDF, à la racine du repository.

## Téléchargement

Clonage du dossier :

	$> git clone https://github.com/mtacnet/21sh-42sh.git
  
## Compilation

Le projet peut être compilé à l'aide de `make` ou `make all`. La compilation de la bibliothèque _libft_ est automatiquement effectuée (son _Makefile_ est appelé depuis celui de *42sh*). L'exécutable est nommé *42sh*.

La commande `make clean` permet de supprimer tous les fichiers objets et `make fclean` de supprimer, en plus de ceux-ci, l'exécutable.

La commande `make re` est équivalent à `make fclean all`.

## Utilisation

/!\ Rappel: Le projet a été principalement développé dans/pour un environnement macOS Sierra (10.12.16). Le projet est susceptible de ne pas avoir les comportements souhaités sous un autre système d'exploitation. /!\

Une fois le projet *42h* compilé vous pouvez le lancer à l'aide de la commande `./42sh`.

## Fonctionnalités implémentées
