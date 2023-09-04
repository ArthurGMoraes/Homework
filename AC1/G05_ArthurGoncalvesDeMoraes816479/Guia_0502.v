// -------------------------
// Guia_0502.v - GATES
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------
// -------------------------

module f5a ( output s,
 input a,
 input b );
// definir dado local
 wire c;
 wire d;
 wire not_b;
// descrever por portas
 nand NAND1 (not_b, b, b);
 nand NAND2 ( c, a, 1 );
 nand NAND3 ( d, 1, not_b );
 nand NAND4 ( s, c, d );
endmodule // f5a

module f5b ( output s,
 input a,
 input b );
// descrever por expressao
 assign s = a | ~b;
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
 $display("Guia_0502 - Arthur Goncalves de Moraes - 816479");
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