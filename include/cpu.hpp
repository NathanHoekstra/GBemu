//
// Created by Nathan on 12/07/2020.
//

#ifndef GBEMU_CPU_HPP
#define GBEMU_CPU_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace GBemu {
    // forward decelerate the bus to prevent circular inclusions
    class Bus;

    class Cpu {
    public:
        Cpu();

        void connect_bus(Bus *n);

        enum CPU_FLAGS {
            C = (1 << 4),   // Carry Flag
            H = (1 << 5),   // Half Carry Flag
            N = (1 << 6),   // Subtract Flag
            Z = (1 << 7)    // Zero Flag
        };
        // cpu registers
        uint8_t a = 0x00;       // Accumulator register
        uint8_t b = 0x00;       // B register
        uint8_t c = 0x00;       // C register
        uint8_t d = 0x00;       // D register
        uint8_t e = 0x00;       // E register
        uint8_t f = 0x00;       // Flag register
        uint8_t h = 0x00;       // H register
        uint8_t l = 0x00;       // L register
        uint16_t sp = 0x0000;   // Stack Pointer
        uint16_t pc = 0x0000;   // Program Counter

        // addressing modes
        uint8_t IMP(); uint8_t IMM();
        uint8_t IMX(); uint8_t REG();
        uint8_t ABS(); uint8_t IND();
        uint8_t ABX(); uint8_t MPZ();
        uint8_t REL();

        // opcodes
        uint8_t ADC();  uint8_t ADD();  uint8_t AND();  uint8_t BIT();
        uint8_t CALL(); uint8_t CCF();  uint8_t CPL();  uint8_t CP();
        uint8_t DAA();  uint8_t DEC();  uint8_t DI();   uint8_t EI();
        uint8_t HALT(); uint8_t INC();  uint8_t JP();   uint8_t JR();
        uint8_t LD();   uint8_t LDD();  uint8_t LDH();  uint8_t LDI();
        uint8_t NOP();  uint8_t OR();   uint8_t POP();  uint8_t PUSH();
        uint8_t RES();  uint8_t RET();  uint8_t RETI(); uint8_t RLA();
        uint8_t RLCA(); uint8_t RLC();  uint8_t RL();   uint8_t RRA();
        uint8_t RRCA(); uint8_t RRC();  uint8_t RR();   uint8_t RST();
        uint8_t SBC();  uint8_t SCF();  uint8_t SET();  uint8_t SLA();
        uint8_t SRA();  uint8_t SRL();  uint8_t STOP(); uint8_t SUB();
        uint8_t SWAP(); uint8_t XOR();  uint8_t LDHL(); uint8_t XXX();

        void clock();
        void reset();
        void irq();
        void nmi();

        uint8_t  opcode = 0x00;
        uint8_t cycles = 0x00;

    private:
        Bus     *bus = nullptr;
        void    write(uint16_t address, uint8_t data);
        uint8_t read(uint16_t address);

        void    set_flag(CPU_FLAGS flag, bool value);
        uint8_t get_flag(CPU_FLAGS flag);

        struct INSTRUCTION {
            std::string name;
            uint8_t(Cpu::*opcode)(void) = nullptr;
            uint8_t(Cpu::*addressing_mode)(void) = nullptr;
            uint8_t cycles = 0;
        };

        std::vector<INSTRUCTION> lookup_table;
    };

} // GBemu namespace

#endif //GBEMU_CPU_HPP
