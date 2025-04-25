# verilog-combinational-logic
# Verilog 组合逻辑电路设计与仿真项目  
## 项目概述  
本项目聚焦于 **Verilog 组合逻辑电路** 的设计与验证，通过实现基础逻辑门（如与门）并搭建仿真环境，帮助学习者掌握以下核心技能：  
- Verilog RTL 建模规范（组合逻辑设计原则）  
- 仿真工具链（Verilator）的完整使用流程  
- 测试平台（Testbench）的设计与调试方法  
- 硬件描述语言（HDL）的调试技巧与波形分析  

**适用人群**：数字电路初学者、FPGA 开发入门者、Verilog 语法实践需求者  


## 目录结构说明  
```  
.  
├── README.md               # 项目文档（你正在阅读）  
└── tests                   # 测试与设计文件  
    ├── common              # 公共逻辑模块（可扩展）  
    │   └── and_gate.sv     # 与门模块（组合逻辑核心）  
    ├── testbench.sv        # 测试平台（包含仿真逻辑）  
    └── waveforms           # 波形文件存储目录（仿真后生成）  
```  

### 文件功能详解  
1. **`common/and_gate.sv`**  
   - **功能**：实现 2 输入与门，组合逻辑无延迟建模  
   - **代码示例**：  
     ```verilog  
     module and_gate #(  
         parameter WIDTH = 1  // 可扩展为多比特输入  
     )(  
         input  logic [WIDTH-1:0] A,  // 输入信号  
         input  logic [WIDTH-1:0] B,  
         output logic [WIDTH-1:0] Y   // 与运算结果  
     );  
         assign Y = A & B;  // 组合逻辑赋值  
     endmodule  
     ```  

2. **`testbench.sv`**  
   - **功能**：生成测试向量，验证 `and_gate` 逻辑正确性  
   - **核心设计**：  
     - 包含输入激励（`initial` 块）  
     - 输出结果打印（自定义任务 `output_and_display`）  
     - 波形转储功能（可扩展）  


## 环境搭建指南  
### 工具链安装  
#### 1. Verilator（仿真核心工具）  
- **作用**：将 Verilog 代码编译为 C++ 可执行文件，支持仿真与调试  
- **安装命令**：  
  ```bash  
  # Ubuntu/Debian 系统  
  sudo apt-get update  
  sudo apt-get install verilator  

  # macOS 系统（通过 Homebrew）  
  brew install verilator  
  ```  
- **版本要求**：Verilator 4.210+  

#### 2. GTKWave（波形查看工具，可选）  
- **作用**：可视化仿真波形，辅助调试  
- **安装命令**：  
  ```bash  
  sudo apt-get install gtkwave  # Linux  
  brew install gtkwave         # macOS  
  ```  

#### 3. 依赖检查  
```bash  
verilator --version  # 验证 Verilator 安装（应输出版本号）  
gtkwave --version    # 可选，验证波形工具  
```  


## 仿真运行全流程  
### 1. 编译与生成可执行文件  
```bash  
# 进入项目根目录  
cd verilator-combinational-logic  

# 执行 Verilator 编译（指定文件路径与搜索目录）  
verilator -Wall -I./tests/common \  # -I 指定模块搜索路径  
          --cc ./tests/common/and_gate.sv \  # 待编译的 RTL 模块  
          --exe ./tests/testbench.sv \        # 测试平台文件  
          --trace  # 可选，启用波形生成（需配合 $dumpvars）  

# 进入生成的 obj_dir 目录  
cd obj_dir  

# 编译可执行文件（基于生成的 Makefile）  
make -f Vtestbench.mk  
```  

### 2. 运行仿真  
```bash  
# 执行仿真程序  
./Vtestbench  

# 预期输出（终端打印）  
Time: 0 | A: 0, B: 0, Y: 0  
Time: 1 | A: 0, B: 1, Y: 0  
Time: 2 | A: 1, B: 0, Y: 0  
Time: 3 | A: 1, B: 1, Y: 1  
```  

### 3. 波形调试（进阶）  
#### 步骤 1：修改测试平台添加波形转储  
在 `testbench.sv` 的 `initial` 块中加入：  
```verilog  
initial begin  
    $dumpfile("./waveforms/waveform.vcd");  // 生成波形文件（自动创建目录）  
    $dumpvars(0, testbench);                 // 转储顶层模块所有信号  
    // 原有测试向量逻辑...  
end  
```  

