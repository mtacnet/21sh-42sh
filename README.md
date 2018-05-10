## 21sh-42sh
Projet 42 - Langage C - 21sh-42sh
------

Objectif des projets *21sh* et *42sh*

- Écrire un shell UNIX le plus stable et le plus complet possible.
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

/!\ PRÉCISION: Lien documentation officielle POSIX: http://pubs.opengroup.org/onlinepubs/9699919799/) /!\

- Édition de la ligne de commande à l’aide de la bibliothèque termcaps.
- Les fonctionnalités des combinaisons de touches `ctrl + D` et `ctrl + C` dans l’édition de la ligne et l’éxecution d’un processus.
- Séparateur de commandes `;`
- Les pipes `|`
- Les opérateurs logiques `&&` et `||`.
- Exécution de commandes simples avec leurs paramètres et gestion du PATH.
- Gestion des erreurs et de la valeur de retour des commandes avec la commande `echo $?`.
- Les redirections avancées: l’aggrégation des sorties de fichier et le heredoc `<<`
	- Les quatre redirections `<`, `>`, `<<` (heredoc) et `>>`.
	- Les aggrégations de descripteurs de fichiers, par exemple pour fermer la sortie d’erreur (>& et <&).
- Utiliser les flèches du haut et du bas pour naviguer dans l’historique des commandes, édition de la ligne possible.
- Couper, copier et/ou coller tout ou partie d’une ligne avec les séquences de touches suivantes:
	- `shift + LEFT/RIGHT` Sélectionner du texte.
	- `alt + C` Copier le texte sélectionné.
	- `alt + V` Coller le texte sélectionné.
	- `alt + X` Couper le texte sélectionné.
- Se déplacer par "mot" vers la gauche et vers la droite avec `ctrl + LEFT` et `ctrl + RIGHT`.
- Aller directement au début et à la fin d’une ligne avec les touches `home` et `end`.
- Ecrire et éditer une commande sur plusieurs lignes. Dans ce cas, `ctrl + UP` et `ctrl + DOWN` permettent de passer d’une ligne à l’autre de la commande en restant sur la même colonne ou la colonne.

- Gestion complète des quotes et doubles quotes, même sur plusieurs lignes (hors expansions).
- Complétion simple avec la touche `tab`
- Gestion des variables locales grace aux builtins `set` et `unset`
- Implémentation des builtins suivantes en respectant les normes dictées par POSIX: 
	◦ `cd`
	◦ `echo`
	◦ `exit`
	◦ `env` 
	◦ `setenv` (équivalent de export sous bash)
	◦ `set`
	◦ `unsetenv`
	◦ `unset`
- Historique des commandes et les builtins `history` et `!` avec toutes leurs options.

## Auteur

- Alexis Guérin - https://github.com/Aguerin42
- Thomas Grange - https://github.com/tgrange42
- Hippolyte Einfalt - https://github.com/PixTillzcorp
- Mickaël Tacnet - https://github.com/mtacnet/

-----
mtacnet@student.42.fr
