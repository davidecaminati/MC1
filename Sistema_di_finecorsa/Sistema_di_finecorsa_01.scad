$fn = 100;
larghezza = 50;
spessore = 3;
for (i = [larghezza/2,-larghezza/2]){
    translate([0,i,0]){
        difference() {
            cube ([20,spessore,20],true);
                rotate([90,0,0]){
                    #cylinder(5,5,5,true);
            }
        }
    }
}
translate([0,0,-10]){
    cube([20,larghezza+spessore,spessore],true);
}