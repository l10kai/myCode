import requests
import json
import sys
import time
import random
import re
from getpass import getpass
import logging

# 配置日志
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s',
    handlers=[
        logging.FileHandler("nowcoder_crawler.log"),
        logging.StreamHandler()
    ]
)

class NowcoderCrawler:
    def __init__(self):
        self.session = requests.Session()
        self.headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
            'Referer': 'https://ac.nowcoder.com/',
            'Accept': 'application/json, text/javascript, */*; q=0.01',
            'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8',
            'Connection': 'keep-alive'
        }
        self.is_logged_in = False
        
    def login(self, username, password):
        """登录牛客网"""
        login_url = "https://www.nowcoder.com/login"
        
        # 先获取登录页面，获取必要的cookies
        self.session.get(login_url, headers=self.headers)
        
        # 构建登录数据
        login_data = {
            'email': username,
            'password': password,
            'remember': 'true'
        }
        
        # 获取登录API地址
        login_api_url = "https://www.nowcoder.com/login/login"
        
        try:
            response = self.session.post(
                login_api_url, 
                data=login_data,
                headers={**self.headers, 'Content-Type': 'application/x-www-form-urlencoded'}
            )
            response.raise_for_status()
            
            data = response.json()
            if data.get('code') == 0:
                logging.info("登录成功")
                self.is_logged_in = True
                return True
            else:
                logging.error(f"登录失败: {data.get('message')}")
                return False
                
        except Exception as e:
            logging.error(f"登录异常: {e}")
            return False
    
    def get_user_info(self, uid):
        """获取用户基本信息"""
        url = f"https://ac.nowcoder.com/acm/contest/profile-basic-info?uid={uid}"
        
        # 添加随机延迟
        self._random_delay()
        
        try:
            response = self.session.get(url, headers=self.headers)
            response.raise_for_status()
            
            # 打印原始响应内容用于调试
            logging.info(f"用户信息响应状态码: {response.status_code}")
            
            # 检查是否返回了HTML页面而不是JSON
            if "<!DOCTYPE html>" in response.text:
                logging.warning("收到HTML响应而非JSON，可能需要登录")
                if not self.is_logged_in:
                    logging.info("尝试登录...")
                    return None
            
            try:
                data = response.json()
                
                if data['code'] != 0:
                    logging.error(f"错误: {data['msg']}")
                    return None
                    
                return data['data']
            except json.JSONDecodeError:
                logging.error("解析响应数据失败，原始响应内容:")
                logging.error(response.text[:200] + "..." if len(response.text) > 200 else response.text)
                return None
                
        except requests.exceptions.RequestException as e:
            logging.error(f"请求错误: {e}")
            return None

    def get_user_rating(self, uid):
        """获取用户rating历史"""
        url = f"https://ac.nowcoder.com/acm/contest/rating-index-data?uid={uid}"
        
        # 添加随机延迟
        self._random_delay()
        
        try:
            response = self.session.get(url, headers=self.headers)
            response.raise_for_status()
            
            logging.info(f"Rating历史响应状态码: {response.status_code}")
            
            # 检查是否返回了HTML页面而不是JSON
            if "<!DOCTYPE html>" in response.text:
                logging.warning("收到HTML响应而非JSON，可能需要登录")
                if not self.is_logged_in:
                    logging.info("尝试登录...")
                    return None
                    
            try:
                data = response.json()
                
                if data['code'] != 0:
                    logging.error(f"错误: {data['msg']}")
                    return None
                    
                return data['data']['ratingDataList']
            except json.JSONDecodeError:
                logging.error("解析响应数据失败，原始响应内容:")
                logging.error(response.text[:200] + "..." if len(response.text) > 200 else response.text)
                return None
                
        except requests.exceptions.RequestException as e:
            logging.error(f"请求错误: {e}")
            return None
    
    def _random_delay(self):
        """添加随机延迟，避免请求过快"""
        delay = random.uniform(1, 3)
        time.sleep(delay)


def display_user_info(user_info):
    """显示用户基本信息"""
    if not user_info:
        return
        
    print("\n用户信息:")
    print(f"用户名: {user_info['userName']}")
    print(f"当前Rating: {user_info['rating']}")
    print(f"排名: {user_info['ranking']}")
    print(f"段位: {user_info['levelName']}")

def display_rating_history(rating_history):
    """显示用户rating历史，不使用prettytable"""
    if not rating_history:
        return
        
    print("\nRating历史:")
    # 确定每列最大宽度
    headers = ["日期", "比赛名称", "Rank", "Rating变化", "Rating"]
    data = []
    
    for item in rating_history:
        date = time.strftime("%Y-%m-%d", time.localtime(item['createTime']/1000))
        rating_change = f"{'+' if item['ratingChange'] > 0 else ''}{item['ratingChange']}"
        data.append([date, item['contestName'], str(item['rank']), rating_change, str(item['rating'])])
    
    # 计算每列的最大宽度
    col_widths = [max(len(h), max(len(row[i]) for row in data)) for i, h in enumerate(headers)]
    
    # 打印表头
    header_row = ' | '.join(h.ljust(col_widths[i]) for i, h in enumerate(headers))
    print(header_row)
    print('-' * len(header_row))
    
    # 打印数据行
    for row in data:
        formatted_row = ' | '.join(str(cell).ljust(col_widths[i]) for i, cell in enumerate(row))
        print(formatted_row)

def main():
    if len(sys.argv) > 1:
        uid = sys.argv[1]
    else:
        uid = input("请输入牛客网用户ID: ")
    
    print(f"正在获取用户 {uid} 的Rating信息...")
    
    crawler = NowcoderCrawler()
    
    user_info = crawler.get_user_info(uid)
    
    # 如果首次请求失败，尝试登录
    if not user_info:
        print("获取信息失败，可能需要登录。")
        username = input("请输入牛客网账号: ")
        password = getpass("请输入密码: ")
        
        if crawler.login(username, password):
            # 登录成功后再次尝试获取数据
            user_info = crawler.get_user_info(uid)
            rating_history = crawler.get_user_rating(uid)
        else:
            print("登录失败，无法获取数据")
            return
    else:
        rating_history = crawler.get_user_rating(uid)
    
    if user_info:
        display_user_info(user_info)
    else:
        print("获取用户信息失败")
    
    if rating_history:
        display_rating_history(rating_history)
    else:
        print("获取Rating历史失败")

if __name__ == "__main__":
    main()
