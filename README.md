# 🏛️ Philosopher

## 📋 Description

Philosopher est un projet pédagogique de l'école 42 qui explore la gestion de la concurrence et la synchronisation des threads. L’objectif est de simuler le problème classique des philosophes en respectant les contraintes de synchronisation et d’optimisation.

## 🔍 Objectif

Le but est de modéliser le comportement de plusieurs philosophes assis autour d’une table, qui passent leur temps à penser, manger et dormir. Chaque philosophe doit suivre des règles précises, en évitant les problèmes classiques de synchronisation comme les deadlocks et les race conditions.

Le projet est divisé en deux parties :

Partie obligatoire : Implémentation avec threads et mutex.

Bonus : Utilisation de semaphores et processus pour la gestion avancée de la synchronisation.

## ⚙️ Fonctionnement

Chaque philosophe suit un cycle de vie :

Penser

Prendre une fourchette

Prendre l’autre fourchette

Manger (pendant un temps défini)

Reposer les fourchettes

Dormir (pendant un temps défini)

Le programme doit s'arrêter si :

Un philosophe meurt de faim.

Toutes les actions requises ont été complétées.


## 🛠️ Installation

### Prérequis :
- C compiler (cc)

### Cloner le projet :
- Clonez le dépôt GitHub pour obtenir les fichiers :

```bash
git clone https://github.com/agraille/Philosophers.git
```

### Compilation :
```bash
cd philo
make
```
Pour le checker bonus, compilez avec la commande suivante :
```bash
cd philo_bonus
make
```
### Exécution :

Exécutez le programme avec une liste d'entiers en argument :
```bash
./philo [nombre_de_philosophes] [temps_mort] [temps_manger] [temps_dormir] [nombre_repas (optionnel)]
```
### Exemple :
```bash
./philo 5 800 200 200
```
### Exemple de Sortie :

-1) philo mort :

-![Texte alternatif](https://github.com/agraille/Philosophers/philo_img1.png)

-2) philo routine ok :
 
 -![Texte alternatif](https://github.com/agraille/Philosophers/philo_img2.png)

## 📏 Contraintes

- Aucun philosophe ne doit mourir de faim (sauf si précisé dans l’argumentaire d’entrée).

- L’accès aux ressources critiques doit être correctement géré.

- Obligatoire : utilisation de threads et mutex.

- Bonus : implémentation avec semaphores et forks.

- Minimiser l’utilisation du processeur (éviter les boucles infinies inutiles).

## 🌟 Fonctionnalités

- ✅ Gestion dynamique des philosophes et des ressources.
- ✅ Synchronisation optimisée avec mutex (obligatoire) et sémaphores (bonus).
- ✅ Protection contre les race conditions et les deadlocks.
- ✅ Gestion robuste des erreurs et des entrées invalides.

## 💻 Contribuer
Les contributions sont les bienvenues ! Si vous souhaitez améliorer cette algo, ajouter de nouvelles fonctionnalités ou corriger des bugs, n’hésitez pas à faire un fork du projet et proposer une pull request.

Comment contribuer :
- 1 - Forkez le projet.
- 2 - Créez une branche pour vos modifications : git checkout -b feature/amélioration
- 3 - Committez vos changements : git commit -am 'Ajout d’une nouvelle fonctionnalité'
- 4 - Poussez la branche : git push origin feature/amélioration
- 5 - Ouvrez une Pull Request pour proposer vos changements.
