<div align="center">
  <img height="450" src="https://raw.githubusercontent.com/Kurama77190/PUSH_SWAP/main/img/LOGO%20PUSH_SWAP.jpg"  />
</div>

![Language](https://img.shields.io/badge/language-C-blue)
![Progress](https://img.shields.io/badge/progress-completed-green)

## PUSH_SWAP | BEN TAYEB SAMY

## Table des matières
- [Introduction](#introduction)
- [Comment ça marche](#comment-ça-marche)
- [Utilisation](#utilisation)
- [Fonctionnalités](#fonctionnalités)
- [Améliorations du parsing](#améliorations-du-parsing)
- [Remerciements](#remerciements)

## Introduction
Le projet `Push_Swap` est une implémentation efficace de l'algorithme de tri "TurkSort", spécialement conçue pour le challenge de tri du même nom. L'objectif est de trier des données sur une pile, en utilisant le moins de mouvements possibles, et ce, en se limitant à un ensemble d'opérations prédéfinies.

<div align="center">
  <img height="150" src="https://raw.githubusercontent.com/Kurama77190/PUSH_SWAP/main/img/Capture.PNG"  />
</div>

## Comment ça marche
L'algorithme "TurkSort" utilise une stratégie de tri par segments, permettant de diviser la pile en plusieurs sous-ensembles qui sont ensuite triés individuellement avant d'être fusionnés. Cette méthode minimise le nombre total d'opérations nécessaires pour obtenir une pile triée.

## Utilisation
Pour utiliser le programme `push_swap`, suivez ces instructions :

``./push_swap [votre_séquence_de_nombres]``

Remplacez `[votre_séquence_de_nombres]` par la séquence de nombres que vous souhaitez trier. Le programme affichera une série d'opérations qui trient cette séquence en utilisant le moins de mouvements possibles.

## Fonctionnalités
- **Tri efficace** : Utilise l'algorithme "TurkSort" pour optimiser le nombre de mouvements nécessaires au tri.
- **Validation des entrées** : Vérifie et valide les entrées pour assurer la stabilité du tri.

## Améliorations du parsing
Une attention particulière a été portée à l'amélioration du parsing des entrées. Le programme est conçu pour gérer efficacement divers cas d'entrées, y compris les valeurs numériques, les séquences de nombres, et les erreurs de format, pour garantir que le tri puisse être réalisé sans interruption.

## Remerciements
- Inspiration : [L'article sur TurkSort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
