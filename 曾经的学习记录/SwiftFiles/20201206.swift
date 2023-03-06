//
//  main.swift
//  HelloWorld
//
//  Created by 程文捷 on 2020/12/6.
//

import SwiftUI
// 1 声明字符串变量str
var str: String
// 2 对字符串变量str进行赋值
str = "hello,world"
// 量值打印
print(str)
// 更改str变量的值
str = "new Value"

var type_10 = 17 // 十进制的17
var type_2 = 0b10001 // 二进制的17
var type_8 = 0o21 // 8进制的17
var type_16 = 0x11 // 16进制的17
// 整形数据
var a1 = UInt8.max // 8位无符号整型的最大值 255
var a2 = UInt16.max // 16位无符号整型的最大值
var a3 = UInt32.max
var a4 = UInt64.max
print(a1)
print(a2)
print(a3)
print(a4)

var maxInt8 = Int8.max
var minInt8 = Int8.min
print(maxInt8)
print(minInt8)

// 元组类型
var pen: (name: String, price: Int) = ("钢笔", 2)
// 获得pen变量名称
var name = pen.name
// 获得pen变量价格
var price = pen.price

// 创建元组时也可以不置顶元组中参数的名称，元组会自动为每个参数分配下标，下标值将从0开始一次递增
var car: (String, Int) = ("奔驰", 200_000)
var carName = car.0
var carPrice = car.1
