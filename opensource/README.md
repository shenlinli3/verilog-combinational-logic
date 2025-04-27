# verilator 编译
```bash  
# 编译环境安装
sudo apt-get update && sudo apt-get install -y \
    git make autoconf g++ flex bison perl python3 \
    libgoogle-perftools-dev numactl perl-doc \
    libfl2 libfl-dev zlib1g-dev liblz4-tool liblz4-dev \
    libssl-dev uuid-dev \
    help2man

# clone 安装环境
git clone https://github.com/verilator/verilator.git verilator-src

sudo apt-get update
sudo apt-get install -y autoconf automake libtool
autoconf
./configure

# 编译（-j$(nproc) 表示使用全部 CPU 核心，加速编译）
make -j$(nproc)
# (未安装可省略)
sudo apt-get remove -y verilator
# （可选）安装到系统路径（需管理员权限）
sudo make install
# 
verilator --version
# 
```