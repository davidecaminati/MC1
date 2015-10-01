$fn = 100;

module perno(){
    cube([33,6,6]);

translate([0,-6,0]){
    cube([5,6,6]);
}

translate([28,0,0]){
    cube([5,6,15]);
    };
}
difference(){
    perno();
    translate([25,3,12]){
        rotate([0,90,0]){
        cylinder(10,1,1);
        }
    }
}