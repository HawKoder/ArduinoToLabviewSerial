//CODE BY VINÍCIUS JEAN FERREIRA
//EASILY AND CLEAN SYSTEM TO SEND SERIAL ANALOG MEASURES TO LABVIEW
//NOTE THAT THIS IS A SIMPLE CODE AND CAN BE EASILY MODIFIED
//USE FOR YOU PROJECTS AND CONTACT ME FOR ANY DOUBT: Shout.and.Hawks@hotmail.com

#define Cord_X A4 //DEFINE COORDINATE X AS PIN ANALOG 4
#define Cord_Y A5 //DEFINE COORDINATE X AS PIN ANALOG 5

int x = 0;
int y = 0;

void setup() 
{
  pinMode(Cord_X, INPUT);
  pinMode(Cord_Y, INPUT);

   Serial.begin(9600);
}

//LOOP UNTIL SOCIALISM WORKS
void loop() 
{
  ReadADC();
  SendData();
  delay(1);
}

//SENDS DATA BY SERIAL PORT TO LABVIEW
void SendData()
{
  String dados = "";
  dados += x;
  dados += "*";
  dados += y;
  dados += "\n";
  Serial.print(dados);
}

//READS THE VALUES FROM TWO ADCs
void ReadADC()
{
  x = analogRead(Cord_X);
  y = analogRead(Cord_Y);  
}

