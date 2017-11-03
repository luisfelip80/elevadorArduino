  
#include <Stepper.h>  // Adicionar a biblioteca para que o arduino possa se comunicar com o motor.
int r, ab, b, i, g, l; // declaraçao de variaveis
int andar; // declaraçao de variaveis. Variavel onde vao ser armazenados os valores do andares.
int comando; // declaraçao de variaveis. Variavel onde vao ser armazenados os valores dos comando.
const int stepsPerRevolution = 500;   // Giros do motor.
 
// Inicializa a biblioteca utilizando as portas de 22, 24, 26, 28 para  
// ligacao ao motor  
Stepper myStepper(stepsPerRevolution, 22, 24, 26, 28);        
   
void setup()   
{ 
  // declaraçao dos pinos de entrada e saida de informaçao
  pinMode (48, INPUT_PULLUP);
  pinMode (50, INPUT_PULLUP);
  pinMode (46, INPUT_PULLUP);
  pinMode(53, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(35, OUTPUT);
  myStepper.setSpeed(50); //Determina a velocidade do motor  
}  
   
    void loop()  {
  
    // luzes que irao indicar o andar pedido ou comando.
    digitalWrite (35, 0);
    digitalWrite (37, 0);
    digitalWrite (39, 0);
  
    // Essa parte analiza em que andar a cabine esta.
    if (!digitalRead(48)) {    
      andar=2;
    }
    else if (!digitalRead(50)) {
      andar=3;
    }
    else if (!digitalRead(46)) {
      andar=1;
    }  
    
    // Essa parte mostra em que andar a cabine esta no LCD de 7 seguimentos.
    if (andar == 1) {
  digitalWrite  (53, 0);
   digitalWrite (51, 0);
   digitalWrite (49, 0);
   digitalWrite (47, 0);
   digitalWrite (45, 1);
   digitalWrite (43, 0);
   digitalWrite (41, 1);
   }
   else if (andar == 2){
  digitalWrite  (53, 1);
   digitalWrite (51, 1);
   digitalWrite (49, 1);
   digitalWrite (47, 1);
   digitalWrite (45, 1);
   digitalWrite (43, 0);
   digitalWrite (41, 0);
   }
   else if (andar== 3){
  digitalWrite  (53, 0);
   digitalWrite (51, 1);
   digitalWrite (49, 1);
   digitalWrite (47, 1);
   digitalWrite (45, 1);
   digitalWrite (43, 0);
   digitalWrite (41, 1);
   }
     
   // Essa parte analiza os andares que so pedidos de acordo com a entreda digital que recebe energia.
   if (digitalRead(40)) {
   comando = 1;
   digitalWrite (39, 1);
   }
   else if (digitalRead(42)) {
   comando = 2;
   digitalWrite (37, 1);
   }
   else if (digitalRead(44)) {
   comando = 3;
   digitalWrite (35, 1);
   }
   
   // Leva a cabine ao andar determinado pelo comando.
   if (comando == 1 & andar > 1) {
   digitalWrite (39, 1);
   myStepper.step(-1); 
   }
   else if (comando == 2 & andar == 3) {
   digitalWrite (37, 1);
   myStepper.step(-1); 
   }
   else if (comando == 2 & andar == 1) {
   digitalWrite (37, 1);
     myStepper.step(1); 
   }
   else if (comando == 3 & andar == 1) {
   digitalWrite (35, 1);   
   myStepper.step(1);
   }
   else if (comando == 3 & andar == 2) {
   digitalWrite (35, 1);   
   myStepper.step(1);
   }
   // Limpa a variavel de comandos depois de chegar no andar desejado.
    if (comando==1 & andar==1) {
            comando=0;
    }
    else if (comando == 2 & andar== 2) {
            comando=0;
    }
    else if (comando == 3 & andar== 3) {
            comando=0;
    }
    
}