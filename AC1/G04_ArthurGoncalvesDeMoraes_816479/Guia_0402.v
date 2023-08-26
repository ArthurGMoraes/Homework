// Arthur Goncalves de Moraes 816479

module fxyz (output s1, output s2, input x, y, z);
assign s1 = ( ~x | ~y ) | ( x & ~y );
assign s2 = ~y & (x & ~y);
endmodule // fxyz


// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, z;
wire s1;
wire s2;
// instancias
fxyz FXYZ1 (s1, s2, x, y, z);
// valores iniciais
initial begin: start
x=1'bx; y=1'bx; z=1'bx; // indefinidos
end
// parte principal
initial begin: main
// identificacao
$display("Guia_0402");
$display("Test boolean expression");
$display("\n( ~x | ~y ) | ( x & ~y ) = s1");
$display("\n~y & (x & ~y) = s2");
// monitoramento
$display("\n x  y  z = s1  = s2");
$monitor("%2b %2b %2b = %2b  = %2b", x, y, z, s1, s2);
// sinalizacao
#1 x=0; y=0; z = 0;
#1 x=0; y=0; z = 1;
#1 x=0; y=1; z = 0;
#1 x=0; y=1; z = 1;
#1 x=1; y=0; z = 0;
#1 x=1; y=0; z = 1;
#1 x=1; y=1; z = 0;
#1 x=1; y=1; z = 1;
end
endmodule // test_module
