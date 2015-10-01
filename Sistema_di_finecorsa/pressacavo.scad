$fn=100;
diametro_filo = 4;

diametro_viti_fissaggio = 2.6;

module Staffa(){
    cube([10,20,3]);
    translate([0,10,0]){
        rotate([0,90,0]){
                cylinder(10,5,5);
        }
    }
}


module Occhiello(){
    difference(){
        Staffa();
        {
        rotate([0,90,0]){
            translate([-1,10,0]){
                cylinder(10,diametro_filo/2,diametro_filo/2);
            }
            }
        }
    }
}

module Pressacavo(){
    difference(){
        Occhiello();
        {
            for ( i = [3,17]){
                translate([5,i,0]){
                    cylinder(5,diametro_viti_fissaggio/2,diametro_viti_fissaggio/2);
                }
            }
        translate([-1,-1,-10]){
            cube([12,22,10]);
            
            }
        }
    }
}

Pressacavo();