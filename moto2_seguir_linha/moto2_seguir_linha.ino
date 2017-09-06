#include <robo_hardware.h>
#include <Servo.h>
#define  CINZA 63

float valor_sensor_dir;
float valor_sensor_esq;

bool branco_branco()
{
     return valor_sensor_dir > CINZA && valor_sensor_esq > CINZA;
}

bool preto_preto()
{
  return valor_sensor_dir < CINZA && valor_sensor_esq < CINZA;
}

bool esqBranco_dirPreto()
{
  return valor_sensor_dir < CINZA && valor_sensor_esq > CINZA;
}  

bool esqPreto_dirBranco()
{
  return valor_sensor_dir > CINZA && valor_sensor_esq < CINZA;
}

void setup()
{
   Serial.begin(9600);
   robo.configurar(false);
}
   
void loop()
{
    //branco>65 e preto<65
  valor_sensor_esq= robo.lerSensorLinhaDir();
  valor_sensor_dir= robo.lerSensorLinhaEsq();
  
  if(preto_preto())// se os 2 fores preto, permanece parado
  {
  robo.acionarMotores(20,20);
  delay(100);
  robo.acionarMotores(20, 80);
  }  
  else if( branco_branco())// se os 2 forem branco, giram na mesma velocidade
  {
    robo.acionarMotores(40, 40);
  } 
  else if(esqBranco_dirPreto())//se esquerdo for branco e direito for preto,esquerda gira para frente e roda direita gira para tras
  { 
    robo.acionarMotores(40, 25);//esq vai para frente com 40, e dir da re com 30
  } 
  else if(esqPreto_dirBranco())//se esquerdo for preto, e direito for branco, roda esquerda para tras e direita gira para frente
  { 
    robo.acionarMotores(25, 40);//esq vai para tras com 30, e direito para frente com 40(moto ligado aos contrario)
  }       
  delay(100);
} 
