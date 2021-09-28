#include<stdio.h>
#include<math.h>

int main(int argc, char**argv) {
  float a,b,c,delta,v1,v2;
  do {
    printf("Coefficient a ? ");
    scanf("%f",&a);
    if (a == 0) printf("Valeur nulle interdite");
  } while (a == 0);
  printf("Coefficient b ? ");
  scanf("%f",&b);
  printf("Coefficient c ? ");
  scanf("%f",&c);
  delta = b * b -4 * a * c;
  v1 = (-1 * b) / (2 * a);
  if (delta > 0) {
    v2 = sqrt(delta) / ( 2 * a);
    printf("2 solutions reelles: %f et %f\n",(v1 + v2),(v1 - v2));
  } else if (delta == 0)
    printf("1 solution reelle: %f\n",v1);
  else {
    v2 = sqrt(fabs(delta)) / (2 * a);
    printf("2 solutions complexes: %f+i%f et %f-i%f\n",v1, v2, v1, v2);
  }
}
