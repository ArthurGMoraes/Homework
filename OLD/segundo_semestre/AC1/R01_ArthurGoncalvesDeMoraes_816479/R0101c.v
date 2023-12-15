// -------------------------
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------

module f ( output s,
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

    wire and1;
    and AND1(and1, notB, c);

    wire and2;
    and AND2(and2, a, b, d);

    wire and3;
    and AND3(and3, notA, b, notC);

    or OR(s, and1, and2, and3);

endmodule // f

module main;
    // ------------------------- definir dados
    reg a;
    reg b;
    reg c;
    reg d;
    wire s;

    f mainCirc (s, a, b, c, d);

    // ------------------------- parte principal
    initial begin
        $display("R0101c - Arthur Goncalves de Moraes - 816479");
        $display("   a    b    c    d    s ");
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