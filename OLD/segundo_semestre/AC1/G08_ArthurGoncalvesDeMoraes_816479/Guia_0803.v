// -------------------------
// Guia_0803
// Nome: Arthur Goncalves de Moraes
// Matricula: 816479
// -------------------------
// -------------------------
// Comparison Igualdade
// -------------------------
module compBit (output compS1,
    input a,
    input b);

    xnor XNOR1 (compS1, a, b);

endmodule
    
module compTudo(output compS0, input a, input b, input c, input d);
    wire and0;
    wire and1;
    and AND0 (and0, a, b);
    and AND1 (and1, and0, c);
    and AND2 (compS0, and0, d);
endmodule    

module test_comp;
    // ------------------------- definir dados
    reg [3:0] a;
    reg [3:0] b;

    wire [3:0] final;

    wire resultado;
    
    compBit CB0 ( final[0], a[0], b[0]);
    compBit CB1 ( final[1], a[1], b[1]);
    compBit CB2 ( final[2], a[2], b[2]);
    compBit CB3 ( final[3], a[3], b[3]);
    compTudo CT0 ( resultado, final[0], final[1], final[2], final[3]);
   

    // ------------------------- parte principal
    initial begin
        $display("Guia_0803 - Arthur Goncalves de Moraes - 816479");
        $display("Test comp");
        $display("soma: ");

        // projetar testes do modulo
        $monitor("%4b e %4b = %b", a, b, resultado );
        a = 4'b000; b = 4'b000;
        #1 a = 4'b0001; b = 4'b0000;
        #1 a = 4'b0000; b = 4'b0011;
        #1 a = 4'b0001; b = 4'b0011;
        #1 a = 4'b0101; b = 4'b1101;
        #1 a = 4'b1000; b = 4'b1000;

    end
endmodule // test_comp