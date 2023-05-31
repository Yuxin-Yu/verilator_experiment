module light(
  input clk,
  input rst,
  output reg [15:0] led
);

  always @(posedge clk) begin
    if (rst) begin 
        led <= 1; 
    end
    else begin
      if(end_cnt) led <= {led[14:0], led[15]};
    end
  end

  reg[31:0] cnt;
  wire      add_cnt;
  wire      end_cnt;
  always @(posedge clk or posedge rst)begin
      if(rst)begin
          cnt <= 0;
      end
      else if(add_cnt)begin
          if(end_cnt)
              cnt <= 0;
          else
              cnt <= cnt + 1;
      end
  end
  assign add_cnt = 1; 
  assign end_cnt = add_cnt && cnt== 10-1; 
  
  
endmodule