#include <stdio.h>
//FUNCIONES
float calculo_ES();
float calcular_promedio_componente(const char* componente);
void nota_cualitativa(float UT);
int main () {
    float ACD, APE, AA, ES, U, UT, b = 0, resultado;
    int c;
    
    for(c = 1; c <= 3; c++){
        printf("\n===== CALCULO DE NOTAS DE LA UNIDAD %i =====\n", c);  
        //AL MOMENTO DE LLAMAR LA FUNCION SE LE COLOCA EL NOMBRE Y LA CANTIDAD QUE SE REPITE
        ACD = calcular_promedio_componente("ACD");
        APE = calcular_promedio_componente("APE");
        AA  = calcular_promedio_componente("AA");
        //LLAMADO A LA FUNCION ES
        ES  = calculo_ES();

        //CALCULO DE UNIDAD CON SUS PONDERADOS
        U = (ACD * 0.20) + (APE * 0.25) + (AA * 0.20) + (ES * 0.35);
        
        printf("-----------------------------------\n");
        printf("NOTA FINAL DE LA UNIDAD %i : %.2f\n", c, U);
        printf("-----------------------------------\n");
        //ACUMULADOR DEL CICLO
        b = U + b; 
    }
    //CALCULO DEL TOTAL DEL CICLO
    UT = b / 3.0;
    printf("\nNota final del ciclo es: %.2f\n", UT);
    nota_cualitativa(UT); 
    return 0;
}
//FUNCIÓN DE CALCULO DE EVALUACIÓN SUMATIVA
float calculo_ES(){
    float ABP, PD, porcentajeABP, nota; 

    do{
    printf("Ingrese su nota del ABP, entre 0 y 10\n");
    scanf("%f", &ABP); 
    }while(ABP<0||ABP>10);

    do{
    printf("Ingrese su nota del Portafolio Digital, entre 0 y 10 \n");
    scanf("%f", &PD); // 
    }while(PD<0||PD>10);

    do{
        printf("Ingrese el porcentaje del ponderado del ABP de 0 a 100\n");
        scanf("%f", &porcentajeABP); 
    }while(porcentajeABP<0||porcentajeABP>100);

    nota=((ABP*porcentajeABP)+(PD*(100-porcentajeABP)))/100; // CALCULO TOTAL DE ES
    return nota;
}
//FUNCION DEL PROMEDIO POR COMPONENTE 
float calcular_promedio_componente(const char* componente) {
    int cn, i;
    float n, a = 0;

    printf("------- CALCULAR NOTA %s -------\n", componente);
     do{
        printf("Cantidad de notas a ingresar en %s: ", componente);
        scanf("%i", &cn);
        if(cn<1){
            printf("==Debe ingresar minimo 1 nota==\n");
        }
        }while(cn<1);

    for (i = 1; i <= cn; i++) {
        do {
            printf("Ingrese nota %i: ", i);
            scanf("%f", &n);
            if (n < 0 || n > 10) {
                printf("Nota invalida. Debe estar entre 0 y 10.\n");
            }
        } while (n < 0 || n > 10);
        //a = ACUMULADOR DE NOTAS
        a = n + a;
    }
    float promedio;
    //CALCULO DEL TOTAL DE CADA COMPONENTE
    promedio = a/cn;
    printf("Nota final de %s es: %.2f\n", componente, promedio);
    return promedio;
}
//FUNCION PARA LA NOTA CUALITATIVA
void nota_cualitativa(float UT){
    if (UT >= 7){
        printf("\n====NOTA CUALITATIVA: APROBADO====\n");
    }else if (UT >=2.5){
        printf("\n====NOTA CUALITATIVA: SUPLETORIO====\n");
    }else{
        printf("\n====NOTA CUALITATIVA: REPROBADO====\n");
    }
}