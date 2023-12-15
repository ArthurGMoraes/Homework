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

    wire notnand1;
    wire nand1;
    nand NAND1(nand1, notB, c);
    not NOT5(notnand1, nand1);

    wire notnand2;
    wire nand2;
    nand NAND2(nand2, a, b, d);
    not NOT6(notnand2, nand2);

    wire notnand3;
    wire nand3;
    nand NAND3(nand3, notA, b, notC);
    not NOT7(notnand3, nand3);

    wire nandOr1;
    nand NAND4(nandOr1, notnand1, notnand1);

    wire nandOr2;
    nand NAND6(nandOr2, notnand2, notnand2);

    wire nandOr3;
    nand NAND7(nandOr3, notnand3, notnand3);

    nand FinalNAND(s, nandOr1, nandOr2, nandOr3);

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
        $display("R0101e - Arthur Goncalves de Moraes - 816479");
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