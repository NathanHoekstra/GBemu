//
// Created by Nathan on 12/07/2020.
//

#include "../include/cpu.hpp"
#include "../include/bus.hpp"

GBemu::Cpu::Cpu() {
    using c = Cpu;
    // TODO: populate lookup table
    lookup_table = {
            { "NOP", &c::LD, &c::IMP, 4 }, { "LD", &c::LD,  &c::IMX, 12 },
    };
}

void GBemu::Cpu::connect_bus(Bus *n) {
    bus = n;
}

void GBemu::Cpu::write(uint16_t address, uint8_t data) {
    bus->write(address, data);
}

uint8_t GBemu::Cpu::read(uint16_t address) {
    return bus->read(address);
}

void GBemu::Cpu::set_flag(GBemu::Cpu::CPU_FLAGS flag, bool value) {

}

uint8_t GBemu::Cpu::get_flag(GBemu::Cpu::CPU_FLAGS flag) {
    return 0;
}
