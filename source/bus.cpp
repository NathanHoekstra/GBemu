//
// Created by Nathan on 12/07/2020.
//

#include "../include/bus.hpp"

GBemu::Bus::Bus(){
    // connect the cpu to the bus
    z80.connect_bus(this);
}

void GBemu::Bus::write(uint16_t address, uint8_t data) {
    ram[address] = data;
}

uint8_t GBemu::Bus::read(uint16_t address) {
    return ram[address];
}
