struct EILC {
  int valeur;
  struct EILC *suivant;
};
typedef struct EILC elementIntLC;

struct EILDC {
  int valeur;
  struct EILDC *precedent;
  struct EILDC *suivant;
};
typedef struct EILDC elementIntLDC;
