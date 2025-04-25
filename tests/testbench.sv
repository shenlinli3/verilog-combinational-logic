module testbench;
    /* verilator lint_off UNOPTFLAT */
    logic A, B;         
    logic Y;           
    /* verilator lint_on UNOPTFLAT */

    // 实例化与门
    and_gate uut (.A(A), .B(B), .Y(Y)); 

    initial begin
        // 初始化并打印初始状态
        A = 0; B = 0; 
        output_and_display();

        // 变更输入并打印输出
        A = 0; B = 1; 
        output_and_display();

        A = 1; B = 0; 
        output_and_display();

        A = 1; B = 1; 
        output_and_display();
        
        $finish; // 结束仿真
    end

    // 自定义任务以输出状态
    task output_and_display();
        begin
            // 测试结果输出
            $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);
        end
    endtask
endmodule