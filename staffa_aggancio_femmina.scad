$fn = 100;
larghezza = 60;
lunghezza = 40;


module jack_femmina(){
    diametro = 13.3;
    altezza = 55;
    cylinder(altezza,diametro/2,diametro/2);    
}




module Buchi(){

module fori_jack(larghezza,lunghezza){
    for (i = [-larghezza/2,larghezza/2] ){
        translate([i,0,0]){
            jack_femmina();
        }
    }
     translate([0,-lunghezza,0]){
        jack_femmina();
     }
 }
 
 fori_jack(larghezza,lunghezza);
 
 module connettore_usb_femmina(){
     altezza = 27;
     larghezza = 18.2;
     lunghezza = 10.7;
     cube([larghezza,lunghezza,altezza],,true);
 }
 
 for (i = [5,-10]){
     translate([0,i,55-27/2]){
        connettore_usb_femmina();
     }
 }
 
 module calamita(){
     diametro = 11.6;
     altezza = 6.6;
     cylinder(altezza,diametro/2,diametro/2);
 }
 
 for (i = [-larghezza/4,larghezza/4]){
     translate([i,-lunghezza/2,55-5.6-2]){
        calamita();
     }
 }
 }
 
 module portabuchi(){
     difference(){
            translate([0,-lunghezza/2+2,50]){
             cube([larghezza*2.5,lunghezza*2.5, 10],true);
            }
         Buchi();
        }
 }

 module Base(){
     hull(){
         moltiplicatore = 1.4;
          for (i = [-larghezza/2*moltiplicatore,larghezza/2*moltiplicatore] ){
            translate([i,9,0]){
                jack_femmina();
            }
        }
         translate([0,-lunghezza*moltiplicatore,0]){
            jack_femmina();
         }
     }
 }
 
 intersection(){
     
     portabuchi();
     Base();
 }