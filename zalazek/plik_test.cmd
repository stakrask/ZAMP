#define V_WIRNIK 30  /* Prędkość obrotu karuzeli */
#define V_GONDOLA 30 /* Prędkość kontrowania gondoli */

Pause 1000

/* === PEŁNY OBRÓT 360 stopni === */
/* Karuzela obraca się, gondole pozostają w pionie */

Begin_Parallel_Actions
  /* Wirnik obraca się o 90 stopni */
  Rotate Karuzela.Wirnik OZ V_WIRNIK 90
  
  /* Wszystkie 4 gondole kontrują obrót (270 stopni w drugą stronę = -90) */
  Rotate Karuzela.Wirnik.Ramie1.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie2.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie3.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie4.Gondola OZ V_GONDOLA 270
End_Parallel_Actions

Pause 300

/* === Druga ćwiartka === */
Begin_Parallel_Actions
  Rotate Karuzela.Wirnik OZ V_WIRNIK 90
  Rotate Karuzela.Wirnik.Ramie1.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie2.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie3.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie4.Gondola OZ V_GONDOLA 270
End_Parallel_Actions

Pause 300

/* === Trzecia ćwiartka === */
Begin_Parallel_Actions
  Rotate Karuzela.Wirnik OZ V_WIRNIK 90
  Rotate Karuzela.Wirnik.Ramie1.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie2.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie3.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie4.Gondola OZ V_GONDOLA 270
End_Parallel_Actions

Pause 300

/* === Czwarta ćwiartka - pełny obrót zakończony === */
Begin_Parallel_Actions
  Rotate Karuzela.Wirnik OZ V_WIRNIK 90
  Rotate Karuzela.Wirnik.Ramie1.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie2.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie3.Gondola OZ V_GONDOLA 270
  Rotate Karuzela.Wirnik.Ramie4.Gondola OZ V_GONDOLA 270
End_Parallel_Actions

Pause 1000