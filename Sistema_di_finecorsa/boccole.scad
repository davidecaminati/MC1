$fn=100;
diametro_vite = 4.9;
module Vite(){
    cylinder(30,diametro_vite/2,diametro_vite/2);
}


//vite();

diametro_perno =  10;
altezza_legno = 18;
altezza_rondella = 1.6;
diametro_rondella = 16;




module Mezzo_perno(){
    translate([0,0,altezza_rondella]){
        cylinder(altezza_legno/2,diametro_perno/2,diametro_perno/2);
        }
    cylinder(altezza_rondella,diametro_rondella/2,diametro_rondella/2);
}
    
    
    
 difference(){
Mezzo_perno();
Vite();
 }