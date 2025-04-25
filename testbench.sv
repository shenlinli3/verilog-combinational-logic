module testbench;
    logic A, B;
    logic Y; // 定义 Y 输出
    logic clk; // 添加一个时钟信号

    and_gate uut (.A(A), .B(B), .Y(Y)); // 实例化与门

    // 时钟生成
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 每 5 单位时间反转一次时钟
    end

    // 测试过程
    initial begin
        // 初始化 A 和 B，并打印 Y 的值
        A = 0; B = 0;         // 初始输入
        @(posedge clk);      // 等待时钟上升沿
        $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);

        A = 0; B = 1;         // 改变输入
        @(posedge clk);
        $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);
        
        A = 1; B = 0; 
        @(posedge clk);
        $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);
        
        A = 1; B = 1; 
        @(posedge clk);
        $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);
        
        $finish; // 结束仿真
    end
endmodule