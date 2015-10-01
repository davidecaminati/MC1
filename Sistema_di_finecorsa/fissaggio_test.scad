
module Aggancio(){
    lunghezza_blocco = 80;
    larghezza_tubo = 25.2;
    altezza_tubo = 16;
    spessore_frame = 5;

    difference(){
        translate([0,(-larghezza_tubo - spessore_frame*2)/2,0]){
            cube([lunghezza_blocco,larghezza_tubo + spessore_frame*2 ,altezza_tubo+spessore_frame]);
        }
        translate([0,-larghezza_tubo/2,spessore_frame]){
            cube([lunghezza_blocco,larghezza_tubo,altezza_tubo]);
        }
    }
}

Aggancio();