/*
 Guia_0204.v
 Arthur Goncalves de Moraes 816479
*/
module Guia_0204;
// define data
 real x = 0.955078; // decimal
 reg [8:0] b = 9'b111101001; // binary
 integer q [4:0];
// actions
 initial
 begin : main
 $display ( "Guia_0204 - Tests" );
 $display ( "x = %f" , x );
 $display ( "b = 0.%9b", b );
 $display ( "b = 0.%x%x%x (16)", b[8],b[7:4],b[3:0] );
 q[4] = b[8];
 q[3] = b[7:6];
 q[2] = b[5:4];
 q[1] = b[3:2];
 q[0] = b[1:0];
 $display ( "b = 0.%2b %2b %2b %2b %2b (2)", b[8],b[7:6],b[5:4],b[3:2],b[1:0] );
 $display ( "q = 0.%2d %2d %2d %2d %2d (4)", q[4],q[3] ,q[2] ,q[1] ,q[0] );
 end // main
endmodule // Guia_0204
