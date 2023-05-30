#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
#include "Vlight.h"   //Verilator生成的头文件
#include "stdio.h"
#include <stdlib.h>

vluint64_t main_time = 0;  //initial 仿真时间
 
Vlight *light = new Vlight("light"); //调用Vlight.h里面的IO struct
 VerilatedVcdC* tfp = new VerilatedVcdC; //导出vcd波形需要加此语句

double sc_time_stamp()
{
    return main_time;
}

void single_cycle(){
    light->clk = 1;
    light->eval();
    tfp->dump(main_time); //dump wave
    main_time++; //推动仿真时间

    light->clk = 0; 
    light->eval();
    tfp->dump(main_time); //dump wave
    main_time++; //推动仿真时间
}

void reset(int n){
    light->rst = 1; 
    while (n-->0)
    {
        single_cycle();
    }
    light->rst = 0; 
}
 
int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv); 
    Verilated::traceEverOn(true); //导出vcd波形需要加此语句
    
    light->trace(tfp, 0);   
    tfp->open("wave.vcd"); //打开vcd
    reset(10);
    while (sc_time_stamp() < 500 && !Verilated::gotFinish()) { //控制仿真时间
        single_cycle();
		printf("led = %d \n",light->led);
    }
    light->final();
    tfp->close();
    delete light;
 
    return 0;
}

