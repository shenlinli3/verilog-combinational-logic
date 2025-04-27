module testbench;
    /* verilator lint_off UNOPTFLAT */
    logic A, B;         
    logic Y;           
    /* verilator lint_on UNOPTFLAT */

    // 实例化与门
    and_gate uut (.A(A), .B(B), .Y(Y)); 

    initial begin
    // 初始化
        A = 0; B = 0;
        $timeformat(-12, 0, " ps", 20); // 显式设置时间格式
        output_and_display();

        // 变更输入并触发评估
        A = 0; B = 1;
        $eval(); // 关键：手动触发组合逻辑评估
        output_and_display();

        A = 1; B = 0;
        $eval();
        output_and_display();

        A = 1; B = 1;
        $eval(); // 触发评估后 Y 应更新为 1
        output_and_display();

        $finish;
    end
    // 自定义任务以输出状态
    task output_and_display();
        begin
            // 测试结果输出
            $display("Time: %0t | A: %b, B: %b, Y: %b", $time, A, B, Y);
        end
    endtask
endmodule
