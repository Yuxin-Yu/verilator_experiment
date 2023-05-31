#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"
#include "Valu___024unit.h"

#define MAX_SIM_TIME 200
vluint64_t sim_time = 0;

int main(int argc, char** argv, char** env) {
    Valu *dut = new Valu;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut->clk ^= 1;
        int a = rand() % 64;
        int b = rand() % 64;
        dut->a_in = a;
        dut->b_in = b;
        dut->op_in = rand() % 3;
        dut->in_valid = rand() % 2;
        dut->eval();
        printf("a = %d, b = %d, out = %d out_valid = %d\n", a, b, dut->out,dut->out_valid);
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
