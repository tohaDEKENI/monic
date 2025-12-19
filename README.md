# Moni-C – Mini System Monitor

MoniC est un **mini-moniteur système** écrit en **C/C++**, qui permet de récupérer et d’afficher en temps réel les informations essentielles de votre système, telles que :

- Utilisation du **CPU**
- Utilisation de la **RAM**
- **Load Average** (1 min, 5 min, 15 min)
- **Uptime** du système
- Mémoire RAM et Swap (totale et utilisée)

Le projet propose deux modes d’affichage :

1. **Mode console** – affichage direct dans le terminal.
2. **Mode serveur web** – affichage via une page web dynamique en utilisant **httplib.h**, **HTML** et **JavaScript**.

---




---

## ⚙️ Installation et compilation

1. Cloner le projet :
```bash
git clone https://github.com/ton-utilisateur/MoniC.git
cd MoniC

##Compiler le projet :
g++ src/*.cpp src/*.c -o moniC -I include

### Exemple d'afficage mode console
===== MINI SYSTEM MONITOR =====
User         : dekeni-toha
Hostname     : dekeni
CPU usage    :[####                                    ] 10.38%
RAM usage    :[###################                     ] 47.79%
RAM          : 1.81 GiB / 3.78 GiB
Swap         : 0.00 GiB / 3.64 GiB
Load Average : 0.68 0.44 0.45
Uptime       : 4h 32min 11sec


