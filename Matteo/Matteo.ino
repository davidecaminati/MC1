
#include <Scanner.h>


#define BUTTON A0
#define BACKLIGHT 10


int bottone = 0;
 
long debounceDelay = 500;    // the debounce time
long lastDebounceTime = 0;    // the debounce time
bool keyLocked = false;
int lastreading = 0;

int optionIndex = 0;

String avviaRotazione[] = {"Oraria e Antior", "Oraria", "Antioraria"};
String numeroPassi[] = {"200","360","400"};
String giriMinuto[] = {"0.1","0.2","0.5","0.8","1","1.5"};
String sensoreInizio[] = {"Presente","Non presente"};


Scanner sc =  Scanner(3,9,11,17);
  
  
void setup() {
  Serial.begin( 9600 );
  pinMode( BACKLIGHT,OUTPUT );
  digitalWrite( BACKLIGHT,LOW );
  lcd.begin(16, 2);
    //configure menu
  menu.getRoot().add(menu1Item1);
  menu1Item1.addRight(menu1Item2).addRight(menu1Item3);
  menu1Item1.add(menuItem1SubItem1);
  menu1Item3.add(menuItem3SubItem1).addRight(menuItem3SubItem2).addRight(menuItem3SubItem3);
  menuItem3SubItem1.add(menuItem3SubItem1SubItem1);
  menuItem3SubItem2.add(menuItem3SubItem2SubItem1);
  menu.toRoot(); 
  menu.use();
  digitalWrite( BACKLIGHT,HIGH );
}
 
void loop() {
  readButtons();


  sc.Run();
}

void menuChanged(MenuChangeEvent changed){
  MenuItem newMenuItem=changed.to; //get the destination menu
}

void menuUsed(MenuUseEvent used){
  int id = used.item.getID();
  lcd.clear();
  switch (id){
    case 2: //Titolo Versione
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(Version);
      sc.Stop();
      break;
    case 3: //Avvia Rotazione
      keyLocked = true;
      optionIndex = 0;
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(used.item.getOptions()[optionIndex]);
      sc.Prepare();
      break;
    case 9: //Numero Passi
      keyLocked = true;
      optionIndex = 0;
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(used.item.getOptions()[optionIndex]);
      break;
    case 11: //Giri Minuto
      keyLocked = true;
      optionIndex = 0;
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(used.item.getOptions()[optionIndex]);
      break;
    case 17: //Sensore Inizio
      keyLocked = true;
      optionIndex = 0;
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(used.item.getOptions()[optionIndex]);
      break;
    default:
      lcd.print(used.item.getName());
      lcd.setCursor(0,1);
      lcd.print(used.item.getID());
      lcd.setCursor(0,0);  
    }
    

}

void navigateMenus() {
  MenuItem currentMenu=menu.getCurrent();
  
  switch (bottone){
    case 1: //select
      if(!(keyLocked)){
          menu.toRoot();
          menu.use();
        }
        else
        {
          saveMemoryOptions(currentMenu.getID(),(byte)optionIndex);
          lcd.setCursor(0,1);
          lcd.print("SALVATAGGIO     ");
          delay(800);
          menu.toRoot();
          menu.use();
          keyLocked = false;
          }
      break;
    case 2: //left
          keyLocked = false;
          menu.moveLeft();
          menu.use();

      break;   
    case 3: //right
        keyLocked = false;
        menu.moveRight();
        menu.use();

      break;        
    case 4:  //up
      if(!(keyLocked)){
        menu.moveUp();  
        menu.use();
        }
      else
        {
        if (optionIndex>0) {optionIndex = optionIndex-1 ;}
          byte val = readMemoryOptions(currentMenu.getID());
          lcd.setCursor(0,1);
           if ((int)val == optionIndex)
           {
             lcd.print("               *");
           }
           else
           {
             lcd.print("                ");
           }
          lcd.setCursor(0,1);
          lcd.print(currentMenu.getOptions()[optionIndex]);
        }
      break;
    case 5: //down
      if(!(keyLocked)){
        menu.moveDown();  
        menu.use();
        }
      else
        {
          if (optionIndex < (currentMenu.getNumberOptions())-1) {optionIndex = optionIndex+1 ;}
          byte val = readMemoryOptions(currentMenu.getID());
          lcd.setCursor(0,1);
           if ((int)val == optionIndex)
           {
             lcd.print("               *");
           }
           else
           {
             lcd.print("                ");
           }
          lcd.setCursor(0,1);
          lcd.print(currentMenu.getOptions()[optionIndex]);
         }
      break;
  }
}

byte readMemoryOptions(int _memPos)
{
  return  EEPROM.read(_memPos);
 }
 
 void saveMemoryOptions(int _memPos, byte _title)
{
   EEPROM.write(_memPos, _title);
}

 
void readButtons(){
  int reading = ctrlButton(analogRead(BUTTON));

  if (lastreading != reading){
    bottone = reading;
    navigateMenus();
    delay(100);
    }
    lastreading = reading;            
 }
 

int ctrlButton( int button ) {
  if ( SELECT[0] <= button && button <= SELECT[1] ) { return 1; }
  if ( LEFT[0] <= button && button <= LEFT[1] ) { return 2; }
  if ( RIGTH[0] <= button && button <= RIGTH[1] ) { return 3; }
  if ( UP[0] <= button && button <= UP[1] ) { return 4; }
  if ( DOWN[0] <= button && button <= DOWN[1] ) { return 5; }
  return 0;
}

