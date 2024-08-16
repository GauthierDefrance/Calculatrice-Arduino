______________________________________________________________
[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
#################### Calculatrice Arduino ####################
[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]


Grâce à l'UE LIBRE Fab lab proposé par CY sup et le Labboite

Ce projet comme son nom l'indique est une calculatrice
utilisant une carte Arduino pour le traitement des données
un pavé numérique pour l'entrée des données et un écran
lcd pour l'affichage des données.
Le projet bénéficie de plusieurs fonction.
Avec les touches 0,1,2,3,4,5,6,7,8,9 vous pouvez saisir des
nombres. A,B,C,D permettent d'effectuer des opérations.
Respectivement (A) Addition, (B) Soustraction, (C) Multiplication 
et (D) Division. (#) correspond à = et enfin (*) correspond
à CE pour réinitialiser.


Ce projet Arduino a été conçu en utilisant différents 
composants, qui vous seront nécessaire si vous souhaitez
réaliser ce projet.

Il vous faudra :
______________________________________________________________
| - Une carte Arduino UNO
| - Des câbles en tout genre
| - Un écran lcd avec connexion i2c
| - un buzzer
| - Un pavé numérique 4x4
| - Un ordinateur avec l'arduino IDE
|_____________________________________________________________

Vous pouvez trouver les composants sur Aliexpress pour pas trop cher.

Vous pouvez rajouter une structure à votre appareil, je vous recommande
l'utilisation de bois contre plaqué que vous pourrez éventuellement
découper à la découpeuse laser. Une fois que vous avez pensé une forme
pour votre structure sur une app comme Free Cad.


Plus de détail ici :
https://www.labboite.fr/#!/projects/calculatrice-arduino

Le projet a était fait par un débutant, le code et les branchements
peuvent ne pas être les plus optimal.


Bibliothèque utilisé :

LiquidCrystal_I2C
https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/

string
https://github.com/arduino/ArduinoCore-API/blob/master/api/String.h

Keypad
https://www.arduino.cc/reference/en/libraries/keypad/