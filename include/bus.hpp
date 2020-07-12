//
// Created by Nathan on 12/07/2020.
//

#ifndef GBEMU_BUS_HPP
#define GBEMU_BUS_HPP

#include <cstdint>
#include <array>

#include "../include/cpu.hpp"

namespace GBemu {

    class Bus {
    public:
        Bus();

        void    write(uint16_t address, uint8_t data);
        uint8_t read(uint16_t address);

    private:
        // bus devices
        Cpu z80;

        // 64 KB RAM
        std::array<uint8_t, 64 * 1024> ram = {};
    };

} // namespace Gbemu

#endif //GBEMU_BUS_HPP
