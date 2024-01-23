<div align="center">
  <img height="550" src="https://raw.githubusercontent.com/Kurama77190/PRINTF/main/image/PRINTF%20LOGO.png"  />
</div>

###

# Projet Printf - École 42 | SAMY BEN TAYEB

![Language](https://img.shields.io/badge/language-C-blue)
![Progress](https://img.shields.io/badge/progress-completed-green)

## Table des Matières
- [Description](#description)
- [Objectifs](#objectifs)
- [Fonctionnalités](#fonctionnalités)
- [Utilisation](#comment-lutiliser)

## Description
Le projet `printf` de l'école 42 est une réplique de la fonction `printf` de la bibliothèque C standard. Il vise à approfondir les connaissances des étudiants en C, notamment sur les arguments variadiques, le formatage des chaînes et la gestion de la mémoire.

## Objectifs
- Comprendre le fonctionnement interne de `printf`.
- Apprendre à gérer les arguments variadiques.
- Maîtriser le formatage des chaînes de caractères.
- Renforcer les compétences en programmation en C.

## Fonctionnalités
- Gestion de divers spécificateurs de format : `%s`, `%d`, `%x`, etc.
- Prise en charge des flags de formatage.
- Compatible avec les flux de sortie standards.

## Comment l'utiliser
```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!", "monde");
    return 0;
}
