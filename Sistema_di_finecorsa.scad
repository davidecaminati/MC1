$fn = 100;
larghezza = 50+25;
spessore = 3;
lunghezza = 25;
altezza = 20-3;


module part_portaswitch(){
    for (i = [larghezza/2,-larghezza/2]){
        translate([0,i,0]){
            difference() {
                cube ([lunghezza,spessore,altezza],true);
                    rotate([90,0,0]){
                        cylinder(5,5,5,true);
                }
            }
        }
    }
    translate([0,0,-altezza/2]){
        cube([lunghezza,larghezza+spessore,spessore],true);
    }
}


for (i = [lunghezza/2-spessore/2]){
    translate([i,0,0]){
        rotate([0,90,0]){
            cube([lunghezza-spessore*2,larghezza+spessore/2,spessore],true);
        }
    }
}
/*
for (i = [-lunghezza/2+spessore/2]){
    translate([i,0,-6]){
        rotate([0,90,0]){
            cube([lunghezza/2-spessore*2,larghezza+spessore/2,spessore],true);
        }
    }
}

*/
module portaswitch(){
    difference(){
        part_portaswitch();
        translate([0,0,-altezza/2-spessore]){
            cylinder(6,2,2);
        }
    }
}

portaswitch();