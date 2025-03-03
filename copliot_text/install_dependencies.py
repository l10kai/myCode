import subprocess
import sys

def install_package(package):
    """安装指定的Python包"""
    print(f"正在安装 {package}...")
    try:
        subprocess.check_call([sys.executable, "-m", "pip", "install", package])
        print(f"{package} 安装成功！")
        return True
    except subprocess.CalledProcessError:
        print(f"安装 {package} 失败，请尝试手动安装: pip install {package}")
        return False

if __name__ == "__main__":
    packages = ["requests", "prettytable"]
    
    print("开始安装必要的依赖包...")
    all_success = True
    
    for package in packages:
        if not install_package(package):
            all_success = False
    
    if all_success:
        print("\n所有依赖已成功安装！现在可以运行 nowcoder_rating_crawler.py 了。")
    else:
        print("\n一些依赖安装失败。请尝试手动安装: pip install prettytable")
