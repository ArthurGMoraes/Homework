// -------------------------
// Guia_0506.v - GATES
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------
// -------------------------

module f5a ( output s,
    input a,
    input b );

    wire c;
    wire d;
    wire e;

    // descrever por portas
    nand NAND1 ( c, a, b );
    nand NAND2 ( d, c, a );
    nand NAND3 ( e, c, b );
    nand NAND4 ( s, e, d );
endmodule // f5a
// -------------------------

module f5b ( output s,
 input a,
 input b );
// descrever por expressao
 assign s =   a ^ b;
endmodule // f5b

module test_f5;
// ------------------------- definir dados
 reg x;
 reg y;
 wire a, b;
 f5a moduloA ( a, x, y );
 f5b moduloB ( b, x, y );

// ------------------------- parte principal
 initial
 begin : main
 $display("Guia_0506 - Arthur Goncalves de Moraes - 816479");
 $display("Test module");
 $display(" x y a b");
 // projetar testes do modulo
 $monitor("%4b %4b %4b %4b", x, y, a, b);
 x = 1'b0; y = 1'b0;
 #1 x = 1'b0; y = 1'b1;
 #1 x = 1'b1; y = 1'b0;
 #1 x = 1'b1; y = 1'b1;
 end
endmodule // test_f5