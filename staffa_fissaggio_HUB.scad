$fn=100;
diameter = 15;
altezza = 5;
distanza = 22;

difference(){
    translate([-21,-12,0]){
        cube([42,42,altezza]);
    }
    #hub();

}

module hub(){
    hull(){
        spostamento = sqrt((distanza * distanza ) - (distanza/2 * distanza/2));
        cylinder(altezza,diameter/2,diameter/2);
        translate([distanza/2,spostamento,0]){
            cylinder(altezza,diameter/2,diameter/2);
        }
        translate([-distanza/2,spostamento,0]){
            cylinder(altezza,diameter/2,diameter/2);
        }
    }
}


difference(){
    
 translate([-21,29,0]){
cube([42,3,20]);
 }
 
for ( i = [10,-10]){
    translate([i,35,13]){
        rotate([90,0,0]){
            cylinder(10,2,2);
        }
    }
}
}