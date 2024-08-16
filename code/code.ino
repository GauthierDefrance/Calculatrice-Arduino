#include "LiquidCrystal_I2C.h"
#include "string.h"
#include <Keypad.h>

//definition note musique
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_DB3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_EB3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_AS5 932
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST     0
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_G6  1568
#define NOTE_C6  1047
#define NOTE_E6  1319
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_FS5 740
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_B4  494
#define NOTE_GS5 831
#define NOTE_E5 659


//création objet LCD
LiquidCrystal_I2C LCD(0x27,16,2);

//def constante utile et autre variables
int line = 0;
int row=0;
String valeur ;
long nombreA=0;
long nombreB=0;
String operateur="0";
int reste=0;
#define BUZZER_PIN 11

//defition musique pacman
int melody[] = {
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
  NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
  NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,
  
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
  NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
};

int durations[] = {
  16, 16, 16, 16,
  32, 16, 8, 16,
  16, 16, 16, 32, 16, 8,
  
  16, 16, 16, 16, 32,
  16, 8, 32, 32, 32,
  32, 32, 32, 32, 32, 16, 8
};



const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );


void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  //demarage écran Lcd
  LCD.init(); // initialisation de l'afficheur
  LCD.backlight();
  LCD.setCursor(2, 0);
  LCD.print("HELLO  WORLD");
  Serial.begin(9600);
  //début musique pacman de démarrage
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
  //Fin initialisation
}


void loop(){
  //début programme principal
  //On rajoute un délai entre chaque itération
  delay(100);
  //on utilise la fonction getkey() pour voir quel touche est préssé sur le keypad 
  char key = keypad.getKey();
  //on réinitialise l'écran LCD et on écrit les valeurs stoqué actuellement dessus
  //Premiere ligne : nombreA et éventuellement l'opération qu'on souhaite faire actuellement
  //Deuxième ligne : nombreB 
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print(nombreA);
  LCD.setCursor(0,1);
  LCD.print(nombreB);
  //Si il n'y a pas d'opérations en cours, pas besoin d'afficher un opérateur
  if (operateur!="0"){
    LCD.setCursor(15,0);
    LCD.print(operateur);
  }
  //détection appuie touche
  if (key){
    //on convertie le char key en string pour pouvoir effectuer des comparaisons
    valeur = String(key);
    //Si on est en train de renseigner nombreA et qu'on appuie sur un nombre
    if ((valeur!="A")&&(valeur!="B")&&(valeur!="C")&&(valeur!="D")&&(operateur=="0")&&(valeur!="*")&&(valeur!="#")){
      //Si le nombre ne cause pas d'overflow
      if ((nombreA*10+ valeur.toInt()<=9999999)&&(nombreA*10+ valeur.toInt()>=-9999999)){
        nombreA= nombreA*10+ valeur.toInt();  
      }
      //Si overflow
      else{
        tone (11, 300);
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Erreur");
        delay(1000);
        nombreA=0;
        nombreB=0;
        operateur="0";
        delay(500);
        noTone (11);
      }
    }
    //Sinon si on renseigne nombreB
    else if ((valeur!="A")&&(valeur!="B")&&(valeur!="C")&&(valeur!="D")&&(valeur!="#")&&(valeur!="*")){
      //Si ne cause pas d'overflow
      if ((nombreB*10+ valeur.toInt()<=9999999)&&(nombreB*10+ valeur.toInt()>=-9999999)){
        nombreB= nombreB*10+ valeur.toInt();  
      }
      //Si overflow
      else{
        tone (11, 300);
        LCD.clear();
        LCD.setCursor(0,0);
        LCD.print("Erreur");
        delay(1000);
        nombreA=0;
        nombreB=0;
        operateur="0";
        delay(500);
        noTone (11);
      }  
    }
    // Dans le cas ou c'est une opération
    else {
      //Si addition
      if(valeur=="A"){
        if (operateur=="0") {
          operateur="A";  
        }
        else{
          egalite();
          operateur="A";
        }
        }
      //Si soustraction
      else if(valeur=="B"){
        if (operateur=="0") {
          operateur="B";  
        }
        else{
          egalite();
          operateur="B";
        }
        }
      //Si multiplication
      else if(valeur=="C"){
        if (operateur=="0") {
          operateur="C";  
        }
        else{
          egalite();
          operateur="C";
        }
        }
      //Si division
      else if(valeur=="D"){
        if ((operateur=="0")) {
          operateur="D";  
        }
        
        
        else{
          egalite();
          operateur="D";
        }
        }
      //Si on souhaite calculer les valeurs
      else if(valeur=="#"){
        egalite();
        }
      //Si on souhaite renitialiser
      else if(valeur=="*"){
        nombreA=0;
        nombreB=0;
        operateur="0";
        tone (11, 600);
        delay(500);
        noTone (11);
        }
    }
    }
  }

//Fonction permettant d'effectuer les calculs après égalité.
int egalite(){
  tone (11, 1200);
  delay(250);
  noTone (11);
  if(operateur=="A"){
          nombreA=nombreA+nombreB;
          nombreB=0;
          operateur="0";
          }
        else if(operateur=="B"){
          nombreA=nombreA-nombreB;
          nombreB=0;
          operateur="0";
          }
        else if(operateur=="C"){
          nombreA=nombreA*nombreB;
          nombreB=0;
          operateur="0";
          }
        else if(operateur=="D"){
          
          //Système anti division par 0
          if (nombreB==0){
            tone (11, 300);
            delay(100);
            tone(11,100);
            LCD.clear();
            LCD.setCursor(0,0);
            LCD.print("Erreur");
            LCD.setCursor(0,1);
            LCD.print("Div par 0");
            delay(1000);
            nombreA=0;
            nombreB=0;
            operateur="0";
            noTone (11);
            }
          if(nombreB!=0){ 
              nombreA=nombreA/nombreB;
              nombreB=0;
              operateur="0";
              }
          //Système anti division par 0
          
          }
  //gestion overflow
  if ((nombreA>=99999999)||(nombreA<=-99999999)){
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("Erreur");
    delay(1000);
    nombreA=0;
    nombreB=0;
    operateur="0";
  }
}


