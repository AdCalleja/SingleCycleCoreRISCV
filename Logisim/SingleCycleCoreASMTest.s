#Logisim Tests
#[addr]
#(value inside)

.text
main:
    lw a0, 0 (a0)     # Load from Data[0+0](1) to x10(0)
    lw a1, 4 (a1)     # Load from Data[0+4](2) to x11(0)
    add a2, a1, a0    # Add 1 + 2 = 3 to x12
    sw a2, 4 (t0)     # Save x12(3) to Data[0+4]
    beq a2, a1, EQUAL # Don't brach x12(3) - x11(2) = 1
    sub a3, a2, a1    # Sub x12(3) - x11(2) = x13(1)
    sub a2, a2, a3    # Sub x12(3) - x13(1) = x12(2) a2 == a1
    beq a2, a1, EQUAL # Branch x12(2) - x11(2) = 0
    nop
    nop
    nop
    nop
EQUAL:
    and a3, a3, a2    # x13(1) AND x12(2) = x13(0)
    or a4, a3, a2     # x13(1) OR x12(2) = x14(1)