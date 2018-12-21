/**
 * Arduino tone
 * Creado por: Oscar Fernandez <oscarfdzalz@gmail.com>
 * Publicado por: codigoelectronica.com <codigoelectronica@gmail.com>
 */

//Libreria de tonos
#include "pitches.h"

//Melodia
int melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

//Nota duración: 4 = cuarto de nota, 8 = octavo de nota, etc.:
int noteDurations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

void setup() {
  //Iterar sobre las notas de la melodía:
  int size = sizeof(melody) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {

    //Para calcular la duración de la nota, tome un segundo dividido por el tipo de nota.
    //e.g. cuarto de nota = 1000 / 4, octavo de nota = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(9, melody[thisNote], noteDuration);

    //Para distinguir las notas, establece un tiempo mínimo entre ellas.
    //La duración de la nota + 30% parece funcionar bien:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    //Deja de tocar el tono
    noTone(9);
  }
}

void loop() {
  //No requiere en este proyecto
}
