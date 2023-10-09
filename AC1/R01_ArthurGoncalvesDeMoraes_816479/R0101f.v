// -------------------------
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------

module fullCirc ( output s,
    input a,
    input b,
    input c,
    input d );

    wire notA;
    not NOT1(notA, a);
    wire notB;
    not NOT2(notB, b);
    wire notC;
    not NOT3(notC, c);
    wire notD;
    not NOT4(notD, d);

    wire nor1;
    nor NOR1(nor1, b, c);
    wire nor1B;
    nor NOR1B(nor1B, nor1, nor1);

    wire nor2;
    nor NOR2(nor2, notA, notB, d);
    wire nor2B;
    nor NOR2B(nor2B, nor2, nor2);

    wire nor3;
    nor NOR3(nor3, a, notB, notC);
    wire nor3B;
    nor NOR3B(nor3B, nor3, nor3);

    wire nor4A;
    nor NOR4A(nor4A, nor2B, nor2B);
    wire nor4B;
    nor NOR4B(nor4B, nor1B, nor1B);
    wire nor4C;
    nor NOR4C(nor4C, nor4A, nor4B);

    wire nor5A;
    nor NOR5A(nor5A, nor4C, nor4C);
    wire nor5B;
    nor NOR5B(nor5B, nor3B, nor3B);
    nor NOR5C(s, nor5A, nor5B);

endmodule // fullCirc

module main;
    // ------------------------- definir dados
    reg a;
    reg b;
    reg c;
    reg d;
    wire s;

    fullCirc mainCirc (s, a, b, c, d);

    // ------------------------- parte principal
    initial begin
        $display("R0101f - Arthur Goncalves de Moraes - 816479");
        $display("   a    b    c    d     s ");
        // projetar testes do modulo
        $monitor("%5b %5b %5b %5b %5b",a,b,c,d,s);
           a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b0;
        #1 a = 1'b0; b = 1'b0; c = 1'b0; d = 1'b1;
        #1 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b0;
        #1 a = 1'b0; b = 1'b0; c = 1'b1; d = 1'b1;
        #1 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b0;
        #1 a = 1'b0; b = 1'b1; c = 1'b0; d = 1'b1;
        #1 a = 1'b0; b = 1'b1; c = 1'b1; d = 1'b0;
        #1 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1;
        #1 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b0;
        #1 a = 1'b1; b = 1'b0; c = 1'b0; d = 1'b1;
        #1 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b0;
        #1 a = 1'b1; b = 1'b0; c = 1'b1; d = 1'b1;
        #1 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b0;
        #1 a = 1'b1; b = 1'b1; c = 1'b0; d = 1'b1;
        #1 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b0;
        #1 a = 1'b1; b = 1'b1; c = 1'b1; d = 1'b1;

    end
endmodule 