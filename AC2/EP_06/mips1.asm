.text
lui $t0, 0x1001
lw $s0, 0($t0)

slt $t1, $s0, $zero

beq $t1, $zero, pos
mult $s0, $s0
mflo $t2
mult $t2, $s0
mflo $t2
addi $s1, $t2, 1
j fim 

pos:
mult $s0, $s0
mflo $t2
mult $t2, $s0
mflo $t2
mult $t2, $s0
mflo $t2
addi $s1, $t2, -1

fim: 
sw $s1, 4($t0)

.data
x: -2
