$fn = 100;
larghezza = 80;
spessore = 3;
for (i = [larghezza/2,-larghezza/2]){
    translate([0,i,-1]){
        difference() {
            cube ([20,spessore,17],true);
                rotate([90,0,0]){
                    cylinder(5,5,5,true);
            }
        }
    }
}
translate([0,0,-10]){
    cube([20,larghezza+spessore,spessore],true);
}

for (i = [-larghezza/2+13,larghezza/2-13]){
    translate([-9,i,-1]){
        cube([2,25,17],true);
    }
}


module Aggancio(){
    lunghezza_blocco = 70;
    larghezza_tubo = 25.2;
    altezza_tubo = 16;
    spessore_frame = 4;

    difference(){
        translate([0,(-larghezza_tubo - spessore_frame*2)/2,0]){
            cube([lunghezza_blocco,larghezza_tubo + spessore_frame*2 ,altezza_tubo+spessore_frame]);
        }
        translate([0,-larghezza_tubo/2,spessore_frame]){
            cube([lunghezza_blocco,larghezza_tubo,altezza_tubo]);
        }
    }
}

translate([-10,0,-11.5]){
Aggancio();
}