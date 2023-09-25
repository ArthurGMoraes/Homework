// -------------------------
// Guia_0801
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------
// -------------------------
// full adder
// -------------------------
module fullAdder ( output s1,
    output s0,
    input a,
    input b,
    input carryIn );
    
    wire xor1Wire;
    wire and1Wire;
    wire and2Wire;

    xor XOR1 (xor1Wire, a, b);
    and AND1 (and1Wire, a, b);
    and AND2 (and2Wire, xor1Wire, carryIn);
    xor XOR2 (s0, xor1Wire, carryIn);
    or OR1 (s1, and2Wire, and1Wire);

endmodule // fullAdder
module test_fullAdder;
    // ------------------------- definir dados
    reg [3:0] a;
    reg [3:0] b;

    wire [4:0] carry; // “vai-um”
    wire [4:0] s;

    fullAdder FA0 ( carry[0], s[0], a[0], b[0], 1'b0 );
    fullAdder FA1 ( carry[1], s[1], a[1], b[1], carry[0] );
    fullAdder FA2 ( carry[2], s[2], a[2], b[2], carry[1] );
    fullAdder FA3 ( carry[3], s[3], a[3], b[3], carry[2] );
    fullAdder FA4 ( carry[4], s[4], 1'b0, 1'b0, carry[3] );
   

    // ------------------------- parte principal
    initial begin
        $display("Guia_0801 - Arthur Goncalves de Moraes - 816479");
        $display("Test ALU's full adder");
        $display("soma: ");

        // projetar testes do modulo
        $monitor("%4b + %4b = %5b", a, b, s);
        a = 4'b000; b = 4'b000;
        #1 a = 4'b0001; b = 4'b0000;
        #1 a = 4'b0000; b = 4'b0011;
        #1 a = 4'b0001; b = 4'b0011;
        #1 a = 4'b0101; b = 4'b1101;
        #1 a = 4'b1000; b = 4'b1000;

    end
endmodule // test_fullAdder