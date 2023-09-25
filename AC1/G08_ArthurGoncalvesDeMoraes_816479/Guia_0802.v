// -------------------------
// Guia_0802
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------
// -------------------------
// full Sub
// -------------------------
module fullSub ( output s1,
    output s0,
    input a,
    input b,
    input carryIn );
    
    wire xor1Wire;
    wire and1Wire;
    wire and2Wire;

    wire not1;
    wire not2;

    not NOT1 (not1, a);
    not NOT2 (not2, xor1Wire);

    xor XOR1 (xor1Wire, a, b);
    and AND1 (and1Wire, not1, b);
    and AND2 (and2Wire, not2, carryIn);
    xor XOR2 (s0, xor1Wire, carryIn);
    or OR1 (s1, and2Wire, and1Wire);

endmodule // fullSub
module test_fullSub;
    // ------------------------- definir dados
    reg [3:0] a;
    reg [3:0] b;

    wire [4:0] carry; // “vai-um”
    wire [4:0] s;

    fullSub FA0 ( carry[0], s[0], a[0], b[0], 1'b0 );
    fullSub FA1 ( carry[1], s[1], a[1], b[1], carry[0] );
    fullSub FA2 ( carry[2], s[2], a[2], b[2], carry[1] );
    fullSub FA3 ( carry[3], s[3], a[3], b[3], carry[2] );
    fullSub FA4 ( carry[4], s[4], 1'b0, 1'b0, carry[3] );
   

    // ------------------------- parte principal
    initial begin
        $display("Guia_0802 - Arthur Goncalves de Moraes - 816479");
        $display("Test ALU's full sub");
        $display("soma: ");

        // projetar testes do modulo
        $monitor("%4b - %4b = %5b", a, b, s);
        a = 4'b000; b = 4'b000;
        #1 a = 4'b0001; b = 4'b0000;
        #1 a = 4'b0000; b = 4'b0011;
        #1 a = 4'b0001; b = 4'b0011;
        #1 a = 4'b0101; b = 4'b1101;
        #1 a = 4'b1000; b = 4'b1000;

    end
endmodule // test_sub