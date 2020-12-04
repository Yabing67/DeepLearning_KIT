#!/usr/bin/env python 
# -*- coding:utf-8 -*-
"""
@author: Bing
"""

import time as t

class MyTimer():
    def __init__(self):
        self.begin = 0
        self.end = 0
        self.prompt = "未开始计时！"
        self.lasted = []
        self.unit = ['年', '月', '日', '小时', '分钟', '秒']

    def __str__(self):
        return self.prompt

    __repr__ = __str__

    # 开始计时
    def start(self):
        self.begin = t.localtime()
        self.prompt = "提示：请先停止计时"
        print("计时开始...")

    # 停止计时
    def stop(self):
        if self.begin == 0:
            print("提示：请先启动计时器")
        else:
            self.end = t.localtime()
            self.__cal()
            print("计时结束！")

    # 内部方法：计算运行时间
    def __cal(self):
        for i in range(6):
            self.lasted.append(self.end[i] - self.begin[i])
            if self.lasted[i]:
                self.prompt = "共计时了" + str(self.lasted[i]) + self.unit[i]
            # 为下次计时做准备
        self.begin = 0
        self.end = 0

    # 计时器相加
    def __add__(self, other):
        result = []
        for i in range(6):
            result.append(self.lasted[i] + other.lasted[i])
            if result[i]:
                prompt = "共计时了" + str(result[i]) + self.unit[i]
        return prompt




