/*
 Guia_0201.v
 Arthur Goncalves de Moraes 816479
*/
module Guia_0201;
// define data
 real x = 0 ; // decimal
 real power2 = 1.0; // power of 2
 integer y = 8 ; // counter
 reg [8:0] b = 9'b1_1110_1001; // binary (only fraction part, Big Endian)
// actions
 initial
 begin : main
 $display ( "Guia_0201 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%9b", b );
 while ( y >= 0 )
 begin
 power2 = power2 / 2.0;
 if ( b[y] == 1 )
 begin
 x = x + power2;
 end
 $display ( "x = %f", x );
 y=y-1;
 end // end while
 end // main
endmodule // Guia_0201
