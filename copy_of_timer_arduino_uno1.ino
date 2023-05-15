#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(8, 9, 4,5,6,7);//Pinos do LCD.
int boton = 2; //Pinos a serem trabalhados.
int repetir = 0;

//Argumentos:  lcd(RS, EN, DB4, DB5, DB6, DB7)
/*
	RS -> 8			EN -> 9
    DB4 -> 4		DB5 -> 5
    DB6 -> 6		DB7 -> 7
*/

void setup()
{
  Serial.begin(9600);
  pinMode(boton, OUTPUT);
  sTimer(); // A função de temporizador é chamada para que o  
  			// as interrupções internas sejam ativadas.
  attachInterrupt(digitalPinToInterrupt(boton), intBoton, RISING);
  //A interrupção externa é chamada com a função.
}

void loop()
{
}
//Os relógios do temporizador são modificados para iniciar a sua função.
void sTimer() 
{
 cli(); 					//Limpar todas as interrupções.
  TCCR1A = 0X00;
  TCCR1B = 0;
  TCCR1C = 0;
  TCNT1 = 0;
  OCR1A = 15625;

  TCCR1B |= (1 << CS12);
  TCCR1B |= (1<< WGM12);
  sei(); 					//As interrupções são estabelecidas.
}

//Função para definir TIMSK1 como 1 ou 0.
void intBoton () 
{
  Serial.println("intBoton");
  if (repetir == 0 )
   {                       
     TIMSK1 |= (1<<OCIE1A);
     repetir = 1 ;
   //lcd.begins(#columnas, #renglones)
 	lcd.begin(16,2);
  lcd.clear(); //Limpar LCD        
  imprimir();
   }
  else{
     TIMSK1 &= !(1 << OCIE1A);
     repetir = 0;
   }
  Serial.println(repetir);
}

ISR(TIMER1_COMPA_vect) 
{
  lcd.setCursor(16,1); //começa a gerar movimento para a esquerda
  lcd.autoscroll();//gerar movimento
  lcd.print(" ");
}

void imprimir(){
  
   for (int palavra=0; palavra<=16; palavra++){   // avança de 1 em 1 a cada 1000ms para cada coluna do LCD
lcd.setCursor (palavra,0);                       // começa da linha 0 à linha 16 
lcd.print ("Bem vindo(a)");
lcd.setCursor (palavra,1);
lcd.print ("Aluno(a): ");
delay (200);
lcd.clear(); 
  }
   for (int palavra=0; palavra<=16; palavra++){   // avança 1 por 1 a cada 1000ms para cada coluna do LCD
lcd.setCursor (palavra,0);                       // começa da linha 0 à linha 16 
lcd.print ("");                  //Nome do aluno(a)
lcd.setCursor (palavra,1);
lcd.print ("");                 //Sobrenome 
delay (200);
lcd.clear(); 
  }
   for (int palavra=16; palavra>=0; palavra--){ //retornar 1 para 1 a cada 500ms para cada coluna do LCD
lcd.setCursor (palavra,0);                     // começa da linha 16 para a linha 0 
lcd.print ("Matricula:");
lcd.setCursor (palavra,1);
lcd.print ("000000");
delay (200);
lcd.clear();    

}
}