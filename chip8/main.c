#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void execute()
{
    /*
    nnn or addr - A 12-bit value, the lowest 12 bits of the instruction
    n or nibble - A 4-bit value, the lowest 4 bits of the instruction
    x - A 4-bit value, the lower 4 bits of the high byte of the instruction
    y - A 4-bit value, the upper 4 bits of the low byte of the instruction
    kk or byte - An 8-bit value, the lowest 8 bits of the instruction
    */
    uint8_t X, Y, kk, n;

    switch (opcode & 0xF000)
    {
            case 0x0000:

            switch(opcode & 0x0FF){
                //00E0 - CLS Clear display
                case 0x00E0:
                //TODO
                break;

                //0x0E0 - RET Return from a subroutine
                case 0x0EE:
                //TODO
                break;

                default: printf("Opcode error 0xxx -> %x\n", opcode);
            }break;

            //1nnn - JP Addr - Jump to location nnn
            case 0x1000:
            PC = nnn;
            break;

            //2nnn - CALL addr
            case 0x2000:
            //TODO
            break;

            //3xkk - SE Vx, byte - skip next instruction if Vx = kk
            case 0x3000:
            if (v[X] == kk) PC += 2;
            break;

            //4xkk - SNE Vx, byte - Skip next instruction if Vx != kk
            case 0x4000:
            if (v[X] != kk) PC += 2;
            break;

            //5xy0 - SE Vx, Vy - Skip next instruction if Vx = Vy
            case 0x5000:
            if (v[X] == v[Y]) PC += 2;
            break;

            //6xkk - LD Vx, byte - Set Vx = kk
            case 0x6000:
            v[X] = kk;
            break;

            //7xkk - ADD Vx, byte - Set Vx = Vx + kk
            case 0x7000:
            v[(X)] += kk;
            break;

            //8xxx
            case 0x8000:
            switch(n){
                    //8xy0 - LD Vx, Vy - Set Vx = Vy
                    case 0x0000:
                    //TODO
                    break;

                    //8xy1 - OR Vx, Vy - Set Vx = Vx OR Vy
                    case 0x0001:
                    //TODO
                    break;

                    //8xy2 - AND Vx, Vy - Set Vx = Vx AND Vy
                    case 0x0002:
                    //TODO
                    break;

                    //8xy3 - XOR Vx, Vy - Set Vx = Vx XOR Vy
                    case 0x0003:
                    //TODO
                    break;

                    //8xy4 - ADD Vx, Vy - Set Vx = Vx + Vy, set VF = carry
                    case 0x0004:
                    //TODO
                    break;

                    //8xy5 - SUB Vx, Vy - Set Vx = Vx - Vy, set VF = not borrow
                    case 0x0005:
                    //TODO
                    break;

                    //8xy6 - SHR Vx {, Vy} - Set Vx = Vx SHR 1
                    case 0x0006:
                    //TODO
                    break;

                    //8xy7 - SUBN Vx, Vy - Set Vx = Vy - Vx, set VF = NOT borrow.
                    case 0x0007:
                    //TODO
                    break;

                    //8xyE - SHL Vx {, Vy} - Set Vx = Vx SHL 1.
                    case 0x0008:
                    //TODO
                    break;

                    //9xy0 - SNE Vx, Vy - Skip next instruction if Vx != Vy.
                    case 0x0009:
                    //TODO
                    break;

                    default: printf("Opcode error 8xxx -> %x\n",opcode );
            }
            break;

            //9xy0 - SNE Vx, Vy - Skip next instruction if Vx != Vy.
            case 0x9000:
            //TODO
            break;

            //Annn - LD I, addr - Set I = nnn.
            case 0xA000:
            //TODO
            break;

            //Bnnn - - JP V0, addr - Jump to location nnn + V0.
            case 0xB000:
            //TODO
            break;

            //Cxkk - RND Vx, byte - Set Vx = random byte AND kk.
            case 0xC000:
            //TODO
            break;

            //Dxyn - DRW Vx, Vy, nibble - Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
            case 0xD000:
            //TODO
            break;

            //Ex9x
            case 0xE000:
            switch(kk){
                //Ex9E - SKP Vx - Skip next instruction if key with the value of Vx is pressed.
                case 0x009E:
                //TODO
                break;
                //ExA1 - SKNP Vx - Skip next instruction if key with the value of Vx is not pressed.
                case 0x00A1:
                //TODO
                break;
            }
            //TODO
            break;

            case 0xF000:
            switch(kk){
                //Fx07 - LD Vx, DT - Set Vx = delay timer value.
                case 0x0007:
                //TODO
                break;
                //Fx0A - LD Vx, K - Wait for a key press, store the value of the key in Vx.
                case 0x000A:
                //TODO
                break;
                //Fx15 - LD DT, Vx - Set delay timer = Vx.
                case 0x0015:
                //TODO
                break;
                //Fx18 - LD ST, Vx - Set sound timer = Vx.
                case 0x0018:
                //TODO
                break;
                //Fx1E - ADD I, Vx - Set I = I + Vx.
                case 0x001E:
                //TODO
                break;
                //Fx29 - LD F, Vx - Set I = location of sprite for digit Vx.
                case 0x0029:
                //TODO
                break;
                //Fx33 - LD B, Vx - Store BCD representation of Vx in memory locations I, I+1, and I+2.
                case 0x0033:
                //TODO
                break;
                //Fx55 - LD [I], Vx - Store registers V0 through Vx in memory starting at location I.
                case 0x055:
                //TODO
                break;
                //Fx65 - LD Vx, [I] - Read registers V0 through Vx from memory starting at location I.
                case 0x0065:
                //TODO
                break;
            }

    }

}
