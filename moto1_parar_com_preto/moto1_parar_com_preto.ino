#include <robo_hardware.h>
#include <Servo.h>
#define  CINZA 65

float valor_sensor_dir;
float valor_sensor_esq;

bool branco_branco()
{
  return valor_sensor_dir > CINZA && valor_sensor_esq > CINZA;
}

bool preto_preto()
{
  valor_sensor_dir < CINZA && valor_sensor_esq < CINZA;
}

bool esqBranco_dirPreto()
{
  valor_sensor_dir < CINZA && valor_sensor_esq > CINZA;
}  

bool esqPreto_dirBranco()
{
  valor_sensor_dir > CINZA && valor_sensor_esq < CINZA;
} 

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
}

void loop(){
  //branco>65 e preto<65
  
  valor_sensor_esq= robo.lerSensorLinhaDir();
  valor_sensor_dir= robo.lerSensorLinhaEsq();
  
  if(preto_preto()){// se os 2 fores preto, permanece parado
    robo.acionarMotores(0,0);
  }  
  else if( branco_branco() ){// se os 2 forem branco, giram na mesma velocidade
    robo.acionarMotores(-40,-40);
  } 
  else if(esqBranco_dirPreto()){ //se esquerdo for branco e direito for preto,esquerda gira e roda direita para
    robo.acionarMotores(-40,0);
  } 
  else if(esqPreto_dirBranco){ //se esquerdo for preto, e direito for branco, roda esquerda para e direita gira
    robo.acionarMotores(0,-40);
  } 
} 
