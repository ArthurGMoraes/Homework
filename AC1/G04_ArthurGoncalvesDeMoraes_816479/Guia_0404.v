// Arthur Goncalves de Moraes 816479

module PoS (output S, input X, Y, Z); // MAXTERMOS
// M 5 6 7
 assign S = (~X| Y|~Z) & (~X|~Y| Z) & (~X|~Y|~Z);
endmodule // PoS

// ---------------------
// -- test_module
// ---------------------
module test_module;
reg x, y, z;
wire s1;
// instancias
PoS PoS1 (s1, x, y, z);
// valores iniciais
initial begin: start
x=1'bx; y=1'bx; z=1'bx;  // indefinidos
end
// parte principal
initial begin: main
// identificacao
$display("Guia_0403");
$display("Test boolean expression");

// monitoramento
$display("\n x  y  z = s1 ");
$monitor("%2b %2b %2b = %2b", x, y, z, s1);
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