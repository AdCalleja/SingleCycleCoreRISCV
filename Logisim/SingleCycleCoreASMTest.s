#Logisim Test

.text
main:
    lw a0, 0 (a0)
    lw a1, 8 (a1)
    add a2, a1, a0
    sw a2, 8 (t0)
    beq a2, a1, EQUAL #6 - 5
    sub a3, a2, a1 #6 - 5
    sub a2, a2, a3 #6 - 1 = 5: a2 == a1
    beq a2, a1, EQUAL
    nop
    nop
    nop
    nop
EQUAL:
    and a3, a3, a2 #1 AND 5 = 1
    or a4, a3, a2 #1 OR 5 = 5
