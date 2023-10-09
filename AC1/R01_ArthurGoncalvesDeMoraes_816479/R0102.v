// Nome: Arthur Goncalves de Moraes
// Matricula: 816479

module f ( output s, input a, input b, input c );
 wire w1, w2, w3, w4;
 not NOT_1 (w1, b);
 not NOT_2 (w2, c);
 and AND_1 (w3, a, w2);
 and AND_2 (w4, a, w1, c);
 or OR__1 (s, w3 ,w4);
 endmodule // s = f (a,b,c)

 module test_f;
// ------------------------- definir dados
 reg x;
 reg y;
 reg z;
 wire r;
 f modulo ( r, x, y, z );
 

// ------------------------- parte principal
 initial
 begin : main
 $display("R01 - Arthur Goncalves de Moraes - 816479");
 $display("Test module");
 $display(" x y z r");
 // projetar testes do modulo
 $monitor("%4b %4b %4b = %4b", x, y, z, r);
    x = 1'b0; y = 1'b0; z = 1'b0;
 #1 x = 1'b0; y = 1'b0; z = 1'b1;
 #1 x = 1'b0; y = 1'b1; z = 1'b0;
 #1 x = 1'b0; y = 1'b1; z = 1'b1;
 #1 x = 1'b1; y = 1'b0; z = 1'b0;
 #1 x = 1'b1; y = 1'b0; z = 1'b1;
 #1 x = 1'b1; y = 1'b1; z = 1'b0;
 #1 x = 1'b1; y = 1'b1; z = 1'b1;
 end
endmodule // test_f5