#### 步骤 2：重新编译并生成波形  
```bash  
make clean  # 清除旧编译产物  
make -f Vtestbench.mk  
./Vtestbench  
```  

#### 步骤 3：用 GTKWave 查看波形  
```bash  
gtkwave ./waveforms/waveform.vcd  
```  

![波形示例](https://i.imgur.com/5bZm5Qp.png)  
*（图示：输入输出信号随时间变化的波形）*  


## 调试与排错技巧  
### 1. 常见错误类型  
| 错误现象                          | 可能原因                          | 解决方法                          |  
|-----------------------------------|-----------------------------------|-----------------------------------|  
| `%Error: Cannot find file`        | 文件路径错误                      | 检查 `-I` 路径与文件路径是否正确 |  
| `%Warning: UNOPTFLAT`             | 组合逻辑反馈回路                  | 检查模块是否存在循环依赖          |  
| 仿真输出异常                      | 测试向量错误或 RTL 逻辑错误       | 打印中间变量，对比真值表          |  

### 2. 高级调试手段  
- **Verilator 调试选项**：  
  ```bash  
  verilator --debug --cc ...  # 启用调试模式，生成调试符号  
  gdb ./Vtestbench            # 使用 GDB 调试仿真程序  
  ```  
- **代码覆盖率分析**：  
  ```bash  
  verilator --coverage --cc ...  
  make -f Vtestbench.mk && ./Vtestbench  
  verilator_coverage --html --dir .  # 生成覆盖率报告  
  ```  


## 项目扩展与学习建议  
### 1. 扩展方向  
#### （1）新增逻辑门模块  
- **目标**：实现或门、异或门、与非门等基础组合逻辑  
- **步骤**：  
  1. 在 `tests/common` 目录下创建新模块（如 `or_gate.sv`）  
  2. 在 `testbench.sv` 中实例化新模块并添加测试向量  
  3. 编写文档记录新模块功能  

#### （2）参数化设计  
- **目标**：使 `and_gate` 支持多比特输入（如 8 位与门）  
- **修改点**：  
  ```verilog  
  // and_gate.sv 新增参数声明  
  module and_gate #(parameter WIDTH = 8)(...);  
  // testbench.sv 实例化时指定参数  
  and_gate #(.WIDTH(8)) uut(...);  
  ```  

#### （3）自动化测试  
- **目标**：生成随机测试向量，提升覆盖率  
- **实现方法**：  
  ```verilog  
  initial begin  
      for (int i=0; i<100; i++) begin  
          A = $random;  // 生成随机输入  
          B = $random;  
          #1;  // 等待仿真时间推进  
      end  
  end  
  ```  

### 2. 学习资源推荐  
- **书籍**：  
  - 《Verilog 数字系统设计教程》（夏宇闻）  
  - 《计算机组成与设计：硬件/软件接口》（ Patterson & Hennessy）  
- **在线课程**：  
  - Coursera 《Digital Circuits and Systems》  
  - 网易云课堂 《FPGA 开发入门与 Verilog 编程》  
- **社区**：  
  - [Verilator 官方文档](https:// verilator.org/)  
  - [EDA Playground](https://www.edaplayground.com/)（在线仿真平台）  


## 贡献与反馈  
### 1. 代码贡献流程  
1.  Fork 本仓库到个人账号  
2. 创建新分支（如 `feature/or_gate`）  
3. 提交代码修改并添加测试用例  
4. 发起 Pull Request（PR）并描述变更内容  

### 2. 问题反馈  
- 提交 Issues 时请包含：  
  - 错误日志截图或文本  
  - 仿真命令与文件路径  
  - 预期结果与实际结果对比  


## 许可证  
本项目采用 **MIT 许可证**，允许自由修改和分发，详见 `LICENSE` 文件（可自行添加）。  


## 联系与支持  
- **作者**：shenlin li
- **邮箱**：shenlinli3@163.com
- **项目地址**：https://github.com/shenlinli3/verilog-combinational-logic/


通过以上内容，学习者可清晰了解项目结构、仿真流程及扩展方向，同时掌握组合逻辑设计的核心调试技巧。建议按照 **基础仿真 → 波形分析 → 代码扩展 → 自动化测试** 的路径逐步深入学习。