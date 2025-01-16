#include <Arduino.h>
// void maTache(void *parametres)
// {
//   while (1) // boucle infinie
//   {
//     Serial.printf("maTache %d\n", xPortGetCoreID());
//     delay(500);
//     Serial.printf("Priorité ma tache =%d\n", uxTaskPriorityGet(NULL));
//   }
// }

void maTache(void *parametres)
{
  int v1 = 0;
  static int v2 = 0;
  while (1) // boucle infinie
  {
    Serial.printf("maTache v1=%d v2=%d\n", v1, v2);
    v1++;
    v2++;
    delay(500);
  }
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.printf("Départ\n");

  xTaskCreatePinnedToCore(
      maTache,    /* Fonction de la tâche. */
      "Ma tâche", /* Nom de la tâche. */
      10000,      /* Taille de la pile de la tâche */
      NULL,       /* Paramètres de la tâche, NULL si pas de paramètre */
      1,          /* Priorité de la tâche */
      NULL,       /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
      1           /*choix du coeur soit 0 ou 1 */
     );

  xTaskCreate(
      maTache,      /* Fonction de la tâche. */
      "Ma tâche 2", /* Nom de la tâche. */
      10000,        /* Taille de la pile de la tâche */
      NULL,         /* Paramètres de la tâche, NULL si pas de paramètre */
      2,            /* Priorité de la tâche */
      NULL);        /* Pointeur pour récupérer le « handle » de la tâche, optionnel */
}
void loop()
{
  Serial.printf("Loop() %d\n", xPortGetCoreID());
  delay(1000);
  Serial.printf("Priorité loop =%d\n", uxTaskPriorityGet(NULL));
}
